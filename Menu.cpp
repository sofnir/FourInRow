#include "Menu.h"

Menu::Menu(sf::RenderWindow & window, std::string & state)
	:_window(& window), _state(& state)
{
	loadFont();
	createBackground();
	createText();
}

void Menu::runMenu()
{
	while (*_state == "MENU")
	{
		sf::Event event;
		sf::Vector2f mouse(sf::Mouse::getPosition(*_window));

		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
				*_state = "END";
			//PLAY                                        
			else if (text[0].getGlobalBounds().contains(mouse) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				*_state = "PLAY";
			}

			//EXIT
			else if (text[1].getGlobalBounds().contains(mouse) &&
				event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				*_state = "END";
			}
		}

		changeColor(mouse);

		_window->clear();
		draw();
		_window->display();
	}
}

void Menu::loadFont()
{
	if (!font.loadFromFile("data/font.ttf"))
	{
		MessageBox(NULL, "Font not found!", "ERROR", NULL);
		return;
	}
}

void Menu::createBackground()
{
	//background pattern from subtlepatterns.com
	if (!backgroundTexture.loadFromFile("data/background.png"))
	{
		MessageBox(NULL, "backgroundImage not found!", "ERROR", NULL);
		return;
	}

	backgroundTexture.setSmooth(true);
	backgroundTexture.setRepeated(true);
	background.setTexture(backgroundTexture);
	background.setTextureRect(sf::IntRect(0, 0, _window->getSize().x, _window->getSize().y));
}

void Menu::createText()
{
	title.setString("Four In Row");
	title.setFillColor(sf::Color(30, 144, 255));
	title.setCharacterSize(80);
	title.setFont(font);
	title.setStyle(sf::Text::Bold);
	title.setPosition(_window->getSize().x / 2 - title.getGlobalBounds().width / 2, 100);

	for (int i = 0; i < numberOfItems; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(65);
		text[i].setString(str[i]);
		text[i].setPosition(_window->getSize().x / 2 - text[i].getGlobalBounds().width / 2, 280 + i * 120);
		text[i].setFillColor(sf::Color(54, 69, 79));
	}
}

void Menu::changeColor(const sf::Vector2f & mouse)
{
	for (int i = 0; i < numberOfItems; i++)
		if (text[i].getGlobalBounds().contains(mouse))
			text[i].setFillColor(sf::Color(30, 144, 255));
		else text[i].setFillColor(sf::Color(54, 69, 79));
}

void Menu::draw()
{
	_window->draw(background);
	_window->draw(title);

	for (int i = 0; i < numberOfItems; i++)
		_window->draw(text[i]);
}