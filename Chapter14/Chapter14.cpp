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
				unsigned totalCnt = item1.units_sold + item2.units_sold;
				double totalRevenue = item1.revenue + item2.revenue;
				cout << item1.isbn() << " " << totalCnt
					<< " " << totalRevenue << " ";
				if (totalCnt != 0)
					cout << totalRevenue / totalCnt << endl;
				else
					cout << "(no sales)" << endl;
			} else {
				cerr << "Data must refer to the same ISBN"
					<< endl;
			}
		} catch (runtime_error err) {
			cout << err.what()
				<< "\nTry Again? Enter y or n" << endl;
		}
	}
	return 0;
}