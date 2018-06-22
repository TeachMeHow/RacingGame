#include "Car.h"



void Car::accelerate(float time_delta)
{
	double speed_delta;
	speed_delta = acceleration * time_delta;
	speed += speed_delta;
	if (speed > max_speed)
		speed = max_speed;
}

void Car::brake(float time_delta)
{
	double speed_delta;
	speed_delta = deceleration * time_delta;
	speed -= speed_delta;
	if (speed < 0)
		speed = 0;
}

double Car::steer(int wheel)
{
	return 0.0;
}

Car::Car()
{
	if (!models.loadFromFile("graphics/cars.png"))
		throw "Couldn\'t load image";
}


Car::~Car()
{
}

void Car::update(int pedal, int wheel)
{
	float time_delta = clock.getElapsedTime().asSeconds();
	clock.restart();
	switch (pedal)
	{
	case 1:
		accelerate(time_delta);
		break;
	case -1:
		brake(time_delta);
		break;
	}
}

void Car::draw(sf::RenderWindow & window)
{
	// calculate appropriate texture based on direction
	sf::RectangleShape body;
	sf::IntRect rect;
}

double Car::get_speed()
{
	return speed;
}

int Car::get_direction()
{
	return direction  - 1;
}

float Car::distance_delta(float time_delta)
{
	float distance;
	distance = speed * time_delta;
	return distance;
}
