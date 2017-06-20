#include "Dialog.h"

Dialog::Dialog()
{
	;
}

Dialog::Dialog(const sf::String & string)
{
	createShape();
	text.setString(string);
	createText();
}

void Dialog::createShape()
{
	shape.setSize(sf::Vector2f(350.0f, 150.0f));
	shape.setFillColor(sf::Color(69, 159, 212, 200));
	shape.setOrigin(sf::Vector2f(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2));
	shape.setPosition(sf::Vector2f(Config::windowSize.x / 2.0f, Config::windowSize.y / 2));
	shape.setOutlineThickness(5);
	shape.setOutlineColor(sf::Color::White);
}

void Dialog::createText()
{
	text.setFont(Data::font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setOrigin(sf::Vector2f(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f));
	text.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y - 10));
}

void Dialog::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape);
	target.draw(text);
}