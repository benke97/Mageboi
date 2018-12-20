#include "Game.h"

Game::Game() : mageboi{5,500,500,40,40}	
{

}

void Game::render(sf::RenderWindow & target)
{
	float floatx = (float)(mageboi.get_midpoint().first);
	float floaty = (float)(mageboi.get_midpoint().second);
	sf::View playerview(sf::FloatRect(floatx - 480.0f, floaty - 270.0f, 960.0f, 540.0f));
	target.setView(playerview);
	sf::CircleShape circ(10.0f);
	circ.setOrigin(0, 0);
	circ.setPosition(100, 100);
	target.draw(circ);
	mageboi.render(target);
	if (mageboi.get_Storm())
	{
		for (stormiterator = stormvector.begin(); stormiterator < stormvector.end(); ++stormiterator)
		{
			stormiterator->render(target);
		}
	}
	if (!iciclevector.empty())
	{
		for (icicleiterator = iciclevector.begin(); icicleiterator < iciclevector.end(); ++icicleiterator)
		{
			icicleiterator->render(target);
		}
	}
	//std::cout << mageboi.get_position().first << " " << mageboi.get_position().second << std::endl;
}

void Game::fillStorm()
{
	for (int i = 0; i < 35; ++i)
	{
		Ice ice(mageboi);
		stormvector.push_back(ice);
	}
}

void Game::update(sf::Clock & GCD, sf::RenderWindow & target)
{
	std::pair<int, int> dir;
	dir.first = 0;
	dir.second = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		dir.second -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		dir.first -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		dir.second += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		dir.first += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		if (Qpressed)
		{
			Qpressed = false;
			if (GCD.getElapsedTime().asMilliseconds() > 100)
			{
				if (mageboi.get_Storm())
				{
					stormvector.clear();
					mageboi.toggleStorm();
				}
				else
				{
					fillStorm();
					mageboi.toggleStorm();
				}
				GCD.restart();
			}
		}
	}
	else
	{
		Qpressed = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (iciclevector.empty())
		{
			Icicle icicle(mageboi, target);
			iciclevector.push_back(icicle);
		}
		else
		{	
			Icicle  firstelement = iciclevector.back();
			if (!firstelement.oncooldown())
			{
				Icicle icicle(mageboi, target);
				iciclevector.push_back(icicle);
			}
		}

	}
	//iciclevector.erase(std::remove_if(iciclevector.begin(), iciclevector.end(), rangelimitreached()), iciclevector.end());
	sf::Texture xd;
	xd.loadFromFile("Icicle.png");
	sf::Sprite kexd;
	kexd.setTexture(xd);
	kexd.setPosition(100, 100);
	target.draw(kexd);
	if (Collision::PixelPerfectTest(mageboi.get_sprite(), kexd))
	{
		std::cout << "blyaaaaaaaaaaaaaaaaat" << std::endl;
	}

	if (!iciclevector.empty())
	{
		for (icicleiterator = iciclevector.begin(); icicleiterator < iciclevector.end(); ++icicleiterator)
		{
			if (icicleiterator->rangelimitreached())
			{
				iciclevector.erase(icicleiterator);
				break;
			}
			else
			{
				icicleiterator->update_position();
			}
		}
	}
	mageboi.set_direction(dir.first, dir.second);
	//std::cout << mageboi.get_direction().first << " " << mageboi.get_direction().second << std::endl;
	mageboi.update_position();
	if (mageboi.get_Storm())
	{
		for (stormiterator = stormvector.begin(); stormiterator < stormvector.end(); ++stormiterator)
		{
			stormiterator->update_position(mageboi);
		}
	}
}