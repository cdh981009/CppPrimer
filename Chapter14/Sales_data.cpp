#include <iostream>
#include <string>

#include "Sales_data.h"

using namespace std;

ostream& operator<<(ostream& os, const Sales_data& item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
	return os;
}

istream& operator>>(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}
