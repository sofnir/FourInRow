#pragma once
#include "SFML\Graphics.hpp"
#include "Data.h"
#include "Coin.h"
#include <vector>

class Board : public sf::Drawable
{
public:
	Board();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	bool pushCoin(Coin * coin);
	std::vector <std::vector <Coin*> > getCoins() { return coins; }
	void reset();

private:
	sf::Texture boardTexture;
	sf::Sprite board;
	std::vector <std::vector <Coin*> > coins;

	void createBoard();
	int findHole(int x);
};
