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

void Coin::setCurrentPosition(int x)
{
	if (x >= 0 && x < 7)
	{
		float dx = (x - position) * 125.0f * 0.5f;
		move(sf::Vector2f(dx, 0));
		position = x;
	}
}

void Coin::update()
{
	if (falling)
	{
		if (getPosition().y < finalPosition)
		{
			speed += gravity;
			move(sf::Vector2f(0, speed));			
		}
		else
		{
			setPosition(sf::Vector2f(getPosition().x, finalPosition));			
			changeFallingState();
		}			
	}
}
