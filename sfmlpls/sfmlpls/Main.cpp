#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setFramerateLimit(60);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	Game g;
	sf::Clock GCD;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(20,40,20));

		g.update(GCD, window);
		g.render(window);

		window.display();
	}

	return 0;
}