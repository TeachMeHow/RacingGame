#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u image_count, float switch_time);
	~Animation();
	void update(int row, float delta_time);

public:
	sf::IntRect part;

private:
	sf::Vector2u image_count;
	sf::Vector2u current_image;

	float elapsed_time;
	float switch_time;
};

