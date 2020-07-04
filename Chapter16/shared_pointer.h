#pragma once

template <typename T>
class shared_pointer{
public:
	shared_pointer() : refCnt(nullptr), p(nullptr), del(nullptr) { }
	explicit shared_pointer(T *p, void (*d) = nullptr) : refCnt(new size_t(1)), p(p), del(d) { }
	shared_pointer(const shared_pointer& p2, void(*d) = nullptr) : refCnt(p2.refCnt), p(p2.p), del(d ? d : p2.del) {
		(*refCnt)++;
	}
	~shared_pointer() { decreaseRef(); }
	shared_pointer* operator=(const shared_pointer& rhs);
	size_t use_count() { return *refCnt; }
	bool unique() { return use_count() == 1; }
	explicit operator bool() const { return p; }
	T& operator*() const {
		// T& 를 반환하므로 외부에서 *p 의 값을 변경할 수 있다.
		// 그럼에도 불구하고 const 함수인 이유는
		// *p (포인터가 가르키고 있는 것)의 값이 변경되는 것이지
		// &p (포인터가 가르키는 주소)는 변함이 없기 때문이다.
		// 따라서 shared_pointer는 변함이 없다.
		return *p;
	}
	T* operator->() const {
		return &this->operator*();
	}
	void reset(T* p = nullptr, void (*d) = nullptr);
	T* get() { return p; }
private:
	size_t *refCnt;
	T *p;
	void (*del);
	void decreaseRef();
};

template <typename T>
void shared_pointer<T>::reset(T* p, void(*d)) {
	decreaseRef();
	this->p = p;
	del = d;
}

template <typename T>
shared_pointer<T>* shared_pointer<T>::operator=(const shared_pointer& rhs) {
	reset();
	refCnt = rhs.refCnt;
	(*refCnt)++;
	p = rhs.p;
	del = rhs.del;
}

template <typename T>
void shared_pointer<T>::decreaseRef() {
	if (refCnt) {
		(*refCnt)--;
		if (*refCnt == 0)
			del ? del(this->p) : delete this->p;
	}
}