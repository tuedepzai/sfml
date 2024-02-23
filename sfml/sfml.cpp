// sfml.cpp : Defines the entry point for the application.
//

#include "sfml.h"

int main()
{
	//random
	srand(static_cast<unsigned>(time(NULL)));

	Game game;
	//Game Loop
	while (game.running() && !game.getEndGame()) {
		{
			//Update
			game.update();
			//Render
			game.render();
		}
	}
	return 0;
}
