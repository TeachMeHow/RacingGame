#define _USE_MATH_DEFINES // for cmath PI
#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>  
#include "Game.h"	
#include <iostream>

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