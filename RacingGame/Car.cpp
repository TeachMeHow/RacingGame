#include "Car.h"


void Car::control(int pedal, int wheel)
{
	this->pedal = pedal;
	switch (wheel)
	{
	case -1: this->direction = LEFT;
		break;
	case 0: this->direction = STRAIGHT;
		break;
	case 1: this->direction = RIGHT;
		break;
	}
}

void Car::update(float time_delta)
{
	if (pedal == 1)
	{
		float speed_delta;
		speed_delta = acceleration * time_delta;
		current_speed += speed_delta;
		if (current_speed > max_speed) current_speed = max_speed;
	}
	else if (pedal == -1)
	{
		float speed_delta;
		speed_delta = deceleration * time_delta;
		current_speed -= speed_delta;
		if (current_speed < 0) current_speed = 0;
	}
}

Car::Car()
{
	current_speed = 0;
	pedal = 0;
	if (!models.loadFromFile("graphics/cars.png"))
		throw "Couldn\'t load image";
}


Car::~Car()
{
}


void Car::collide(float time_delta)
{
	float speed_delta = deceleration * time_delta;
	if ((current_speed - speed_delta) < 2)
		current_speed -= speed_delta;
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
