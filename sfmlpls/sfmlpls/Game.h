#pragma once
#include "Player.h"
#include <utility>
#include "Ice.h"
#include "Icicle.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <algorithm>
#include "Collision.h"

class Game
{
public:
	Game();
	~Game() = default;

	void update(sf::Clock &, sf::RenderWindow &);
	void render(sf::RenderWindow &);
	void fillStorm();

private:
	Player mageboi;
	std::vector<Ice> stormvector{};
	std::vector<Icicle> iciclevector{};
	std::vector<Icicle>::iterator icicleiterator{};
	std::vector<Ice>::iterator stormiterator{};
	bool Qpressed{true};
};

