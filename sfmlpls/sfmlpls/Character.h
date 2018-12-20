#include <utility>
#include <SFML/Graphics.hpp>

class Character
{
public:
	Character(int s, int x, int y, int h, int w);

	virtual ~Character() = default;

	virtual void set_direction(int, int);
	std::pair<int, int> get_direction();

	int get_speed();
	void set_speed(int);

	void set_position(int, int);
	std::pair<int, int> get_position();

	void update_position();

	std::pair<int, int> get_midpoint();
	void set_midpoint(int, int);
	sf::Sprite get_sprite();
	int get_height();
	int get_width();
	void stop();

protected:
	int speed;
	int height;
	int width;
	sf::Texture playertexture{};
	sf::Sprite playersprite{};
	std::pair<int, int> position;
	std::pair<int, int> direction;
	std::pair<int, int> midpoint;

};