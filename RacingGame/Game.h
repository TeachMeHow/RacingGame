#pragma once
#include <SFML/Graphics.hpp>
#include "Track.h"
class Game
{
	Track track;
public:
	Game();
	~Game();
	void start();
	void display();
};

