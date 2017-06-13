#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>

const int numberOfItems = 2;

class Menu
{
public:
	Menu(sf::RenderWindow & window, std::string & state);
	void runMenu();

private:
	sf::RenderWindow *_window;
	std::string *_state;
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Font font;
	sf::Text title;
	sf::Text text[numberOfItems];
	sf::String str[numberOfItems] = { "Play","Exit" };

	void loadFont();
	void createBackground();
	void createText();
	void changeColor(const sf::Vector2f & mouse); //when cursor is on the text change the color
	void draw();
};