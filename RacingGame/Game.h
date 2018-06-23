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
	// temporary value storing time, should be reset every time it exceeds update time
	float elapsed_time;
	// sfml clock, reset every display loop
	sf::Clock clock;
private:
	// handles all events from display loop
	void handle_event(float time_delta, sf::Event& event);
	// shows relevant info about game state on the screen
	void draw_debug_info(sf::Font* font);
	// help to convert speed in m/s to km/h
	int speed_to_kmh(int double_ms);
	// updates game state, delta time is calculated time of one full display loop
	void update(float delta_time);
	
public:
	Game();
	~Game();
	// creates display window, draws and updates relevant entities in a loop
	void display();
};

