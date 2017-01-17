#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
	char name[41];
	int bankCode, branchCode, accNumber;

	void AccountNumber::name(const char name[]) {
		strcpy(_name, name);
	}

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accNumber) {
		//check bankCode, branchCode and accNumber entered by user
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accNumber;

		if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE) {
			if (branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE) {
				if (accNumber >= MIN_ACCNO && accNumber <= MAX_ACCNO) {
					_validAccNumber = true;
				}
			}
		}
		else
			_validAccNumber = false;
	}

	void AccountNumber::displayName() const {
		cout << "Name: " << _name;
	}

	void AccountNumber::displayNumber() const {
		cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber;
	}

	void AccountNumber::display() const {
		if (isValid() == true) {
			displayName();
			cout << ", ";
			displayNumber();
			cout << endl;
		}
		else if (isValid() == false) {
			cout << _name << " does not have a valid account number." << endl;
		}
	}

	void AccountNumber::display(bool display_name) const {
		if (isValid() == true) {
			if (display_name == true) {
				displayName();
				cout << endl;
			}
			else if (display_name == false) {
				displayNumber();
				cout << endl;
			}
		}
		else if (isValid() == false) {
			cout << _name << " does not have a valid account number." << endl;
		}
	}

	void AccountNumber::display(bool display_name, bool display_number) const {
		if (isValid() == true) {
			if (display_name == true && display_number == true) {
				displayName();
				cout << ", ";
				displayNumber();
				cout << endl;
			}
			else if (display_name == true && display_number == false) {
				displayName();
				cout << endl;
			}
			else if (display_name == false && display_number == true) {
				displayNumber();
				cout << endl;
			}
			else if (display_name == false && display_number == false) {
			
			}
		}
		else if (isValid() == false) {
			cout << _name << " does not have a valid account number." << endl;
		}
	}

	bool AccountNumber::isValid() const {
		return _validAccNumber;
	}
}

