// Track class represents road a car is travelling on
// Track map is described in a text file map.txt
// Track is described by length, width, turns, positions of cars that are on it
// Track can be drawn on the screen, reset when it reaches the end and should be updated
//
// Szymon Cichy 235093
// June 2018
#pragma once
#include "Car.h"
#include "Animation.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Track
{
private:
	enum Turn { LEFT, STRAIGHT, RIGHT };

	// track continues in directions[pos_index] direction
	std::vector<int> directions;
	// until distances[pos_index] is reached
	std::vector<float> distances;
	
	// increments each time car_position exceeds distances[pos_index]
	int pos_index;
	// current car position on the track in m
	float car_position;
	// track length in m
	float total_length;
	// in m
	float track_width;
	// car offset from road center in m
	float car_offset;

	sf::Texture track_texture;
	Animation track_animation;
	Car& player;
private:
	// throws exception if map couldn't be loaded
	void read_map(const char* filename);
public:
	// load track textures
	Track(Car& car);
	~Track();
	void draw(sf::RenderWindow& window);
	// time delta is time since last update
	void update(float time_delta);
	// when the track is reset, either new lap should begin or the game should end
	void reset_track();
	float get_car_distance() const { return car_position; };
	int debug_get_turn() const { return directions[pos_index]; };
};

