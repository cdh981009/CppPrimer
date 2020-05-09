// Chapter14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdexcept>

#include "Sales_data.h"

using namespace std;

int main() {
	Sales_data item1, item2;
	while (cin >> item1 >> item2) {
		try {
			if (item1.isbn() == item2.isbn()) {
				cout << item1 + item2 << endl;
			} else {
				throw runtime_error("Data must refer to same ISBN");
			}
		} catch (runtime_error err) {
			cout << err.what()
				<< "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}
	return 0;
}