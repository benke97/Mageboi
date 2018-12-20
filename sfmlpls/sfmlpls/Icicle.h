#pragma once
#include "Player.h"
#include <vector>
#include <math.h>

class Icicle
{
public:
	Icicle(Player &, sf::RenderWindow &);
	~Icicle() = default;

	void update_position();
	void set_direction(float, float);
	void render(sf::RenderWindow &);
	bool rangelimitreached();
	bool oncooldown();

private:
	float distancetraveled{};
	float speed{10};
	float size{20};
	float range{ 300 };
	float cooldown{ 500 };
	sf::Clock cooldownclock;
	sf::Texture IcicleTexture{};
	sf::Sprite IcicleSprite{};
	std::pair<float, float> position{};
	std::pair<float, float> direction{};
};

