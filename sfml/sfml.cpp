// sfml.cpp : Defines the entry point for the application.
//

#include "sfml.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window!", sf::Style::Default);
	
	sf::Event ev;

	//Game Loop
	while (window.isOpen())
	{
		//Event Polling
		while (window.pollEvent(ev)) {

			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::R);
					window.close();
				break;

			}
		}

		//Update

		//Render
		window.clear(sf::Color(214, 154, 113)); //clear old frame
		window.display(); // tell app that window is done drawing!
		
	}


	return 0;
}
