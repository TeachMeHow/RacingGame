#include "Track.h"
#include <fstream>


Track::Track(Car& car) : player(car)
{
	car_distance = 0;
	car_offset = 0;
	pos_index = 0;
	std::ifstream map;
	map.open("map.txt");
	if (!map.is_open())
		throw "Couldn't load the map";
	int i;
	char dir;
	float dist; 
	// TODO reads last twice
	map >> track_width;
	while (!map.eof())
	{
		map >> i;
		map >> dist;
		map >> dir;
		distances.push_back(dist);
		switch (dir)
		{
		case 'L': directions.push_back(LEFT);
			break;
		case 'S': directions.push_back(STRAIGHT);
			break;
		case 'R': directions.push_back(RIGHT);
		}
	}
	total_length = 0;
	std::for_each(distances.cbegin(), distances.cend(), [&](float n) { total_length += n; });

	if (!track_texture.loadFromFile("graphics/track_lower.png"))
		throw "Couldn\'t load texture";
}


Track::~Track()
{
}

void Track::draw(sf::RenderWindow & window)
{
	sf::RectangleShape rect(sf::Vector2f(320, 100));
	const int pix_per_meter = 340 / track_width;
	//
	sf::IntRect part(160 + int(pix_per_meter * car_offset), 0, 320, 100);
	rect.setTexture(&track_texture);
	rect.setTextureRect(part);
	rect.setPosition(0.0f, 224.0f - 100.0f);
	window.draw(rect);
}

void Track::update(float time_delta)
{
	car_distance += player.distance_delta(time_delta);
	if (car_distance > distances[pos_index])
	{
		pos_index++;
	}
	float rate = -5.0f / 10.0f;
	switch (directions[pos_index])
	{
	case LEFT:
		rate = -5.0f / 10.0f;
		break;
	case STRAIGHT:
		rate = 0;
		break;
	case RIGHT:
		rate = -5.0f / 10.0f;
	}

	car_offset += rate * time_delta;
}

float Track::get_car_distance()
{
	return car_distance;
}
