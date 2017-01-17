#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
namespace sict {
	class Account {
		char name_[41];
		double balance_;
	public:
		Account();
		Account(double balance);
		Account(const char name[], double balance = 0.0);
		void display(bool gotoNewline = true)const;
		Account& operator=(const char*);
		Account& operator+=(const Account&);
		Account& add(const Account&, const Account&);
		double values(const Account&);
	};
	
	Account operator+(const Account&, const Account&);
	double operator+=(double&, const Account&);
	std::ostream & operator<<(std::ostream& display, const Account&);
};

#endif