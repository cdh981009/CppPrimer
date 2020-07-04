#include <iostream>

#include "Util.h"
#include "shared_pointer.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {
	{
		shared_pointer<int> p1(new int(32), [](int* p) {
			cout << "deleting pointer containing integer: " << *p << endl;
			delete p;
							   });
		cout << *p1 << endl;
		cout << p1.unique() << " " << p1.use_count() << endl;
		{
			auto p2 = p1;
			cout << p1.unique() << " " << p1.use_count() << " " << p2.use_count() << endl;
			{
				auto p3 = p2;
				*p3 = 11;
				cout << p1.unique() << " " << p1.use_count() << " " << p2.use_count() << endl;
				cout << *p1 << " " << p1.use_count() << " " << p2.use_count() << endl;
				
			}
			cout << p1.unique() << " " << p1.use_count() << " " << p2.use_count() << endl;
		}
		cout << p1.unique() << " " << p1.use_count() << endl;
	}
	_CrtDumpMemoryLeaks();
}
