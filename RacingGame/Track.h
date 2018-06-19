#pragma once
#include <vector>
#include "Car.h"
#include <SFML/Graphics.hpp>
class Track
{
	Car player;
	struct TrackSection
	{
		// -1 - left
		// 0 - straigh
		// 1 - right
		int turn;
		// in m
		double r;
		// in m - 1/4 pi * r if turn != 0
		double length;
	};
	std::vector<TrackSection> map;
	double total_length;
	sf::Texture track_texture;
public:
	// load track textures
	Track();
	~Track();
	void scroll();
	void draw(sf::RenderWindow& window);
};

