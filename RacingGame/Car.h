#pragma once
#include <SFML/Graphics.hpp>
class Car
{
	// in m/s
	const double max_speed = 150 * 1000 / 3600.0;
	// in m/s - gas
	const double acceleration = 4;
	// in m/s - braking
	const double deceleration = 8;
	//in m/s
	double speed = 0;
	// car steers in direction
	enum Direction { STRAIGHT, LEFT, RIGHT } direction;
	void accelerate(float time_delta);
	void brake(float time_delta);
	double steer(int wheel);
	sf::Clock clock;

	sf::Texture models;
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
	void update(int pedal, int wheel);
	// display car, depends on the direction
	void draw(sf::RenderWindow& window);
	// returns speed in m/s
	double get_speed();
	// returns direction in degrees
	int get_direction();

};

