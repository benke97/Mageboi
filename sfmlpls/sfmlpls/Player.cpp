#include "Player.h"
#include <math.h>
#include <iostream>

void Player::render(sf::RenderWindow & target)
{
	playersprite.setTexture(playertexture);
	float x = (float)(position.first);
	float y = (float)(position.second);
	playersprite.setOrigin(0, 0);
	playersprite.setPosition(x, y);
	target.draw(playersprite);

}

void Player::toggleStorm()
{
	Storm = !Storm;
}

void Player::set_Storm(bool b)
{
	Storm = b;
}

bool Player::get_Storm()
{
	return Storm;
}
