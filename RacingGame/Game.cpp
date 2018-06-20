#include "Game.h"
#include <chrono>



void Game::handle_event(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		window.close();
		break;
	case sf::Event::KeyPressed:
		break;
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
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			handle_event(event);
		}
		window.clear();
		window.setView(view);
		track.draw(window);
		window.display();
	}
	window.close();
}
