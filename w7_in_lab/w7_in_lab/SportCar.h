#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_

#include "Car.h"
#include <iostream>
namespace sict {
	class SportCar : public Car {
		int noOfPassengers_;
	public:
		SportCar();
		SportCar(int maxS, int noOfPass);

		void accelerate();
		void brake();
		std::ostream& display(std::ostream& ostr) const;
	};
}
#endif
