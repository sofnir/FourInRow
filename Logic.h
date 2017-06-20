#pragma once
#include "Board.h"
#include "Coin.h"
#include "Data.h"

enum class gameState { PLAYING, RED_WIN, YELLOW_WIN, DRAW };

class Logic
{
public:
	Logic();

	bool isRedTurn() const { return redTurn == true; }
	void changeTurn() { redTurn = !redTurn; }
	void setGameState(const gameState & s) { state = s; }
	void checkLogic(std::vector <std::vector <Coin*> > coins);
	gameState getState() const { return state; }

private:
	bool redTurn = true;
	gameState state = gameState::PLAYING;
};

