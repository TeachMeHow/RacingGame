#define _USE_MATH_DEFINES // for cmath PI
#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>  

int main()
{
	sf::Text text;
	text.setCharacterSize(24);
	text.setFont(font);
	text.setPosition(20, 20);
	text.setFillColor(sf::Color::White);
	text.setString("I CAN DRAW");
	float pixel_per_second = 100.0;
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
		//shift = change_direction(event.key, angle);
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