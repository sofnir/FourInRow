#include "Logic.h"

Logic::Logic()
{
}

Logic::~Logic()
{
}
#include <iostream>
void Logic::checkLogic(std::vector <std::vector <Coin*> > coins)
{
	//vertival
	for (int j = 0; j <= 6; j++)
		for (int i = 5; i >= 3; i--)
		{
			if (coins[i][j] != nullptr && coins[i - 1][j] != nullptr && coins[i - 2][j] != nullptr && coins[i - 3][j] != nullptr)
			{
				if (coins[i][j]->getTextureRect() == coins[i - 1][j]->getTextureRect() && coins[i][j]->getTextureRect() ==
					coins[i - 2][j]->getTextureRect() && coins[i][j]->getTextureRect() == coins[i - 3][j]->getTextureRect())
				{
					state = (coins[i][j]->getTexture() == &Data::redCoin) ? RED_WIN : YELLOW_WIN;
					return;
				}
			}
		}
	// horizontal
	for (int i = 5; i >= 0; i--)
		for (int j = 0; j <= 3; j++)
		{
			if (coins[i][j] != nullptr && coins[i][j + 1] != nullptr && coins[i][j + 2] != nullptr && coins[i][j + 3] != nullptr)
			{
				if (coins[i][j]->getTextureRect() == coins[i][j + 1]->getTextureRect() && coins[i][j]->getTextureRect() ==
					coins[i][j + 2]->getTextureRect() && coins[i][j]->getTextureRect() == coins[i][j + 3]->getTextureRect())
				{
					state = (coins[i][j]->getTexture() == &Data::redCoin) ? RED_WIN : YELLOW_WIN;
					return;
				}
			}
		}
	// up right
	for (int i = 3; i <= 5; i++)
		for (int j = 0; j <= 3; j++)
		{
			if (coins[i][j] != nullptr && coins[i - 1][j + 1] != nullptr && coins[i - 2][j + 2] != nullptr &&
				coins[i - 3][j + 3] != nullptr)
			{
				if (coins[i][j]->getTexture() == coins[i - 1][j + 1]->getTexture() && coins[i][j]->getTexture() ==
					coins[i - 2][j + 2]->getTexture() && coins[i][j]->getTexture() == coins[i - 3][j + 3]->getTexture())
				{
					state = (coins[i][j]->getTexture() == &Data::redCoin) ? RED_WIN : YELLOW_WIN;
					return;
				}
			}
		}
	// down right
	for (int i = 2; i >= 0; i--)
		for (int j = 0; j <= 3; j++)
		{
			if (coins[i][j] != nullptr && coins[i + 1][j + 1] != nullptr && coins[i + 2][j + 2] != nullptr &&
				coins[i + 3][j + 3] != nullptr)
			{
				if (coins[i][j]->getTexture() == coins[i + 1][j + 1]->getTexture() && coins[i][j]->getTexture() ==
					coins[i + 2][j + 2]->getTexture() && coins[i][j]->getTexture() == coins[i + 3][j + 3]->getTexture())
				{
					state = (coins[i][j]->getTexture() == &Data::redCoin) ? RED_WIN : YELLOW_WIN;
					return;
				}
			}
		}

	//check draw
	int coinsNumber = 0;

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
		{
			if (coins[i][j] != nullptr)
			{
				coinsNumber++;
			}
		}

	if (coinsNumber == 42)
	{
		state = DRAW;
		return;
	}
}
