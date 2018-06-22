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
	// update everey x seconds (1 / freq [HZ])
	const float update_time = 1.0f / 30.0f;
	float elapsed_time;
	sf::Clock clock;
private:
	void handle_event(float time_delta, sf::Event& event);
	void draw_debug_info(sf::Font* font);
	int speed_to_kmh(int double_ms);
	void update(float delta_time);
	
public:
	Game();
	~Game();
	void display();
};

