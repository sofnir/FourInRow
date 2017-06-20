#pragma once
#include <SFML\Graphics\RenderTarget.hpp>
#include <vector>
#include "Data.h"
#include "Coin.h"

class Board : public sf::Drawable
{
public:
	Board();

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	bool pushCoin(Coin * coin);
	std::vector <std::vector <Coin*> > getCoins() { return coins; }
	void reset();
	void update();
	bool contain(const sf::Vector2f & mousePosition) { return board.getGlobalBounds().contains(mousePosition); }

private:
	sf::Texture boardTexture;
	sf::Sprite board;
	std::vector <std::vector <Coin*> > coins;

	void createBoard();
	int findHole(int x);
};
