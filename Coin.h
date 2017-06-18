#pragma once
#include "SFML\Graphics.hpp"
#include "Data.h"

class Coin : public sf::Sprite
{
public:
	Coin();
	Coin(const sf::Texture &texture);

	int getCurrentPosition() const { return position; }
	void moveRight();
	void moveLeft();

private:
	int position = 3;
};
