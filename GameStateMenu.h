#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "TextButton.h"

class GameStateMenu : public GameState
{

public:
	GameStateMenu(Game* game);

	virtual void draw() override;
	virtual void update() override;
	virtual void handleInput() override;

private:
	sf::Text title;
	TextButton buttons[2];

	void createTitle();
	void createButtons();
	void playGame();
};
