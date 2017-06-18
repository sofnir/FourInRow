#pragma once
#include "Board.h"
#include "Coin.h"
#include "Data.h"

enum gameState { PLAYING, RED_WIN, YELLOW_WIN, DRAW };

class Logic
{
public:
	Logic();
	~Logic();

	bool isRedTurn() const { return redTurn == true; }
	void changeTurn() { redTurn = !redTurn; }
	void setGameState(const gameState & s) { state = s; }
	void checkLogic(std::vector <std::vector <Coin*> > coins);
	gameState getState() const { return state; }

private:
	bool redTurn = true;
	gameState state = PLAYING;
};

