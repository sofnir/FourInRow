#pragma once
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include "Board.h"

class Coin
{
public:
	Coin();

	void create(const sf::Vector2f * holesPosition);
	void reset();
	void setProperties(int i);
	void move(const sf::Vector2f * holesPosition, const sf::Vector2f mousePos);
	void setStopPosition(const sf::Vector2f * holesPosition, const int * tabLogic);
	void moveDown();
	void setTabLogicValue(int * tabLogic);

	sf::Sprite & Sprite() { return sprite; }
	bool & Show() { return show; }
	bool & Enable() { return enable; }
	bool & Fall() { return fall; }
	float & StopPosition() { return stopPosition; }

private:
	sf::Sprite sprite;
	bool show;
	bool enable;
	bool fall;
	float stopPosition;
	sf::Texture redTexture;
	sf::Texture yellowTexture;
	int value;
	int xPosition;
	int yPosition;
    float speed;
	const float gravity;
	
	void loadTextures();
};

