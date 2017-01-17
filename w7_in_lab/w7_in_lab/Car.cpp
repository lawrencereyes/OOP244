#include "Car.h"
namespace sict {
	void Car::speed(int value) {
		if (value > maxSpeed_)
			maxSpeed_ = value;
		else if (value < 0)
			value = 0;

		speed_ = value;
	}

	int Car::maxSpeed() const {
		return maxSpeed_;
	}

	int Car::speed() const {
		return speed_;
	}

	Car::Car(int maxS) {
		maxSpeed_ = maxS;
		speed_ = 0;
	}
}