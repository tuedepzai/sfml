#include "Game.h"
#include "Game.h"
#include "Game.h"
#include "sfml.h"

//Funcitons//

void Game::initVariables()
{
	this->window = nullptr;
	this->Points = 0;
	this->enemySpawnTimer = 0.f;
	this->enemySpawnTimerMax = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->PointsPerEnemy = 5;
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
	this->updateMousepos();
	this->updateEnemies();

	//Update mouse pos
	//Relative to the screen
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " "<< sf::Mouse::getPosition().y << '\n';
	//Relative to the winow

	std::cout << "Mouse pos" << this->MouseposWindow.x << " " << this->MouseposWindow.y << '\n';
}

void Game::render()
{
	this->window->clear();
	

	//Draw game objects
	this->renderEnemies();
	this->window->display();
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::updateMousepos()
{
	this->MouseposWindow = sf::Mouse::getPosition(*this->window);
	this->MousePosView = this->window->mapPixelToCoords(this->MouseposWindow);
}

void Game::spawnEnemy()
{
	/*
		@return void

		Spawns enemies and sets their color and pos
		-Sets a random position
		-Sets a random color
		-Adds enemy to the vector
	*/
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);
	this->enemy.setFillColor(sf::Color::Green);

	//spawn the enemy
	this->enemies.emplace_back(this->enemy);
}

void Game::updateEnemies()
{
	/*
		@return void
		spawn enemy 
		make enemy move downward
		remove smth of the edge of the screen
	*/

	//Update the timer for spawning
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
			//spawn enemy and reset the timer!
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else {
			this->enemySpawnTimer += 1.f;
		}
	}

	for (int i = 0; i< this->enemies.size(); ++i)
	{
		

		this->enemies[i].move(0.f, 1.f);
		
		bool deleted = false;
		//Checked if clicked
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (this->enemies[i].getGlobalBounds().contains(this->MousePosView)) {
				this->LoadAndPlaySound("C:/Users/doget/source/repos/sfml/sfml/Assets/click.wav");
				++this->Points;
				deleted = true;
			}
		}

		if (this->enemies[i].getPosition().y > this->window->getSize().y) {
			deleted = true;
		}

		if(deleted) this->enemies.erase(this->enemies.begin() + i);

	}
}

void Game::renderEnemies()
{
	for (auto &enemy : this->enemies)
	{
		this->window->draw(enemy);
	}
}

sf::SoundBuffer soundBuffer;
sf::Sound sound;
void Game::LoadAndPlaySound(std::string FilePath) {
	if (!soundBuffer.loadFromFile(FilePath)) {
		std::cout << "Error loading sound file from: " << FilePath << std::endl;
		return;
	}

	// Set the sound buffer and play the sound
	sound.setBuffer(soundBuffer);
	sound.setVolume(100);
	sound.play();
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



