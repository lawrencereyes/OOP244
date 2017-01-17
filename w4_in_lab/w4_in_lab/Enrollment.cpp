using namespace std;
#include <iostream>
#include <cstring>
#include "Enrollment.h"

namespace sict {
	Enrollment::Enrollment(){
		setEmpty();
	}

	Enrollment::Enrollment(const char *name, const char *code, int year, int semester, int slot) {
		setEmpty();
		set(name, code, year, semester, slot);
	}

	bool Enrollment::isEnrolled() const{
		return enrolled_;
	}

	bool Enrollment::isValid() const {
		return name_ && name_[0];
	}

	void Enrollment::setEmpty(){
		name_[0] = 0;
		code_[0] = 0;
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;
	}

	void Enrollment::display(bool nameOnly)const{
		if (isValid()) {
			cout << name_;
			if (!nameOnly) {
				cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else {
			cout << "Invalid enrollment!" << endl;
		}
	}

	void Enrollment::set(const char *name , const char *code, int year, int semester, int slot, bool enrolled){
		setEmpty();
		if (name != nullptr && name != NULL && name[0] != '0') {
			if (code != nullptr && code != NULL && code[0] != '0') {
				if (year >= 2015) {
					if (semester > 0 && semester < 4) {
						if (slot > 0 && slot < 6) {
							strcpy(name_, name);
							strcpy(code_, code);
							year_ = year;
							semester_ = semester;
							slot_ = slot;
							enrolled_ = enrolled;
						}
					}
				}
			}
		}
	}

	bool Enrollment::hasConflict(const Enrollment & other)const{
		bool check = false;
		if (other.year_ == year_) {
			if (other.year_ == 0 && year_ == 0) {
				check = false;
				return check;
				if (other.semester_ == semester_) {
					if (other.slot_ == slot_) {
						check = true;
					}
				}
			}
		}
		return check;
	}
}