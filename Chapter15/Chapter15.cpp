// Chapter15.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_Quote.h"
#include "Basket.h"

using namespace std;

int main() {
	/*
	Basket bsk;
	
	// 포인터를 숨기기 위해 만들었는데, 사용자가 포인터를 사용해야하는 모순 발생
	//bsk.add_item(make_shared<Quote>("123", 45));
	//bsk.add_item(make_shared<Bulk_quote>("345", 10, 3, .5));
	//bsk.add_item(make_shared<Bulk_quote>("345", 10, 3, .5));
	//bsk.add_item(make_shared<Bulk_quote>("345", 10, 3, .5));
	
	bsk.add_item(Quote("123", 45));
	bsk.add_item(Bulk_quote("345", 10, 3, .5));
	bsk.add_item(Bulk_quote("345", 10, 3, .5));
	bsk.add_item(Bulk_quote("345", 10, 3, .5));

	bsk.total_receipt(cout);
	*/
	return 0;
}
