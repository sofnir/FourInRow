#include "Dialog.h"

Dialog::Dialog()
{
	;
}

void Dialog::createShape(sf::RenderWindow & window)
{
	shape.setSize(sf::Vector2f(350, 150));
	shape.setFillColor(sf::Color(30, 144, 255, 200));
	shape.setOrigin(sf::Vector2f(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2));
	shape.setPosition(sf::Vector2f(window.getSize().x / 2 , window.getSize().y / 2));
	shape.setOutlineThickness(5);
	shape.setOutlineColor(sf::Color::White);
}

void Dialog::createText(sf::Font & font)
{
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y - 10));
}

void Dialog::draw(sf::RenderWindow & window)
{
	window.draw(shape);
	window.draw(text);
}