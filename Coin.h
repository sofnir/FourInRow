#pragma once
#include "Data.h"

class Coin : public sf::Sprite
{
public:
	Coin();
	Coin(const sf::Texture &texture);

	int getCurrentPosition() const { return position; }
	void setCurrentPosition(int x);
	void update();
	void changeFallingState() { falling = !falling; }
	void setFinalPosition(float y) { finalPosition = y; }

private:
	int position = 3;
	bool falling = false;
	float speed = 0;
	float gravity = 0.6;
	float finalPosition;
};
