#pragma once
#include "Engine.h"
#include "Creater.h"


Engine::Engine()
{
	arr = worldcreate();
	worldsize = getWorldSize();
	for (int i = 0; i<5;i++)
		bullet.emplace_back();
	numMonster = 5;
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
				player.get_player_Sprite().setRotation(0);
			}

			if (event.key.code == sf::Keyboard::Right)
			{
				window->setView(mainView);
				mainView.move(20.f, 0);
			}

			if (event.key.code == sf::Keyboard::Left)
			{
				window->setView(mainView);
				mainView.move(-20.f, 0);
			}
			if (event.key.code == sf::Keyboard::Up)
			{
				window->setView(mainView);
				mainView.move(0, -20.f);
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				window->setView(mainView);
				mainView.move(0, 20.f);
			}
			if (event.key.code == sf::Keyboard::Space)
			{

				bulletnum++;
				player.shootAnim();
				bullet[bulletnum].shoot(player.get_player_Sprite().getPosition().x, player.get_player_Sprite().getPosition().y, player.getPlayerRotation());
				


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
	for (int i = 0; i < monster.size(); i++)
	{
		monster[i].update(deltaTime);
	}

	for (int i=0; i < 5;i++)
	{
		if (bullet[i].get_fly())
			bullet[i].update(deltaTime);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < numMonster; j++)
		{
			if (bullet[i].get_fly() && monster[j].getEnemyAlive())
			{
				if (bullet[i].getPosition().intersects
				(monster[j].getPosition()))
				{
					
					bullet[i].stop();
					monster[j].Dead();
				
				}
			}
		}
	}

}


void Engine::draw()
{
	window->clear();
	window->setView(mainView);
	
	worldDraw(arr, *window);

	window->draw(player.get_player_Sprite());

	for (int i = 0; i < monster.size(); i++) {
		if(monster[i].getEnemyAlive()) window->draw(monster[i].get_enemy_sprite());
	}
	for (int i=0; i < 5;i++)
	{
		if (bullet[i].get_fly())
		{
			window->draw(bullet[i].get_bullet_Sprite());
		}

	}

	window->display();



}






void Engine::run()
{
	sf::Clock clock;

	int** arr;
	arr = worldcreate();

	printArray(arr);
	
	createHorde(numMonster, monster, worldsize, sf::Vector2i(0, 1));


	while (window->isOpen())
	{
		
		sf::Time dt = clock.restart();

		input();
		update(dt);
		draw();
	
	}

	
}
