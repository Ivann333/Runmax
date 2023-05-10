#include "Engine.h"



Engine::Engine()
{
	arr = worldcreate();
	

}


void Engine::input()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
	
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			
			if ((event.key.code == sf::Keyboard::Escape) || (event.type == sf::Event::Closed)) 	window->close();

			if (event.key.code == sf::Keyboard::W)
			{
				player.moveUp();
			}

			if (event.key.code == sf::Keyboard::S)
			{
				player.moveDown();
			}

			if (event.key.code == sf::Keyboard::A)
			{
				player.moveLeft();
			}


			if (event.key.code == sf::Keyboard::D)
			{
				player.moveRight();
			}

			break;

		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::W) 
			{
				player.setStepy(0);
				player.doNothingAnim();
			}
			if (event.key.code == sf::Keyboard::S)
			{
				player.setStepy(0);
				player.doNothingAnim();
			
			}

			if (event.key.code == sf::Keyboard::A) 
			{
				player.setStepx(0);
				player.doNothingAnim();
				
			}
			if (event.key.code == sf::Keyboard::D)
			{
				player.setStepx(0);
				player.doNothingAnim();

			}

			break;
		default:
			break;
		
		}




	}
}



void Engine::update(sf::Time const& deltaTime)
{
	player.update(deltaTime);
	monster.update(deltaTime);

}


void Engine::draw()
{
	window->clear();


	worldDraw(arr, *window);
	
	window->draw(monster.get_enemy_sprite());
	window->draw(player.get_player_Sprite());

	window->display();



}






void Engine::run()
{
	sf::Clock clock;

	int** arr;
	arr = worldcreate();

	printArray(arr);


	while (window->isOpen())
	{
		
		sf::Time dt = clock.restart();

		input();
		update(dt);
		draw();
	
	}

	
}
