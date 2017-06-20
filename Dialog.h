#pragma once
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Text.hpp>
#include "Data.h"

class Dialog : public sf::Drawable
{
public:
	Dialog();
	Dialog(const sf::String & string);

	void createShape();
	void createText();

	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::RectangleShape shape;
	sf::Text text;
};
