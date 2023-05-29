#pragma once
#include "Libs.h"
#include "Animator.h"

class Enemy
{

public:

	Enemy();
	void spawn(float spawn_x,float spawn_y, int type);
	void update(sf::Time deltaTime, sf::Vector2f playerPosition, sf::Vector2f resolution);
	sf::FloatRect getPosition();
	bool getEnemyAlive();
	void Dead();
	sf::Sprite get_enemy_sprite() const;

private:

	bool enemyUpdateMove;

	const float enemy1_SPEED = 1.0f;
	const float enemy1_HEALTH = 1;

	sf::Time enemyMoveTime;

	sf::Sprite enemy_sprite;

	bool EnemyAlive;

	sf::Vector2f enemy_position;

	Animator enemy_anim = Animator(enemy_sprite);

	int enemy_type;

	float enemy_speed;
	float enemy_health;

};

