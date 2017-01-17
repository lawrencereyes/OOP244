#include <cstring>
#include <iostream>
#include <iomanip>
#include "Contact.h"
using namespace std;

namespace sict {

	Contact::Contact() {
		setEmpty();
	}

	Contact::Contact(const char* name, int noPN) {
		phoneNumber_ = new PhoneNumber[noPN];
		strncpy(name_, name, 41);
		name_[40] = '\0';
		_noPN = noPN;
	}

	Contact::Contact(const Contact & other){
		strcpy(name_, other.name_);
		_noPN = other._noPN;
		phoneNumber_ = new PhoneNumber[_noPN];

		for(int i = 0; i < _noPN; i++) {
			phoneNumber_[i] = other.phoneNumber_[i];
		}
	}

	Contact & Contact::operator=(const Contact & C){
		delete[] phoneNumber_;
		strcpy(name_, C.name_);
		_noPN = C._noPN;
		phoneNumber_ = new PhoneNumber[_noPN];

		for(int i = 0; i < _noPN; i++) {
			phoneNumber_[i] = C.phoneNumber_[i];
		}

		return *this;
	}

	

	Contact::~Contact() {
		delete[] phoneNumber_;
	}

	void Contact::display()const {
		//display the name and go to new line
		cout << name_ << endl;

		// loop through elements of phoneNumber_ up to _noPN and display them one by one
		for (int i = 0; i < _noPN; i++) {
			phoneNumber_[i].display();
		}

		// draw a 40 char line using '-' and go to new line
		for (int i = 0; i < 40; i++) {
			cout << "-";
		}
		cout << endl;

	}

	void Contact::read() {
		cout << "Contact Name: ";
		cin.getline(name_, 41, '\n');
		cout << "Please enter " << _noPN << " phone numbers: " << endl;
		for (int i = 0; i < _noPN; i++) {
			cout << i + 1 << ": ";
			phoneNumber_[i].read();
		}
	}

	bool Contact::isEmpty()const {
		return phoneNumber_ == nullptr;
	}

	void Contact::setEmpty() {
		name_[0] = 0;
		_noPN = 0;
		phoneNumber_ = nullptr;// same as phoneNumber_ = (PhoneNumber*)0;
	}
}