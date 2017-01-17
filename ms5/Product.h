#ifndef SICT__Product_H_
#define SICT__Product_H_

#include <iostream>
#include "general.h"
#include "Streamable.h"

namespace sict {
	class Product : public Streamable {
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		Product();
		Product(const char* sku, const char* name, double price = 0, bool taxed = true, int quantity = 0, int qtyNeeded = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();

		void sku(const char*);
		void name(const char*);
		void price(double);
		void taxed(bool);
		void quantity(int);
		void qtyNeeded(int);

		const char* sku() const;
		const char* name() const;
		double price() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool isEmpty() const;

		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);
	};

	double operator+=(double&, const Product&);
	std::istream& operator>>(std::istream& is, Product& p);
	std::ostream& operator<<(std::ostream& os, const Product&);
}
#endif