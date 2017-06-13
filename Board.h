#pragma once
#include <SFML\Graphics.hpp>
#include <Windows.h>

class Board
{
public:
	Board();

	const sf::Sprite & Sprite() { return sprite; }
	const sf::Vector2f * HolesPosition() { return & holesPosition[0][0]; }

private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f holesPosition[6][7];

	void loadTexture();
	void create();
	void setHolesPosition();
};