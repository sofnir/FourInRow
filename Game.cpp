#include "Game.h"

Game::Game() : state("MENU")
{
	window.create(sf::VideoMode(700, 600), "FourInRow", sf::Style::Close);
	window.setFramerateLimit(144);
}

void Game::runGame()
{
	while (state != "END")
	{
		if (state == "MENU")
			menu();
		else if (state == "PLAY")
			play();
	}
}

void Game::menu()
{
	Menu menu(window, state);
	menu.runMenu();
}

void Game::play()
{
	Play play(window, state);
	play.runPlay();
}