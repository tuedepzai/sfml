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
	this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	this->enemy.setPosition(sf::Vector2f(10.f, 20.f));
	this->enemy.setSize(sf::Vector2f(30.f, 30.f));
	this->enemy.setFillColor(sf::Color::Cyan);;
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;

}

//Accessors

void Game::update()
{
	this->PollEvent();

	//Update mouse pos
	//Relative to the screen
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " "<< sf::Mouse::getPosition().y << '\n';
	//Relative to the winow
	std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << '\n';
}

void Game::render()
{
	this->window->clear();
	

	//Draw game objects
	this->window->draw(this->enemy);
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



