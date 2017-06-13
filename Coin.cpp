#include "Coin.h"

Coin::Coin() : show(false), enable(false), fall(false), xPosition(3), yPosition(-1), speed(0), 
gravity(0.2),stopPosition(0)
{
	loadTextures();
}

void Coin::create(const sf::Vector2f * holesPosition)
{
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	sprite.setOrigin(sf::Vector2f(redTexture.getSize().x / 2, redTexture.getSize().y / 2));
	sprite.setPosition(sf::Vector2f( (holesPosition + 3)->x , (holesPosition + 3)->y - 100));
}

void Coin::reset()
{
	show = false;
	enable = false;
	fall = false;
	xPosition = 3;
	yPosition = -1;
	stopPosition = 0;
}

void Coin::setProperties(int i)
{
	if (i % 2 == 0)
	{
		sprite.setTexture(redTexture);
		value = 1;
	}
	else {
		sprite.setTexture(yellowTexture);
		value = 2;
	}	

	show = true;
	enable = true;
}

void Coin::move(const sf::Vector2f * holesPosition, const sf::Vector2f mousePos)
{
	float width = sprite.getGlobalBounds().width / 2;

	for (int i = 0; i <= 6; i++)
	{
		if (mousePos.x >= (holesPosition + i)->x - width && mousePos.x <= (holesPosition + i)->x + width 
			&& mousePos.y < (holesPosition + 5 * 7)->y + width)
		{
			xPosition = i;
			sprite.setPosition(sf::Vector2f((holesPosition + i)->x, sprite.getPosition().y));
		}
	}	
}
#include <iostream>
void Coin::setStopPosition(const sf::Vector2f * holesPosition, const int * tabLogic)
{
	for (int i = 0; i < 6; i++)
		if (*(tabLogic + i * 7 + xPosition) == 0)
			yPosition++;
	
	if (yPosition > -1)
		stopPosition =  (holesPosition + yPosition * 7 + xPosition)->y;
}

void Coin::moveDown()
{
	sprite.move(0, speed);

	if (sprite.getPosition().y < stopPosition)
		speed += gravity;
	else
	{
		sprite.setPosition(sprite.getPosition().x, stopPosition);
		speed = 0;
		fall = false;
		enable = false;
	}
}

void Coin::setTabLogicValue(int * tabLogic)
{
	*(tabLogic + yPosition * 7 + xPosition) = value;
}

void Coin::loadTextures()
{
	if (!redTexture.loadFromFile("data/red.png"))
	{
		MessageBox(NULL, "Image not found!", "ERROR", NULL);
		return;
	}
	redTexture.setSmooth(true);

	if (!yellowTexture.loadFromFile("data/yellow.png"))
	{
		MessageBox(NULL, "Image not found!", "ERROR", NULL);
		return;
	}
	yellowTexture.setSmooth(true);
}
