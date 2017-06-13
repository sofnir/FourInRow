#pragma once
#include "Coin.h"
#include "Board.h"

class Logic
{
public:
	Logic();

	int checkLogic();
	void restart();
	int * TabLogic() { return & tabLogic[0][0]; }

private:

	int tabLogic[6][7];
};

