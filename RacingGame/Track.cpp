#include "Track.h"



Track::Track()
{

	if (!track_texture.loadFromFile("graphics/track.png"))
		throw "Couldn\'t load texture";
}


Track::~Track()
{
}

void Track::draw(sf::RenderWindow & window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(track_texture.getSize()));
	rect.setPosition(0.0f, 0.0f);
	rect.setTexture(&track_texture);
	window.draw(rect);
}
