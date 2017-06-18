#include "GameStatePlay.h"
#include "GameState.h"

GameStatePlay::GameStatePlay(Game * game)
{
	this->game = game;
	coin = new Coin(Data::redCoin);
	createButtons();
}

void GameStatePlay::draw()
{
	game->window.clear(sf::Color::Black);
	game->window.draw(Data::background);
	game->window.draw(board);

	if (coin != nullptr)
	{
		game->window.draw(*coin);
	}

	for (auto &button : buttons)
		game->window.draw(button);

	if (dialog != nullptr)
		game->window.draw(*dialog);

	game->window.display();
}

void GameStatePlay::update()
{
	for (auto &button : buttons)
		button.update(game->mousePosition);
}

void GameStatePlay::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				game->popState();
				return;
			}
			else if (event.key.code == sf::Keyboard::Right && coin != nullptr)
			{
				coin->moveRight();
			}
			else if (event.key.code == sf::Keyboard::Left && coin != nullptr)
			{
				coin->moveLeft();
			}
			else if (event.key.code == sf::Keyboard::Down && coin != nullptr)
			{
				if (board.pushCoin(coin))
				{
					logic.checkLogic(board.getCoins());
					logic.changeTurn();

					if (logic.getState() == PLAYING)
					{
						coin = (logic.isRedTurn()) ? new Coin(Data::redCoin) : new Coin(Data::yellowCoin);
					}
					else
					{
						coin = nullptr;

						if (logic.getState() == RED_WIN)
							dialog = new Dialog("The winner is\n   red player");
						else if (logic.getState() == YELLOW_WIN)
							dialog = new Dialog("The winner is\n yellow player");
						else if (logic.getState() == DRAW)
							dialog = new Dialog("Draw");
					}
				}
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (buttons[0].isHover(game->mousePosition))
				{
					game->popState();
					return;
				}
				else if (buttons[1].isHover(game->mousePosition))
				{
					board.reset();
					logic.setGameState(PLAYING);
					coin = (logic.isRedTurn()) ? new Coin(Data::redCoin) : new Coin(Data::yellowCoin);
					Dialog *wsk = dialog;
					dialog = nullptr;
					delete wsk;
				}
			}
		}
		default: break;
		}
	}

	return;
}

void GameStatePlay::createButtons()
{
	buttons[0].setString("Back");
	buttons[1].setString("Play again");

	for (int i = 0; i < 2; i++)
	{
		buttons[i].setFont(Data::font);
		buttons[i].setCharacterSize(40);
		buttons[i].setOrigin(buttons[i].getGlobalBounds().width / 2, 0);
		buttons[i].setPosition(sf::Vector2f(260 + 200 * i, 530));
		buttons[i].setFillColor(Color::LightGrey);
		buttons[i].setHoverColor(Color::Blue);
	}
}
