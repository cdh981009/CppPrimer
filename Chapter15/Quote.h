#pragma once
#include <string>
#include <iostream>
#include <utility>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) :
		bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const {
		return n * price;
	}
	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone()&& { return new Quote(std::move(*this)); }
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(std::ostream& os, const Quote& item, size_t n);