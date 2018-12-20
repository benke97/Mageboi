#pragma once
#include "Player.h"

class Ice
{
public:
	Ice(Player &);
	~Ice() = default;
	float get_xscalar();
	float get_yscalar();
	float get_startPos();
	void update_position(Player &);
	void render(sf::RenderWindow & target);
	bool oncooldown();

private:
	float xscalar;
	float yscalar;
	float startPos;
	float cooldown{ 7000 };
	sf::Clock cooldownclock;
	sf::Texture IceTexture{};
	sf::Sprite IceSprite{};
	std::pair<float, float> position{};
	std::pair<float, float> prevposition{};
};

