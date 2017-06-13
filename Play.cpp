#include "Play.h"

Play::Play(sf::RenderWindow & window, std::string & state) : _window(& window), _state(& state), number(-1)
{
	createBackground();
	loadMusic();
	loadFont();
	restart();
	createText();
	dialog.createShape(window);
	dialog.createText(font);
}

void Play::runPlay()
{
	while (*_state == "PLAY")
	{
		if (music.getStatus() == music.Stopped) 
			music.play(); 

		sf::Event event;
		mousePosition = sf::Vector2f(sf::Mouse::getPosition(*_window));

		changeColor();
		if (board.Sprite().getGlobalBounds().contains(mousePosition))
			drawCoin = true;
		else
			drawCoin = false;

		while (_window->pollEvent(event))
		{
			if (text[0].getGlobalBounds().contains(mousePosition) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				restart();
			//back
			else if (text[1].getGlobalBounds().contains(mousePosition) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				*_state = "MENU";
			}
			//ESC - back
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
				*_state = "MENU";
			else if (event.type == sf::Event::Closed)
				*_state = "END";


			if (coin[number].Enable() == true)
			{		
				coin[number].move(board.HolesPosition(), mousePosition);
				
				//Down
				if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left && board.Sprite().getGlobalBounds().contains(mousePosition))
				{
					coin[number].setStopPosition(board.HolesPosition(), logic.TabLogic());

					if (coin[number].StopPosition() != 0)
					{
						coin[number].Fall() = true;
						coin[number].Enable() = false;
					}
				}
			}
		}

		isFalling();

		_window->clear();
		draw();
		_window->display();
	}
}

void Play::createBackground()
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

void Play::loadMusic()
{
	if (!music.openFromFile("data/Berlin_View.ogg"))
		MessageBox(NULL, "Music not found!", "ERROR", NULL);
	return;
}

void Play::loadFont()
{
	if (!font.loadFromFile("data/font.ttf"))
	{
		MessageBox(NULL, "Font not found!", "ERROR", NULL);
		return;
	}
}

void Play::createText()
{
	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(40);
		text[i].setString(str[i]);
		text[i].setOrigin(text[i].getGlobalBounds().width / 2, 0);
		text[i].setPosition(sf::Vector2f(260 + 200 * i, 530));
		text[i].setFillColor(sf::Color(54, 69, 79));
	}
}

void Play::addCoin()
{
	if (number < 41)
	{
		number++;
		coin[number].setProperties(number);
		coin[number].move(board.HolesPosition(), mousePosition);
	}
}

void Play::isFalling()
{
	if (coin[number].Fall() == true)
		coin[number].moveDown();
	else if (coin[number].Fall() == false && coin[number].Enable() == false)
	{
		coin[number].setTabLogicValue(logic.TabLogic());
		check();
	}
}

void Play::check()
{
	if (logic.checkLogic() == 0)
		addCoin();
	else
	{
		endGame();
		dialog.Show() = true;

		if (logic.checkLogic() == 1)
			dialog.Text().setString("The winner is\n   red player");
		else if (logic.checkLogic() == 2)
			dialog.Text().setString("The winner is\n yellow player");
		else if (logic.checkLogic() == 0 && number == 41)
			dialog.Text().setString("Draw");

		dialog.Text().setOrigin(sf::Vector2f(dialog.Text().getGlobalBounds().width / 2, dialog.Text().getGlobalBounds().height / 2));
	}
}

void Play::endGame()
{
	for (int i = 0; i < 42; i++)
		coin[i].Enable() = false;
}

void Play::restart()
{
	dialog.Show() = false;

	logic.restart();

	number = -1;

	for (int i = 0; i < 42; i++)
	{
		coin[i].reset();
		coin[i].create(board.HolesPosition());
	}
		
	addCoin();
}

void Play::changeColor()
{
	for (int i = 0; i < 2; i++)
		if (text[i].getGlobalBounds().contains(mousePosition))
			text[i].setFillColor(sf::Color(30, 144, 255));
		else text[i].setFillColor(sf::Color(54, 69, 79));
}

void Play::draw()
{
	_window->draw(background);

	for (int i = 0; i < 42; i++)
		if (coin[i].Show())
		{
			if(coin[i].Enable() && drawCoin)
				_window->draw(coin[i].Sprite());
			else if(!coin[i].Enable())
				_window->draw(coin[i].Sprite());
		}
			

	_window->draw(board.Sprite());
	
	for (int i = 0; i < 2; i++)
		_window->draw(text[i]);

	if (dialog.Show() == true)
		dialog.draw(*_window);
}