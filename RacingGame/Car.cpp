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
	float speed_delta;
	// if gas pedal was pressed, acccelerate
	if (pedal == 1)
	{
		speed_delta = acceleration * time_delta;
		current_speed += speed_delta;
		if (current_speed > max_speed) current_speed = max_speed;
	}
	// if brake was pressed, decelerate
	else if (pedal == -1)
	{
		speed_delta = deceleration * time_delta;
		current_speed -= speed_delta;
		if (current_speed < 0) current_speed = 0;
	}
}

Car::Car()
{
	current_speed = 0;
	pedal = 0;
	direction = STRAIGHT;
	if (!models.loadFromFile("graphics/cars.png"))
		throw "Couldn\'t load image";
}


Car::~Car()
{
}


void Car::collide(float time_delta)
{
	float speed_delta = deceleration * time_delta;
	// slow down down to min. 4 m/s
	if ((current_speed - speed_delta) > 4)
		current_speed -= speed_delta;
}

void Car::draw(sf::RenderWindow & window)
{
	int row = 0;
	switch (direction)
	{
	case LEFT: row = 1;
		break;
	case RIGHT: row = 2;
		break;
	}
	sf::IntRect part(0, row * 54, 110, 54);
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(110.0f, 54.0f));
	rect.setTexture(&models);
	rect.setTextureRect(part);
	sf::Vector2f pos(window.getView().getCenter().x - (110.0f / 2.0f), window.getView().getSize().y - 54.0f);
	rect.setPosition(pos);
	window.draw(rect);
}

float Car::get_speed()
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
	float v_velocity = 5 * current_speed / max_speed;
	float offset;
	switch (direction)
	{
	case STRAIGHT: offset = 0;
		break;
	case LEFT: offset = -v_velocity * time_delta;
		break;
	case RIGHT: offset = v_velocity * time_delta;
	}
	return offset;
}
