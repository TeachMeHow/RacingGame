#pragma once
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
	// direction facing in degrees
	double direction = 0;
	double accelerate(int pedal);
	double steer(int wheel);
public:
	// load car model
	Car();
	~Car();
	// -1 left, 1 right
	void turn(int dir);
	// pedal:
	// 1 - gas
	// 0 - nothing
	// -1 - brake
	// wheel:
	// -1 - left;
	// 0 - nothing
	// 1 - right
	void update_car(int pedal, int wheel);
	// display car, depends on the direction
	void draw();
	// returns speed in m/s
	double get_speed();
	// returns direction in degrees
	double get_direction();

};

