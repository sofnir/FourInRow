#include "Board.h"
#include <iostream>
Board::Board()
{
	createBoard();
	coins.resize(6);

	for (int i = 0; i < 6; i++)
		coins[i].resize(7);
}

void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(board);

	for (auto & row : coins)
		for (auto & coin : row)
			if (coin != nullptr)
				target.draw(*coin);
}

bool Board::pushCoin(Coin * coin)
{
	int x = coin->getCurrentPosition();
	int y = findHole(x) - 1; //hole index after falling

	if (y >= 0)
	{

		coins[y][x] = coin;
		int diff = (board.getGlobalBounds().top + 79.0f * 0.5f) - coins[y][x]->getPosition().y; //distance between coin and first hole
		float stopPosition = diff + y * 125.0f * 0.5f;
		coins[y][x]->move(sf::Vector2f(0, stopPosition));

		return true;
	}

	return false;
}

void Board::reset()
{
	coins.clear();
	coins.resize(6);

	for (int i = 0; i < 6; i++)
		coins[i].resize(7);
}

void Board::createBoard()
{
	boardTexture.loadFromFile("Data/board.png");
	boardTexture.setSmooth(true);
	board.setTexture(boardTexture);
	board.setOrigin(board.getGlobalBounds().width / 2.0f, board.getGlobalBounds().height / 2.0f);
	board.setPosition(sf::Vector2f(Config::windowSize.x / 2.0f, Config::windowSize.y / 2.0f));
	board.setScale(sf::Vector2f(0.5f, 0.5f));
}

int Board::findHole(int x)
{
	int stopPosition = 0;

	for (int y = 5; y >= 0; y--)
	{
		if (coins[y][x] == nullptr)
		{
			stopPosition++;
		}
	}

	return stopPosition;
}
