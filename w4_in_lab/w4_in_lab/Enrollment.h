#ifndef _SICT_ENROLMENT_H_
#define _SICT_ENROLMENT_H_
namespace sict {
	class Enrollment {
		char name_[31];
		char code_[11];
		int year_, semester_, slot_;
		bool enrolled_;

	public:
		Enrollment();
		Enrollment(const char*, const char*, int, int, int);
		bool isEnrolled() const;
		bool isValid() const;
		void setEmpty();
		void display(bool onlyName = false)const;
		void set(const char*, const char*, int, int, int, bool enrolled = false);
		bool hasConflict(const Enrollment &other) const;
	};
}
#endif