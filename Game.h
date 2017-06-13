#pragma once
#include "Menu.h"
#include "Play.h"
#include <windows.h>

class Game
{
public:
	Game();
	void runGame();

private:
	std::string state;
	sf::RenderWindow window;

	void menu();
	void play();
};