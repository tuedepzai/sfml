#pragma once
#include "sfml.h"
/*
* Class act as the game engine btw
* 
*/

class Game {
private:
	//Vars
	int Points;
	int PointsPerEnemy;
	bool MouseHeld;
	int Health;
	bool endGame;

	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;

	
	//Game objects
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;

	sf::Vector2i MouseposWindow;
	sf::Vector2f MousePosView;

	sf::Text UiText;
	//Game logic
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Sound stuff


	void initVariables();
	void initWindow();
	void initEnemies();
	void initText();

public:
	//Constructors / Destrustors
	Game();
	virtual ~Game();

	//Access
	const bool running() const;
	void PollEvent();

	const bool getEndGame() const;

	//Assets
	sf::Font font;

	//Functions
	void update();
	void render();

	void spawnEnemy();
	void updateEnemies();
	void renderEnemies(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void updateText();
	void initFonts();

	void updateMousepos();

	void LoadAndPlaySound(std::string FilePath);


};