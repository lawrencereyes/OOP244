#include "AidApp.h"
#include "Product.h"
#include "AmaPerishable.h"
#include "AmaProduct.h"

#include <iomanip>
#include <iostream>

using namespace std;

namespace sict {
	int AidApp::run(){
		char nSku[MAX_SKU_LEN];
		Product* p;

		while (menu() != 0) {
			if (menu() == 1) {
				listProducts();
				pause();
			}
			else if (menu() == 2) {
				cout << "Please enter the SKU: ";
				cin >> nSku;

				if (SearchProducts(nSku) != -1) {
					product_[SearchProducts(nSku)]->write(cout, false);
				}
				else {
					cout << "Not found!" << endl;
				}

				pause();
			}
			else if (menu() == 3) {
				addProduct(false);
				loadRecs();
				pause();
			}
			else if (menu() == 4) {
				addProduct(true);
				loadRecs();
				pause();
			}
			else if (menu() == 5) {
				cout << "Please enter the SKU: ";
				cin >> nSku;

				addQty(nSku);
				pause();
			}
			else if (menu() == 0) {
				cout << "Goodbye!!" << endl;
				pause();
			}
			else {
				cout << "===Invalid Selection, try again.===" << endl;
				pause();
			}
		}
		return 0;
	}

	AidApp::AidApp(const char * filename){
		strcpy(filename_, filename);

		for (int i = 0; i < MAX_NO_RECS; i++)
			product_[i] = nullptr;

		noOfProducts_ = 0;
	
		loadRecs();
	}

	void AidApp::pause() const{
		cout << "Press Enter to continue...";
		cin.ignore(1000, '\n');
	}

	int AidApp::menu(){
		int choice;

		cout << "Disaster Aid Supply Management Program" << endl
			<< "1- List products" << endl
			<< "2- Display product" << endl
			<< "3- Add non-perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to quantity of purchased products" << endl
			<< "0- Exit program" << endl
			<< "> ";
		cin >> choice;

		if(choice >= 0 && choice < 6)
			return choice;
		
		cin.clear();
	}

	void AidApp::loadRecs(){
		int readIndex = 0;
		char isP;

		datafile_.open(filename_);

		if (datafile_.fail()) {
			datafile_.open(filename_, ios::in);
			datafile_.close();
			datafile_.open(filename_, ios::out);
			datafile_.close();
		}
		else {
			while (datafile_.eof()) {
				delete[readIndex] product_;

				datafile_ >> isP;
				cin.ignore(1, ',');

				if (isP == 'P'){
					product_[readIndex] = new AmaPerishable;
					product_[readIndex]->load(datafile_);
				}
				else if(isP == 'N'){
					product_[readIndex] = new AmaProduct;
					product_[readIndex]->load(datafile_);
				}
				else if(!isP){
					product_[readIndex]->load(datafile_);
					readIndex++;
				}
			}
			noOfProducts_ = readIndex;
			datafile_.close();
		}
	}

	void AidApp::saveRecs(){
		datafile_.open(filename_);

		for (int i = 0; i < noOfProducts_; i++) {
			datafile_ << product_[i];
		}

		datafile_.close();
	}

	void AidApp::listProducts() const{
		double cost;

		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Nedd| Expiry   " << endl
			<< "-----|--------|--------------------|-------|----|----------|----|----------" << endl;

		for (int i = 0; i < noOfProducts_; i++) {
			cout << right << setw(4) << setfill(' ') << i + 1 << " | ";
			product_[i]->write(cout, true);

			if (i == 10)
				pause();
			
			cost += *product_[i];
		}

		cout << "---------------------------------------------------------------------------" << endl;

		cout << "$" << cost;
	}

	int AidApp::SearchProducts(const char * sku) const{
		for (int i = 0; i < noOfProducts_; i++) {
			if (*product_[i] == sku)
				return i;
			else
				return -1;
		}
	}

	void AidApp::addQty(const char * sku){
		int check = SearchProducts(sku);
		int pItems;

		for (int i = 0; i < noOfProducts_; i++){
			if (check == -1)
				cout << "Not found!" << endl;
			else {
				product_[i]->write(cout, false);

				cout << "Please enter the number of purchased items: ";
				cin >> pItems;

				if (pItems) {
					if (pItems <= (product_[i]->qtyNeeded() - product_[i]->quantity())) {
						product_[i] += pItems;
					}
					else {
						cout << "Too many items; only " << product_[i]->qtyNeeded() << " is needed, please return the extra " << (pItems - (product_[i]->qtyNeeded() - product_[i]->quantity())) << " items." << endl;
					}
				}
				else {
					cout << "Invalid quantity value!" << endl;
				}
			}

			datafile_ << product_[i];
			cout << "Updated!" << endl;
			cin.clear();
		}
	}

	void AidApp::addProduct(bool isPerishable){
		Product* p;

		if (isPerishable) {
			p = new AmaPerishable;
		}
		else {
			p = new AmaProduct;
		}

		istream& read = p->read(cin);

		if (read.fail() || read.bad())
			p->write(cout, false);
		else {
			noOfProducts_++;
			product_[noOfProducts_] = p;

			saveRecs();
		}
	}


}