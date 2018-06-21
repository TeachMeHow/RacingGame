#include "Track.h"



Track::Track()
{

	if (!track_texture.loadFromFile("graphics/track_lower.png"))
		throw "Couldn\'t load texture";
	if (!image.loadFromFile("graphics/track_lower.png"))
		throw "Couldn\'t load texture";
}


Track::~Track()
{
}

void Track::draw(sf::RenderWindow & window)
{
	sf::RectangleShape rect(sf::Vector2f(320, 100));
	sf::IntRect part(160, 50, 320, 50);
	rect.setTexture(&track_texture);
	rect.setTextureRect(part);
	sf::IntRect part(160, 0, 320, 100);
	rect.setTextureRect(part);
	rect.setPosition(0.0f, 224.0f - 100.0f);
	window.draw(rect);
}
