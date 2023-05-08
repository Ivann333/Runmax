#pragma once
#include "Libs.h"
#include "Animator.h"

class Player
{
public:
	 Player();
	 sf::Sprite get_player_Sprite() const;
	 void update(sf::Time deltaTime);
	 void spawn();


	 void moveLeft();
	 void moveRight();
	 void moveUp();
	 void moveDown();


	 void doNothingAnim();


	 void setStepx(float x);
	 void setStepy(float y);


private:
	const int k_health = 100;
	const int k_speed = 2;

	sf::Vector2f player_position;

	sf::Sprite player_sprite;
	sf::Time time_moving;

	Animator player_anim = Animator(player_sprite);

	float stepx = 0.0f;      
	float stepy = 0.0f;

	
	
};

