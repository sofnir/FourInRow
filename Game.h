#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Mouse.hpp>
#include <stack>
#include <iostream>
#include "Data.h"

class GameState;

class Game
{
public:
	Game();
	~Game();

	sf::RenderWindow window;
	sf::Vector2f mousePosition;
	Data data;

	void pushState(GameState* state);
	void popState();
	GameState* peekState();

	void gameLoop();

private:
	std::stack<GameState*> states;
};

