#include <iostream>
#include <cstring>
#include <iomanip>
#include "Weather.h"
using namespace std;

namespace sict {
	void Weather::set(const char* date, double high, double low) {
		strcpy(_date, date);
		_high = high;
		_low = low;
	}

	void Weather::display() const {
		cout << setw(10) << left << setprecision(1) << setfill('_') << _date
			<< setw(6) << fixed << right << setprecision(1) << setfill('_') << _high
			<< setw(6) << setprecision(1) << setfill('_') << right << _low << endl;
	}

	const char * Weather::date() const
	{
		return _date;
	}

	double Weather::low() const
	{
		return _low;
	}
}