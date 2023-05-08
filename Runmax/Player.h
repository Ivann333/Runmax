#pragma once
#include "Libs.h"
#include "Animator.h"

class Player
{
public:
	 Player();



private:
	const int k_health = 100;
	const int k_speed = 2;
	sf::Sprite player_sprite;

	Animator player_anim = Animator(player_sprite);


};

