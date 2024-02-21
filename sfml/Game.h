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

	void initVariables();
	void initWindow();

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
	


};