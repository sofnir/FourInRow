#pragma once
#include <SFML\Window\Event.hpp>
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

	void draw() override;
	void update() override;
	void handleInput() override;

private:
	Board board;
	Coin * coin;
	Logic logic;
	TextButton buttons[2];
	Dialog *dialog;

	void createButtons();
};
