// Chapter14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Sales_data.h"

using namespace std;

int main() {
	Sales_data item1, item2;
	// 입력을 읽어 item1과 item2에 넣는 코드
	double price = 0;
	cin >> item1 >> item2;

	if (item1.bookNo == item2.bookNo) {
		unsigned totalCnt = item1.units_sold + item2.units_sold;
		double totalRevenue = item1.revenue + item2.revenue;
		cout << item1.bookNo << " " << totalCnt
			<< " " << totalRevenue << " ";
		if (totalCnt != 0)
			cout << totalRevenue / totalCnt << endl;
		else
			cout << "(no sales)" << endl;
	} else {
		cerr << "Data must refer to the same ISBN"
			<< endl;
		return -1;
	}
	cin >> price;
	return 0;
}