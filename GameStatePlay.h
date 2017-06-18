#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Board.h"
#include "Coin.h"
#include "Logic.h"
#include "TextButton.h"
#include "Dialog.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	virtual void draw() override;
	virtual void update() override;
	virtual void handleInput() override;

private:
	Board board;
	Coin * coin;
	Logic logic;
	TextButton buttons[2];
	Dialog *dialog;

	void createButtons();
};
