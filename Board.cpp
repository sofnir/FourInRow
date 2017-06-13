#include "Board.h"

Board::Board()
{
	loadTexture();
	create();
	setHolesPosition();
}

void Board::loadTexture()
{
	if (!texture.loadFromFile("data/board.png"))
	{
		MessageBox(NULL, "Image not found!", "ERROR", NULL);
		return;
	}
	texture.setSmooth(true);
}

void Board::create()
{
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
	sprite.setPosition(sf::Vector2f(700/2 - sprite.getGlobalBounds().width/2, 100));
}

void Board::setHolesPosition()
{
	const int pictureFirstPosition = 79; //first hole position
	const int pictureSpace = 125; //space between holes
	//rescaling
	float scale = sprite.getScale().x;
	float firstPosition = pictureFirstPosition * scale;
	float space = pictureSpace * scale;

	sf::Vector2i boardPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
		{
			holesPosition[i][j].x = boardPosition.x + firstPosition + space * j;
			holesPosition[i][j].y = boardPosition.y + firstPosition + space * i;
		}
}
