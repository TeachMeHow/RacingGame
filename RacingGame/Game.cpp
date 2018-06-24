#include "Game.h"
#include <string>



void Game::handle_event(float time_delta, sf::Event& event)
{
	// car update params
	int pedal = 0;
	int wheel = 0;

	switch (event.type)
	{
	case sf::Event::Closed:
		window.close();
		break;
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			pedal = 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			pedal = -1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			wheel = -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			wheel = 1;
		break;
	}
	player.control(pedal, wheel);
}

void Game::draw_debug_info(sf::Font* font)
{
	// origin and positioning
	sf::Vector2f origin(0.0f, 0.0f);
	int row_height = 12;
	// text font and style
	int char_size = 10;
	sf::Text text;
	text.setFont(*font);
	text.setCharacterSize(char_size);
	text.setFillColor(sf::Color::White);
	std::string buffer;

	// speed
	buffer = "Speed: " + std::to_string(speed_to_kmh(player.get_speed())) + " km/h";
	text.setString(buffer);
	text.setPosition(origin);
	window.draw(text);

	// track turn
	std::string str;
	switch (track.debug_get_turn())
	{
	case 0: str = "left";
		break;
	case 1: str = "straight";
		break;
	case 2: str = "right";
		break;
	}
	buffer = "Turn: " + str;
	text.setString(buffer);
	origin += sf::Vector2f(0.0f, float(row_height));
	text.setPosition(origin);
	window.draw(text);

	// Direction the car is steering in
	buffer = "Direction: " + std::to_string(player.get_direction());
	text.setString(buffer);
	origin += sf::Vector2f(0.0f, float(row_height));
	text.setPosition(origin);
	window.draw(text);

	// Car position on the track
	buffer = "Distance: " + std::to_string(int(track.get_car_distance())) + "m";
	text.setString(buffer);
	origin += sf::Vector2f(0.0f, float(row_height));
	text.setPosition(origin);
	window.draw(text);
}

int Game::speed_to_kmh(int double_ms)
{
	int speed;
	speed = double_ms * (3600.0f / 1000.0f);
	return speed;
}

void Game::update(float time_delta)
{
	elapsed_time += time_delta;
	if (elapsed_time > update_time)
	{
		player.update(elapsed_time);
		track.update(elapsed_time);
		elapsed_time -= update_time;
	}
}

Game::Game() : track(player)
{
}


Game::~Game()
{
}

void Game::display()
{
	int w_height = 720;
	// width / height
	float aspect_ratio = 320.0f / 224.0f;
	int w_width = w_height * aspect_ratio;
	window.create(sf::VideoMode(w_width, w_height), "Game");
	// view with the same size as original Outrun
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(320.0f , 224.0f));
	sf::Vector2f screen_center(320 / 2.0f, 224 / 2.0f);
	view.setCenter(screen_center);

	sf::Font font;
	if (!font.loadFromFile("fonts/PressStart2P.ttf"))
		throw "Couldn\'t load font";

	float time_delta;
	elapsed_time = 0.0f;
	clock.restart();
	while (window.isOpen())
	{
		time_delta = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			handle_event(time_delta, event);
		}

		update(time_delta);

		window.clear(sf::Color::Blue);
		window.setView(view);
		track.draw(window);
		player.draw(window);
		draw_debug_info(&font);
		window.display();
	}
	window.close();
}
