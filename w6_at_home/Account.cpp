#include <iomanip>
#include <string.h>
#include "Account.h"
using namespace std;
namespace sict {
	Account::Account() {
		name_[0] = 0;
		balance_ = 0;
	}
	Account::Account(double balance) {
		name_[0] = 0;
		balance_ = balance;
	}
	Account::Account(const char name[], double balance) {
		strncpy(name_, name, 40);
		name_[40] = 0;
		balance_ = balance;
	}

	void Account::display(bool gotoNewline)const {
		cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
		if (gotoNewline) cout << endl;
	}

	Account& Account::operator=(const char* name) {
		strncpy(name_, name, 40);
		name_[40] = 0;
		return *this;
	}

	Account & Account::operator+=(const Account & acc){
		balance_ += acc.balance_;
		return *this;
	}

	Account& Account::add(const Account& B, const Account& C){
		balance_ = B.balance_ + C.balance_;
		return *this;
	}

	double Account::values(const Account& value) {
		return value.balance_;
	}

	Account operator+(const Account& B, const Account& C){
		Account sum, A;

		sum += A.add(B, C);
		return sum;
	}

	double operator+=(double& num, const Account& acc){
		Account temp;
		num += temp.values(acc);
		return num;
	}

	std::ostream & operator<<(std::ostream & dsp, const Account& acc) {
		acc.display(false);
		return dsp;
	}
}