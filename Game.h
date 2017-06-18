#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
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

