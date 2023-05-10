#pragma once
#include "Libs.h"
#include "Animator.h"

class Enemy
{

public:

	Enemy();
	sf::Sprite get_enemy_sprite() const;
	void spawn(float spawn_x,float spawn_y);
	void update(sf::Time deltaTime);


private:
	sf::Sprite enemy_sprite;
	Animator enemy_anim = Animator(enemy_sprite);


	sf::Vector2f enemy_position;


};

