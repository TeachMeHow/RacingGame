#include "Track.h"
#include <fstream>


void Track::read_map(const char * filename)
{
	std::ifstream map;
	map.open(filename);
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
		if (!distances.empty()) dist += distances.back();
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
}

void Track::reset_track()
{
	car_position = 0;
	pos_index = 0;
}

Track::Track(Car& car) : player(car), track_animation(&track_texture, sf::Vector2u(2, 2))
{
	car_position = 0;
	car_offset = 0;
	pos_index = 0;

	read_map("map.txt");
	

	if (!track_texture.loadFromFile("graphics/track_animation.png"))
		throw "Couldn\'t load texture";
	track_animation = Animation(&track_texture, sf::Vector2u(2, 2));
	track_animation.part.width -= 320;
}


Track::~Track()
{
}

void Track::draw(sf::RenderWindow & window)
{
	sf::RectangleShape rect(sf::Vector2f(320, 100));
	const float pix_per_meter = 340.0f / float(track_width);
	//
	//sf::IntRect part(160 + int(pix_per_meter * car_offset), 0, 320, 100);
	rect.setTexture(&track_texture);
	rect.setTextureRect(track_animation.part);
	rect.setPosition(0.0f, 224.0f - 100.0f);
	window.draw(rect);
}

void Track::update(float time_delta)
{
	car_position += player.distance_delta(time_delta);
	if (car_position > distances[pos_index])
	{
		pos_index++;
	}

	float rate = (2.5f / 41.0f) * player.get_speed();
	if (directions[pos_index] == RIGHT)
		rate = -rate;
	else if (directions[pos_index] == STRAIGHT)
		rate = 0;
	float dist_1 = rate * time_delta;
	float dist_2 = player.offset_delta(time_delta);
	car_offset += dist_1 + dist_2;

	// collision
	float left_boundary, right_boundary;
	left_boundary = -track_width / 2;
	right_boundary = track_width / 2;
	// how much the car slows down
	if (car_offset < left_boundary || car_offset > right_boundary)
	{
		player.collide(time_delta);
	}

	int row;
	if (directions[pos_index] == STRAIGHT)
		row = 0;
	else row = 1;

	bool is_left = directions[pos_index] == LEFT ? true : false;
	// 1 switch is 2 m
	// switch every 2[m] / speed[m/s] seconds
	float switch_time = 2.0f / player.get_speed();

	// update track animation with some changes
	track_animation.part.width = 640;
	track_animation.update(row, time_delta, switch_time, is_left);
	track_animation.part.width = is_left ? -320 : 320;
	float offset;
	const float pix_per_meter = 340.0f / float(track_width);
	offset = is_left ? -(160.0f + car_offset * pix_per_meter) : (160.0f + car_offset * pix_per_meter);
	//offset += car_offset * pix_per_meter;
	track_animation.part.left += offset;

}
