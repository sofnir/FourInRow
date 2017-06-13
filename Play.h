#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Board.h"
#include "Coin.h"
#include "Logic.h"
#include "Dialog.h"

class Play
{
public:
	Play(sf::RenderWindow & window, std::string & state);
	void runPlay();

private:
	sf::RenderWindow *_window;
	std::string *_state;
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Music music;
	sf::Font font;
	sf::Vector2f mousePosition;
	int number; //current coin number
	sf::Text text[2]; //menu items (Play again, Back)
	sf::String str[2] = { "Play again", "Back" };
	bool drawCoin = false;

	void createBackground();
	void loadMusic();
	void loadFont();
	void createText();
	void addCoin();
	void isFalling();
	void check(); //checking who win
	void endGame();
	void restart();
	void changeColor(); //when cursor is on the text change the color
	void draw();

	Board board;
	Logic logic;
	Coin coin[42];
	Dialog dialog;
};