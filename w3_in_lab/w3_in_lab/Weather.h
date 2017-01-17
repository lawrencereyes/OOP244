#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_

namespace sict {
	class Weather {
		char _date[7];
		double _high, _low;
		
		public:
			void set(const char*, double, double);
			void display() const;
	};
}
#endif
