#include "Car.h"



Car::Car()
{
	if (!models.loadFromFile("graphics/cars.png"))
		throw "Couldn\'t load image";
}


Car::~Car()
{
}
