#pragma once
#include <SFML\Graphics.hpp>

class Dialog
{
public:
	Dialog();

	void createShape(sf::RenderWindow & window);
	void createText(sf::Font & font);
	void draw(sf::RenderWindow & window);

	sf::Text & Text() { return text; }
	bool & Show() { return show; }

private:
	sf::RectangleShape shape;
	sf::Text text;
	bool show = false;
};

