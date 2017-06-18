#include "Data.h"

sf::Font Data::font;
sf::Texture Data::redCoin;
sf::Texture Data::yellowCoin;
sf::Sprite Data::background;

Data::Data()
{
	font.loadFromFile("Data/font.ttf");
	redCoin.loadFromFile("Data/red.png");
	redCoin.setSmooth(true);
	yellowCoin.loadFromFile("Data/yellow.png");
	yellowCoin.setSmooth(true);
	backgroundTexture.loadFromFile("Data/background.png");
	createBackground();
}

void Data::createBackground()
{
	backgroundTexture.setSmooth(true);
	backgroundTexture.setRepeated(true);
	background.setTexture(backgroundTexture);
	background.setTextureRect(sf::IntRect(0, 0, Config::windowSize.x, Config::windowSize.y));
}