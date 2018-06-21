#pragma once
#include <SFML/Graphics.hpp>
#include "Track.h"
#include "Car.h"
class Game
{
private:
	Car player;
	Track track;
	sf::RenderWindow window;
private:
	void handle_event(sf::Event& event);
	void draw_debug_info(sf::Font* font);
	int speed_to_kmh(int double_ms);
	
public:
	Game();
	~Game();
	void start();
	void display();
};

