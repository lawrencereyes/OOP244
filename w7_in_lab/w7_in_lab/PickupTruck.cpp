#include <cstring>
#include "PickupTruck.h"

using namespace std;
using namespace sict;

namespace sict {
	PickupTruck::PickupTruck() {
		loadAmount_ = 0;
		loadedMaterial_[0] = '\0';
	}
	
	void PickupTruck::load(const char* loadedMaterial, int loadAmount) {
		loadAmount_ = loadAmount;
		strcpy(loadedMaterial_, loadedMaterial);
	}

	void PickupTruck::unload() {
		loadAmount_ = 0;
	}

	bool PickupTruck::isEmpty() const {
		return loadAmount_ == 0;
	}

	void PickupTruck::accelerate() {
		speed(speed() + 20);
	}

	void PickupTruck::brake() {
		speed(speed() - 5);
	}

	std::ostream& PickupTruck::display(std::ostream& ostr) const {
		if (isEmpty())
			ostr << "This pickup truck is not carrying any load";
		else
			ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial_;

		if (speed() > 0)
			ostr << ", traveling at the speed of " << speed() << " km/h.";
		else
			ostr << " and is parked.";

		return ostr;
	}
}