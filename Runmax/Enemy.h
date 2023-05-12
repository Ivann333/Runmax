#pragma once
#include "Libs.h"
#include "Animator.h"

class Enemy
{

public:

	Enemy();
	sf::Sprite get_enemy_sprite() const;
	void spawn(float spawn_x,float spawn_y, int type);
	void update(sf::Time deltaTime);
	sf::FloatRect getPosition();

private:
	const float enemy1_SPEED = 1.0f;
	const float enemy1_HEALTH = 1;

	sf::Sprite enemy_sprite;

	sf::Vector2f enemy_position;

	Animator enemy_anim = Animator(enemy_sprite);

	int enemy_type;

	float enemy_speed;
	float enemy_health;

};

