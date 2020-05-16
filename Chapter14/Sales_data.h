#pragma once

#include <string>
#include <iostream>

class Sales_data {
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const std::string& s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(const std::string& s): bookNo(s) { }
	inline std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data& rhs);
private:
	double avg_price() const {
		return units_sold ? revenue / units_sold : 0;
	}
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::ostream& operator<<(std::ostream& os, const Sales_data& item);
std::istream& operator>>(std::istream& is, Sales_data& item);
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);