#include "Game.h"
#include <chrono>



void Game::handle_event(sf::Event& event)
{
	// car update params
	int pedal = 0, wheel = 0;
	switch (event.type)
	{
	case sf::Event::Closed:
		window.close();
		break;
	case sf::Event::KeyPressed:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			wheel = -1;
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
			wheel = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			pedal = 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
			pedal = -1;
			break;
	}
	player.update(pedal, wheel);
}

void Game::draw_debug_info(sf::Font* font)
{
	sf::Vector2f position(0.0f, 0.0f);
	int row_height = 16;
	int char_size = 14;
	sf::Text text;
	text.setFont(*font);
	text.setCharacterSize(char_size);
	text.setFillColor(sf::Color::White);
	text.setOutlineThickness(1);
	text.setOutlineColor(sf::Color::Black);
	std::string buffer;
	buffer = "Speed: " + std::to_string(speed_to_kmh(player.get_speed()));
	text.setString(buffer);
	position += sf::Vector2f(0.0f, 0 * row_height);
	text.setPosition(position);
	window.draw(text);

	buffer = "Direction: " + std::to_string(player.get_direction());
	text.setString(buffer);
	position += sf::Vector2f(0.0f, 1 * float(row_height));
	text.setPosition(position);
	window.draw(text);


}

int Game::speed_to_kmh(int double_ms)
{
	int speed;
	speed = double_ms * (3600.0f / 1000.0f);
	return speed;
}

void Game::update(float delta_time)
{
	elapsed_time += delta_time;
	if (elapsed_time > update_time)
	{
		track.update(update_time);

		elapsed_time -= update_time;
	}
}

Game::Game()
{
}


Game::~Game()
{
}

void Game::display()
{
	int w_height = 720;
	// width / height
	double aspect_ratio = 320.0f / 224.0f;
	int w_width = w_height * aspect_ratio;
	window.create(sf::VideoMode(w_width, w_height), "Game");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(320.0f , 224.0f));
	sf::Vector2f screen_center(320 / 2.0f, 224 / 2.0f);
	view.setCenter(screen_center);
	sf::Font font;
	if (!font.loadFromFile("fonts/INVASION2000.ttf"))
		throw "Couldn\'t load font";

	float delta_time;
	elapsed_time = 0.0f;
	clock.restart();
	while (window.isOpen())
	{
		delta_time = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			handle_event(event);
		}

		update(delta_time);

		window.clear();
		window.setView(view);
		track.draw(window);
		player.draw(window);
		draw_debug_info(&font);
		window.display();
	}
	window.close();
}
