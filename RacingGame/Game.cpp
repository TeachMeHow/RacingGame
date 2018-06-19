#include "Game.h"
#include <chrono>



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
	sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Game");
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
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
				}
			}
		}
		window.clear();
		window.setView(view);
		track.draw(window);
		window.display();
	}
	window.close();
}
