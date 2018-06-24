// main file, launches the game
//
// Szymon Cichy 235093
// June 2018

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"	

int main()
{
	try	{
		Game game;
		game.display();
	} catch (const char* msg) {
		std::cerr << "Game couldn't start:\n" << msg;
	}
	return 0;
}