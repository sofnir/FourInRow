#pragma once
#include <SFML\Graphics.hpp>
#include "Data.h"

class Dialog : public sf::Drawable
{
public:
	Dialog();
	Dialog(const sf::String & string);

	void createShape();
	void createText();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::RectangleShape shape;
	sf::Text text;
};
