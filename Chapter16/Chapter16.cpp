#include <iostream>

#include "Util.h"
#include "shared_pointer.h"

using namespace std;

int main() {
	shared_pointer<int> p1(new int(32));
	cout << *p1 << endl;
	cout << p1.unique() << " " << p1.use_count() << endl;
	{
		auto p2 = p1;
		cout << p1.unique() << p1.use_count() << " " << p2.use_count() << endl;
	}
}
