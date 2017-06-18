#include "Coin.h"

Coin::Coin()
{
	;
}

Coin::Coin(const sf::Texture & texture) : sf::Sprite(texture)
{
	setOrigin(getGlobalBounds().width / 2.0f, getGlobalBounds().height / 2.0f);
	setPosition(sf::Vector2f(Config::windowSize.x / 2.0f, 50));
	setScale(sf::Vector2f(0.5f, 0.5f));
}

void Coin::moveRight()
{
	if (position < 6)
	{
		move(sf::Vector2f(125.0f * 0.5f, 0));
		position++;
	}
}

void Coin::moveLeft()
{
	if (position > 0)
	{
		move(sf::Vector2f(-125.0f * 0.5f, 0));
		position--;
	}
}
