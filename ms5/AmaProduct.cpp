#include "AmaProduct.h"
#include <cstring>
#include <iomanip>

using namespace std;

namespace sict
{
	AmaProduct::AmaProduct(char tag) {
		fileTag_ = tag;
	}

	const char * AmaProduct::unit() const {
		return unit_;
	}

	void AmaProduct::unit(const char * value) {
		strcpy(unit_, value);
	}

	fstream & AmaProduct::store(fstream & file, bool addNewLine) const {
		file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << unit_ << "," << qtyNeeded();

		if (addNewLine)
			file << endl;

		return file;
	}

	fstream & AmaProduct::load(fstream & file) {

		char sku_[MAX_SKU_LEN], name_[500];
		int taxed_, quantity_, qtyNeeded_;
		double price_;

		file.getline(sku_, MAX_SKU_LEN, ',');
		file.getline(name_, 500, ',');
		file >> price_;
		file.ignore(500, ',');
		file >> taxed_;
		file.ignore(500, ',');
		file >> quantity_;
		file.ignore(500, ',');
		file.getline(unit_, 1000, ',');
		file >> qtyNeeded_;
		file.ignore(500, ',');

		sku(sku_);
		name(name_);
		price(price_);
		if (taxed_ == 1)
			taxed(true);
		else
			taxed(false);
		quantity(quantity_);
		qtyNeeded(qtyNeeded_);

		return file;
	}

	ostream & AmaProduct::write(ostream & os, bool linear) const {
		if (!err_.isClear())
			os << err_.message();
		else {
			if (linear) {
				os << setfill(' ') << left << setw(MAX_SKU_LEN) << sku() << '|'
					<< left << setw(20) << name() << '|'
					<< right << fixed << setw(7) << setprecision(2) << cost() << '|'
					<< right << setw(4) << quantity() << '|'
					<< left << setw(10) << unit_ << '|'
					<< right << setw(4) << qtyNeeded() << '|';
			}
			else {
				os << "Sku: " << sku() << endl
					<< "Name: " << name() << endl
					<< "Price: " << price() << endl
					<< "Price after tax: ";
				taxed() ? os << cost() : os << "N/A";
				os << endl
					<< "Quantity On Hand: " << quantity() << " " << unit_ << endl
					<< "Quantity Needed: " << qtyNeeded();
			}
		}
		return os;
	}

	istream & AmaProduct::read(istream & istr) {
		char rSku[MAX_SKU_LEN], rName[500], rTaxed;
		int rQuantity, rQtyNeeded;
		double rPrice;

		cout << "Sku: ";
		istr >> rSku;
		istr.ignore(500, '\n');

		cout << "Name: ";
		istr >> rName;
		istr.ignore(500, '\n');

		cout << "Unit: ";
		istr >> unit_;
		istr.ignore(500, '\n');

		cout << "Taxed? (y/n): ";
		istr >> rTaxed;

		if (rTaxed == 'Y' || rTaxed == 'y' || rTaxed == 'n' || rTaxed == 'N') {
			err_.clear();

			cout << "Price: ";
			istr >> rPrice;
			istr.ignore(500, '\n');

			if (!istr.fail() && !istr.bad()) {
				istr.clear();
				err_.clear();

				cout << "Quantity On hand: ";
				istr >> rQuantity;
				istr.ignore(500, '\n');

				if (!istr.fail() && !istr.bad()) {
					istr.clear();
					err_.clear();

					cout << "Quantity Needed: ";
					istr >> rQtyNeeded;

					if (istr.fail() || istr.bad()) {
						err_ = "Invalid Quantity Needed Entry";
						istr.setstate(ios::failbit);
					}
				}
				else {
					err_ = "Invalid Quantity Entry";
					istr.setstate(ios::failbit);
				}
			}
			else {
				err_ = "Invalid Price Entry";
				istr.setstate(ios::failbit);
			}
		}
		else {
			err_ = "Only (Y)es or (N)o are acceptable";
			istr.setstate(ios::failbit);
		}

		if (!istr.fail() && !istr.bad()) {
			sku(rSku);
			name(rName);
			tolower(rTaxed) == 'y' ? taxed(true) : taxed(false);
			price(rPrice);
			quantity(rQuantity);
			qtyNeeded(rQtyNeeded);
		}

		return istr;
	}
}