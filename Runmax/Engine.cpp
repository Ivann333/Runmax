#include "Engine.h"



Engine::Engine()
{

	

}


void Engine::input()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		if ((event.key.code == sf::Keyboard::Escape) || (event.type == sf::Event::Closed)) 	window->close();

	}
}


void Engine::draw()
{
	window->clear();

	int** arr;
	arr = worldcreate();
	worldDraw(arr, *window);
	

	window->display();



}






void Engine::run()
{
	sf::Clock clock;

	std::cout << "a";


	int** arr;
	arr = worldcreate();

	printArray(arr);


	while (window->isOpen())
	{
		
		sf::Time dt = clock.restart();

		input();
		draw();
	
	}

	
}
