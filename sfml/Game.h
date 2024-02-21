#pragma once
#include "sfml.h"
/*
* Class act as the game engine btw
* 
*/

class Game {
private:
	//Vars
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	
	//Game objects
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;

	sf::Vector2i MouseposWindow;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;



	void initVariables();
	void initWindow();
	void initEnemies();

public:
	//Constructors / Destrustors
	Game();
	virtual ~Game();

	//Access
	const bool running() const;
	void PollEvent();

	//Functions
	void update();
	void render();

	void spawnEnemy();
	void updateEnemies();
	void renderEnemies();


	void updateMousepos();


};