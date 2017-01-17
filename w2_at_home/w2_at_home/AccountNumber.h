#ifndef SICT_ACCNUMBER_H_
#define SICT_ACCNUMBER_H_

	// #define statements go here
#define MAX_NAME_LENGTH   40
#define MIN_BANKCODE    100
#define MAX_BANKCODE   999
#define MIN_BRANCHCODE    1
#define MAX_BRANCHCODE   220
#define MIN_ACCNO    10000
#define MAX_ACCNO    99999

namespace sict {
	// class declration goes here
	class AccountNumber {
		char _name[MAX_NAME_LENGTH + 1];
		int _bankCode, _branchCode, _accountNumber;
		bool _validAccNumber, display_name, display_number;

		void displayName() const;
		void displayNumber() const;

	public:
		void name(const char name[]);
		void accountNumber(int _bankCode, int _branchCode, int _accountNumber);
		void display() const;
		void display(bool) const;
		void display(bool, bool) const;
		bool isValid() const;
	};
}
#endif