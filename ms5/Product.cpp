#include "Product.h"
#include "general.h"
#include <cstring>

using namespace std;

namespace sict {
	Product::Product() {
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		taxed_ = true;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(const char* sku, const char* name, double price, bool taxed, int quantity, int qtyNeeded){
		strncpy(sku_, sku, MAX_SKU_LEN);

		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);

		quantity_ = 0;
		taxed_ = taxed;
		price_ = price;
		qtyNeeded_ = qtyNeeded;
	}

	Product::Product(const Product& p){
		strncpy(sku_, p.sku_, MAX_SKU_LEN);

		name_ = nullptr;
		name_ = new char[strlen(p.name_) + 1];
		strcpy(name_, p.name_);

		taxed_ = p.taxed_;
		price_ = p.price_;
		quantity_ = p.quantity_;
		qtyNeeded_ = p.qtyNeeded_;
	}

	Product & Product::operator=(const Product & p){
		strncpy(sku_, p.sku_, MAX_SKU_LEN);

		name_ = new char[strlen(p.name_) + 1];
		strcpy(name_, p.name_);

		taxed_ = p.taxed_;
		price_ = p.price_;
		quantity_ = p.quantity_;
		qtyNeeded_ = p.qtyNeeded_;

		return *this;
	}

	Product::~Product(){
		delete[] name_;
		name_ = nullptr;
	}

	void Product::sku(const char* sku) {
		strncpy(sku_, sku, MAX_SKU_LEN);
	}

	void Product::name(const char* name) {
		delete[] name_;
		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
	}

	void Product::price(double price) {
		price_ = price;
	}

	void Product::taxed(bool taxed) {
		taxed_ = taxed;
	}

	void Product::quantity(int quantity) {
		quantity_ = quantity;
	}

	void Product::qtyNeeded(int qtyNeeded) {
		qtyNeeded_ = qtyNeeded;
	}

	const char* Product::sku() const{
		char* sku;
		sku = new char[strlen(sku_) + 1];
		strcpy(sku, sku_);
		return sku;

	}

	const char * Product::name() const{
		return name_;
	}

	double Product::price() const{
		return price_;
	}

	bool Product::taxed() const{
		return taxed_;
	}

	int Product::quantity() const{
		return quantity_;
	}

	int Product::qtyNeeded() const{
		return qtyNeeded_;
	}

	double Product::cost() const{
		return taxed_ ? price_ * (1 + TAX) : price_;
	}

	bool Product::isEmpty() const{
		return sku_[0] == '\0';
	}

	bool Product::operator==(const char* compare){
		return !strcmp(sku_, compare);
	}

	int Product::operator+=(int number){
		return quantity_ += number;
	}

	int Product::operator-=(int num){
		return quantity_ -= num;
	}

	
	double operator+=(double & a, const Product & p){
		return a += p.cost() * p.quantity();
	}

	std::istream & operator>>(std::istream & is, Product & p){
		return p.read(is);
	}

	std::ostream & operator<<(std::ostream & os, const Product & p){
		return p.write(os, true);
	}
}
