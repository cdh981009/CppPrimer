#pragma once

#include <string>
#include <iostream>

class Sales_data {
public:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

ostream& operator<<(ostream& os, const Sales_data& item);
istream& operator>>(istream& is, Sales_data& item);