#pragma once
#include "Libs.h"
#include "Animator.h"
#include "WorldCreater.h"


class Player
{
public:
	 Player();
	 sf::Sprite get_player_Sprite() const;
	 void update(sf::Time deltaTime);
	 void spawn(int x, int y);


	 void moveLeft();
	 void moveRight();
	 void moveUp();
	 void moveDown();

	 bool getShooting() const;

	 void doNothingAnim();

	 void setStepx(float x);
	 void setStepy(float y);

	 float getStepX() const;
	 float getStepY() const;



	 void shootAnim();
		 
	 float getPlayerRotation();

	 sf::Vector2f getPosition() const;

private:

	

	bool shooting;

	float rotation;

	const int k_health = 100;

	sf::Vector2f player_position;

	sf::Sprite player_sprite;
	sf::Time time_moving;


	Animator player_anim = Animator(player_sprite);

	float stepx = 0.0f;      
	float stepy = 0.0f;

	float player_rotateX;
	float player_rotateY;
	
	
};

