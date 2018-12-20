#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	using Character::Character;
	void render(sf::RenderWindow & target);
	void toggleStorm();
	void set_Storm(bool);
	bool get_Storm();

private:
	bool Storm{ false };
	int ParticlePos{};
};

