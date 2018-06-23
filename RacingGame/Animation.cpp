#include "Animation.h"


Animation::Animation(sf::Texture * texture, sf::Vector2u image_count, float switch_time)
{
	this->image_count = image_count;
	this->switch_time = switch_time;
	elapsed_time = 0.0f;
	current_image.x = 0;
	part.width = texture->getSize().x / float(image_count.x);
	part.height = texture->getSize().x / float(image_count.y);
}

Animation::~Animation()
{
}

void Animation::update(int row, float delta_time)
{
	current_image.y = row;
	elapsed_time += delta_time;
	if (elapsed_time > switch_time)
	{
		elapsed_time -= switch_time;
		current_image.x++;
		if (current_image.x >= image_count.x)
			current_image.x = 0;
	}
}
