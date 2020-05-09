#pragma once

#include <string>
#include <iostream>

class Sales_data {
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
public:
	inline std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data& rhs);
private:
	std::string bookNo;
	double revenue = 0.0;
	unsigned units_sold = 0;
};

std::ostream& operator<<(std::ostream& os, const Sales_data& item);
std::istream& operator>>(std::istream& is, Sales_data& item);
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);