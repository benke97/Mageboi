#include "Ice.h"
#include <math.h>
#include <stdlib.h>



Ice::Ice(Player & mageboi)
{
	float x = (float)(rand() % 100 + 50);
	float y = (float)(rand() % 100 + 50);
	float s = (float)(rand() % 100);
	xscalar = x;
	yscalar = y;
	startPos = s;
	update_position(mageboi);
	IceTexture.loadFromFile("frostyboi.png");
}

float Ice::get_xscalar()
{
	return xscalar;
}

float Ice::get_yscalar()
{
	return yscalar;
}

float Ice::get_startPos()
{
	return startPos;
}

void Ice::update_position(Player & mageboi)
{
	int v1 = mageboi.get_position().first;
	int v2 = mageboi.get_position().second;
	float playerx = (float)(v1);
	float playery = (float)(v2);
	int wid = mageboi.get_width();
	int hei = mageboi.get_height();
	float width = (float)(wid);
	float height = (float)(hei);
	position.first = playerx + width/2 + xscalar * cos(startPos*3.14159265 / 50);
	position.second = playery + height/2 + yscalar * sin(startPos*3.14159265 / 50);
	prevposition.first = playerx + width / 2 + xscalar * cos((startPos-5)*3.14159265 / 50);
	prevposition.second = playery + height / 2 + yscalar * sin((startPos-5)*3.14159265 / 50);
	++startPos;
}

void Ice::render(sf::RenderWindow & target)
{
	IceSprite.setTexture(IceTexture);
	IceSprite.setOrigin(0, 0);
	IceSprite.scale(2, 2);
	IceSprite.setPosition(position.first, position.second);
	target.draw(IceSprite);
	IceSprite.setPosition(prevposition.first, prevposition.second);
	target.draw(IceSprite);
	IceSprite.scale(0.5, 0.5);
}

bool Ice::oncooldown()
{
	return 7000 - cooldownclock.getElapsedTime().asMilliseconds() > 0;
}

