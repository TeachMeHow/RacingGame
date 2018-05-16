#define _USE_MATH_DEFINES // for C++  
#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>  

sf::Vector2f change_direction(sf::Event::KeyEvent key, float& direction)
{
	float x, y;
	// a^2 + b^2 == 1
	// direction
	// angle from 0 to 2p
	// float angle = direction;
	switch (key.code)
	{
	case sf::Keyboard::Left :
		direction = M_PI;
		break;
	case sf::Keyboard::Right :
		direction = 0;
		break;
	case sf::Keyboard::Up :
		direction = 1.5 * M_PI;
		break;
	case sf::Keyboard::Down :
		direction = 0.5 * M_PI;
		break;

	}
	y = std::sin(direction);
	x = std::cos(direction);
	return sf::Vector2f(x, y);
	
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Game");
	sf::Font font;
	if (!font.loadFromFile("fonts/INVASION2000.ttf"))
		return 1;
	sf::Text text;
	text.setCharacterSize(24);
	text.setFont(font);
	text.setPosition(20, 20);
	text.setFillColor(sf::Color::White);
	text.setString("I CAN DRAW");
	float pixel_per_second = 40.0;
	std::chrono::duration<float> second = std::chrono::seconds(1);
	// move 1 pixel every interval
	std::chrono::duration<float> interval = second / pixel_per_second;
	std::chrono::time_point<std::chrono::steady_clock> t0, t1;

	float angle = 0;
	sf::Vector2f shift(1, 0);
	
	bool move = false;
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
					move = !move;
					t0 = std::chrono::steady_clock::now();
				}
			}
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) \
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right) \
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) \
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		shift = change_direction(event.key, angle);
		// continous movement

		t1 = std::chrono::steady_clock::now();
		std::chrono::duration<float> dur = t1 - t0;
		if (dur > interval)
		{
			t0 = std::chrono::steady_clock::now();
			sf::Vector2f t_pos = text.getPosition();
			sf::Vector2f new_pos = t_pos + shift;
			text.setPosition(new_pos);
		}
	}
		window.clear();
		window.draw(text);
		window.display();
	}
	window.close();
	return 0;
}