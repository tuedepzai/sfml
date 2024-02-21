#include "sfml.h"

//Funcitons//

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 400;
	this->window = new sf::RenderWindow(this->videoMode, "My Window!", sf::Style::Default);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;

}

//Accessors

void Game::update()
{
	this->PollEvent();
}

void Game::render()
{
	this->window->clear(sf::Color::Black);
	

	//Draw game objects

	this->window->display();
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::PollEvent()
{
	while (this->window->pollEvent(ev)) {

		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::R)
				this->window->close();
			break;

		}
	}
}



