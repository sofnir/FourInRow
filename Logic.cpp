#include "Logic.h"

Logic::Logic()
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			tabLogic[i][j] = 0;
}

int Logic::checkLogic()
{
	//vertical
	for (int j = 0; j <= 6; j++)
		for (int i = 5; i >= 3; i--)
		{
			if (tabLogic[i][j] == tabLogic[i - 1][j] && tabLogic[i][j] == tabLogic[i - 2][j] && tabLogic[i][j] == tabLogic[i - 3][j] && tabLogic[i][j] != 0)
			{
				if (tabLogic[i][j] == 1) return 1;
				else return 2;
			}
		}
	// horizontal
	for (int j = 5; j >= 0; j--)
		for (int i = 0; i <= 3; i++)
		{
			if (tabLogic[j][i] == tabLogic[j][i + 1] && tabLogic[j][i] == tabLogic[j][i + 2] && tabLogic[j][i] == tabLogic[j][i + 3] && tabLogic[j][i] != 0)
			{
				if (tabLogic[j][i] == 1) return 1;
				else return 2;
			}
		}
	// up right
	for (int i = 3; i <= 5; i++)
		for (int j = 0; j <= 3; j++)
		{
			if (tabLogic[i][j] == tabLogic[i - 1][j + 1] && tabLogic[i][j] == tabLogic[i - 2][j + 2] && tabLogic[i][j] == tabLogic[i - 3][j + 3] && tabLogic[i][j] != 0)
			{
				if (tabLogic[i][j] == 1) return 1;
				else return 2;
			}
		}
	// down right
	for (int i = 2; i >= 0; i--)
		for (int j = 0; j <= 3; j++)
		{
			if (tabLogic[i][j] == tabLogic[i + 1][j + 1] && tabLogic[i][j] == tabLogic[i + 2][j + 2] && tabLogic[i][j] == tabLogic[i + 3][j + 3] && tabLogic[i][j] != 0)
			{
				if (tabLogic[2][j] == 1) return 1;
				else return 2;
			}
		}

	return 0;
}

void Logic::restart()
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			tabLogic[i][j] = 0;
}
