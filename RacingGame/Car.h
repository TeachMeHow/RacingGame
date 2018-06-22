#pragma once
#include <SFML/Graphics.hpp>
class Car
{
private:
	// in m/s
	const float max_speed = 150 * 1000 / 3600.0;
	// vertical speed when turning in m/s
	const float v_speed = 3;
	// in m/s - gas
	const float acceleration = 4;
	// in m/s - braking
	const float deceleration = 8;
	//in m/s
	float current_speed;
	// -1 brake, 0 nothing, 1 gas
	int pedal;
	
	// car steers in direction
	enum Direction { LEFT = -1, STRAIGHT = 0, RIGHT = 1 } direction;

	sf::Texture models;

private:
public:
	// load car model
	Car();
	~Car();
	// pedal:
	// 1 - gas
	// 0 - nothing
	// -1 - brake
	// wheel:
	// -1 - left;
	// 0 - nothing
	// 1 - right
	// manipulate controls of the car
	void control(int pedal, int wheel);
	// update car state based on controls and time delta
	void update(float time_delta);
	// display car, depends on the direction
	void draw(sf::RenderWindow& window);
	// returns speed in m/s
	double get_speed();
	// returns direction - 'L', 'S' or 'R'
	int get_direction();
	// calculates distance travelled assuming current acceleration and speed, during delta time
	float distance_delta(float time_delta);
	// distance travelled either left(-), straight(0) or right(+), vertically, during delta time
	float offset_delta(float time_delta);
	void debug_set_speed(float speed) { current_speed = speed; };
	void debug_set_direction(int direction)
	{
		switch (direction)
		{
		case -1: this->direction = LEFT;
			break;
		case 0: this->direction = STRAIGHT;
			break;
		case 1: this->direction = RIGHT;
			break;
		}
	}

};

