#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::display()
{

	sf::RenderWindow window(sf::VideoMode(600, 600), "Game");
	sf::Font font;
	if (!font.loadFromFile("fonts/INVASION2000.ttf"))
		throw "Couldn\'t load font";
}
