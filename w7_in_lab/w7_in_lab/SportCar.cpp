#include "SportCar.h"

using namespace std;
using namespace sict;

namespace sict {
	SportCar::SportCar() {
		noOfPassengers_ = 0;
	}

	SportCar::SportCar(int maxS, int noOfPass) : Car(maxS){
		noOfPassengers_ = noOfPass;
	}

	void SportCar::accelerate() {
		speed(speed() + 40);
	}

	void SportCar::brake() {
		speed(speed() - 10);
	}

	std::ostream & SportCar::display(std::ostream & ostr) const{
		if (speed() > 0)
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is traveling at a speed of " << speed() << " km/h.";
		else 
			ostr << "This sport car is carrying " << noOfPassengers_ << " pasengers and is parked.";

		return ostr;
	}
}