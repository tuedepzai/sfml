// sfml.cpp : Defines the entry point for the application.
//

#include "sfml.h"

int main()
{
	Game game;
	//Game Loop
	while (game.running()) {
		{
			//Update
			game.update();
			//Render
			game.render();
		}
	}
	return 0;
}
