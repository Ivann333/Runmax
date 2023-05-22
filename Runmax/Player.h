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


	 void doNothingAnim(int status);

	 void setPlayerRotateX(float x);
	 void setPlayerRotateY(float y);

	 float getPlayerRotateX()const;
	 float getPlayerRotateY()const;


	 void setStepx(float x);
	 void setStepy(float y);

	 sf::Vector2f getCenter() const;

private:
	const int k_health = 100;
	const int k_speed = 2;

	sf::Vector2f player_position;

	sf::Sprite player_sprite;
	sf::Time time_moving;


	Animator player_anim = Animator(player_sprite);

	float stepx = 0.0f;      
	float stepy = 0.0f;

	float player_rotateX;
	float player_rotateY;
	
	
};

