#include "Car.h"



void Car::accelerate(float time_delta)
{
	double speed_delta;
	speed_delta = acceleration * time_delta;
	current_speed += speed_delta;
	if (current_speed > max_speed)
		current_speed = max_speed;
}

void Car::brake(float time_delta)
{
	double speed_delta;
	speed_delta = deceleration * time_delta;
	current_speed -= speed_delta;
	if (current_speed < 0)
		current_speed = 0;
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
	return current_speed;
}

int Car::get_direction()
{
	return direction;
}

float Car::distance_delta(float time_delta)
{
	float distance;
	distance = current_speed * time_delta;
	return distance;
}

float Car::offset_delta(float time_delta)
{
	float offset;
	switch (direction)
	{
	case STRAIGHT: offset = 0;
		break;
	case LEFT: offset = -v_speed * time_delta;
		break;
	case RIGHT: offset = v_speed * time_delta;
	}
	return offset;
}
