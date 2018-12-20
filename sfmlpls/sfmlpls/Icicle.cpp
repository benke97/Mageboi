#include "Icicle.h"
#include <iostream>


Icicle::Icicle(Player & mageboi, sf::RenderWindow & target)
{
	IcicleTexture.loadFromFile("Icicle.png");
	sf::Vector2i mousepos = sf::Mouse::getPosition(target);
	sf::Vector2f worldPos = target.mapPixelToCoords(mousepos);
	float mousex = worldPos.x;
	float mousey = worldPos.y;
	float playerx = (float)(mageboi.get_midpoint().first);
	float playery = (float)(mageboi.get_midpoint().second);
	float deltax = mousex - playerx;
	float deltay = mousey - playery;
	float x = deltax / sqrt(pow(deltax,2) + pow(deltay, 2));
	float y = deltay / sqrt(pow(deltax, 2) + pow(deltay, 2));
	set_direction(x, y);
	position.first = playerx;
	position.second = playery;
	if (deltay > 0)
	{
		std::cout << (180 / 3.1415)* acos(x) << std::endl;
		IcicleSprite.setRotation(30.0f + (180 / 3.1415)* acos(x));
	}
	else
	{
		IcicleSprite.setRotation(30.0f - (180 / 3.1415)* acos(x));
	}
}

void Icicle::update_position()
{
	//std::cout << "\n" << direction.first << " " << direction.second << std::endl << "\n";
	float xdistance = speed * direction.first;
	float ydistance = speed * direction.second;
	position.first += xdistance;
	position.second += ydistance;
	distancetraveled += sqrt(pow(xdistance, 2) + pow(ydistance, 2));
}

void Icicle::set_direction(float x, float y)
{
	direction.first = x;
	direction.second = y;
}

void Icicle::render(sf::RenderWindow & target)
{
	IcicleSprite.setTexture(IcicleTexture);
	IcicleSprite.setOrigin(16,16);
	//IcicleSprite.scale(2, 2);
	IcicleSprite.setPosition(position.first, position.second);
	target.draw(IcicleSprite);
	//IcicleSprite.scale(0.5, 0.5);
}

bool Icicle::oncooldown()
{
	return cooldown - cooldownclock.getElapsedTime().asMilliseconds() > 0;
}

bool Icicle::rangelimitreached()
{
	return range < distancetraveled;
}

