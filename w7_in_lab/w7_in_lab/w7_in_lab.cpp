#include <iostream>
#include "SportCar.h"
#include "PickupTruck.h"
using namespace std;
using namespace sict;

void drive(Car& c) {
	c.accelerate();
	c.brake();
	c.display(cout) << endl;
}
void stop(Car& c) {

	while (c.speed() > 0)
	c.brake();

	c.display(cout) << endl;

}

int main()
{
	SportCar Tesla(240, 2);
	PickupTruck Ford;
	Tesla.display(cout) << endl;
	Ford.display(cout) << endl;
	Ford.load("Bricks", 3500);
	drive(Tesla);
	drive(Ford);
	stop(Tesla);
	stop(Ford);
	Ford.unload();
	Tesla.display(cout) << endl;
	Ford.display(cout) << endl;
	return 0;
}