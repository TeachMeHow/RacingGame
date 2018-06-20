#pragma once
#include <SFML/Graphics.hpp>
#include "Track.h"
class Game
{
	Track track;
	sf::RenderWindow window;
	void handle_event(sf::Event& event);
public:
	Game();
	~Game();
	void start();
	void display();
};

