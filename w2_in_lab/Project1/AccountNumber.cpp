#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
	// member functions' (methods') definition go here
	void AccountNumber::name(const char name[]) {
		strncpy(_name, name, MAX_NAME_LENGTH);
		_name[MAX_NAME_LENGTH] = 0;
	}

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;

		if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE) {
			if (branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE) {
				if (accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO) {
					_validAccNumber = true;
				}
			}
		}else
			_validAccNumber = false;
	}

	void AccountNumber::display() {
		if (isValid() == true) {
			cout << "Name: " << _name << ", Accountnumber: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
		}
		else if (isValid() == false) {
			cout << _name << " does not have a valid account number." << endl;
		}
	}

	bool AccountNumber::isValid() {
		return _validAccNumber;
	}
}