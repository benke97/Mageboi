#include "Character.h"

Character::Character(int s, int x, int y, int h, int w) : speed{ s }, height{ h }, width{ w }, position{ std::make_pair(x,y) },
direction{ std::make_pair(0,0) }, midpoint{ std::make_pair(x + w/2,y + h/2) }
{
	playertexture.loadFromFile("Orben.png");
}

void Character::set_speed(int new_speed)
{
	//Sets the speed of the Character to a new integer.
	speed = new_speed;
}

int Character::get_speed()
{
	//Returns the speed of the Character.
	return speed;
}

void Character::set_position(int x, int y)
{
	//Sets the position to a set of new coordinates.
	position.first = x;
	position.second = y;
}

void Character::set_midpoint(int x, int y)
{
	//Sets the midpoint to a set of new coordinates.
	midpoint.first = x + width/2;
	midpoint.second = y + height/2;
}

sf::Sprite Character::get_sprite()
{
	return playersprite;
}

std::pair<int, int> Character::get_midpoint()
{
	//Returns the coordinates for the middle of the Character.
	return midpoint;
}

std::pair<int, int> Character::get_position()
{
	//Returns the coordinates of the Character.
	return position;
}

int Character::get_height()
{
	//Returns the height of the Character.
	return height;
}
int Character::get_width()
{
	return width;
}
void Character::stop()
{
	//Sets the direction of the Character to 0.
	direction.first = 0;
	direction.second = 0;
}

void Character::set_direction(int x, int y)
{
	//Updates the direction of the Character.
	direction.first = x;
	direction.second = y;
}

std::pair<int, int> Character::get_direction()
{
	//Returns the current direction of the Character in a pair.
	return direction;
}


void Character::update_position()
{
	//Updates the position according to the velocity of the Character.
	position.first += speed * direction.first;
	position.second += speed * direction.second;
	midpoint.first = position.first + width/2;
	midpoint.second = position.second + height/2;
}