#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "general.h"
namespace sict {
	int Date::value()const {
		return year_ * 372 + mon_ * 31 + day_;
	}

	void Date::errCode(int errorCode) {//do not know why is presenting an error
		readErrorCode_ = errorCode;
	}

	Date::Date(){
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}

	Date::Date(int year, int mon, int day) {
		year_ = year;
		mon_ = mon;
		day_ = day;
		readErrorCode_ = NO_ERROR;
	}

	bool Date::operator==(const Date & D) const{
		return value() == D.value();
	}

	bool Date::operator!=(const Date & D) const {
		return value() != D.value();
	}

	bool Date::operator<(const Date & D) const {
		return value() < D.value();
	}

	bool Date::operator>(const Date & D) const {
		return value() > D.value();
	}

	bool Date::operator<=(const Date & D) const {
		return value() <= D.value();
	}

	bool Date::operator>=(const Date & D) const {
		return value() >= D.value();
	}

	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}

	int Date::errCode() const{
		return readErrorCode_;
	}

	bool Date::bad() const {
		return readErrorCode_ != 0 ? true : false;
	}

	std::istream & Date::read(std::istream & istr){
		char sep;

		istr >> year_ >> sep >> mon_ >> sep >> day_;
		if (istr.fail())
			readErrorCode_ = CIN_FAILED;
		else {
			if (year_ >= MIN_YEAR && year_ <= MAX_YEAR) {
				if (mon_ >= 1 && mon_ <= 12) {
					if (day_ >= 1 && day_ <= mdays()) {
						readErrorCode_ = NO_ERROR;
					}
					else readErrorCode_ = DAY_ERROR;
				}
				else readErrorCode_ = MON_ERROR;
			}
			else readErrorCode_ = YEAR_ERROR;
		}

		return istr;
	}

	std::ostream & Date::write(std::ostream & ostr) const{
		ostr << year_ << '/'<< setfill('0') << setw(2) << mon_ << '/' << setfill('0') << setw(2) << day_;
		return ostr;
	}

	std::istream & operator>>(std::istream & instr, Date & date){
		date.read(instr);
		return instr;
	}

	std::ostream & operator<<(std::ostream & output, const Date & date){
		date.write(output);
		return output;
	}
	

}