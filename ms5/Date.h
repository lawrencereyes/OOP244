#ifndef SICT_DATE_H__
#define SICT_DATE_H__

#include <iostream>
using namespace std; 

namespace sict {

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

	class Date {
	private:
		int year_, mon_, day_, readErrorCode_;
		int value()const;
		void errCode(int);
	public:
		Date();
		Date(int, int, int);
		bool operator ==(const Date& D)const;
		bool operator !=(const Date& D)const;
		bool operator <(const Date& D)const;
		bool operator >(const Date& D)const;
		bool operator <=(const Date& D)const;
		bool operator >=(const Date& D)const;
		int mdays()const;
		int errCode()const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::istream& operator>>(std::istream& input, Date&);
	std::ostream& operator<<(std::ostream& output, const Date&);
}
#endif
