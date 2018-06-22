#pragma once
#include "Car.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Track
{
private:
	enum Turn { LEFT, STRAIGHT, RIGHT };

	// track continues in directions[pos_index] direction
	std::vector<Turn> directions;
	// until distances[pos_index] is reached
	std::vector<float> distances;
	
	// increments each time car_position exceeds distances[pos_index]
	int pos_index;
	// current car position on the track in m
	float car_distance;
	// track length in m
	float total_length;
	// in m
	float track_width;
	// car offset from road center in m
	float car_offset;

	sf::Texture track_texture;
public:
	// load track textures
	Track();
	~Track();
	void draw(sf::RenderWindow& window);
	// time delta is time since last update
	void update(float time_delta);
};

