#include "Enemy.h"


Enemy::Enemy()
{


	auto& enemy1 = enemy_anim.CreateAnimation("enemy1", "image/Enemy1Sprite.png", sf::seconds(0.5), true);
	enemy1.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(52, 100), 4, 1);

	auto& enemy2 = enemy_anim.CreateAnimation("enemy2", "image/Enemy2Sptire.png", sf::seconds(0.5), true);
	enemy2.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(116, 200), 4, 1);

	auto& enemy2death = enemy_anim.CreateAnimation("enemy2death", "image/EnemyDeathSprite.png", sf::seconds(1), false);
	enemy2death.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(132, 200),8, 1);

	auto& enemy1death = enemy_anim.CreateAnimation("enemy1death", "image/Enemy2DeathSprite.png", sf::seconds(1), false);
	enemy1death.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(40, 100), 4, 1);

	EnemyAlive = false;
	enemyUpdateMove = true;
}

bool Enemy::getEnemyAlive()
{
	return EnemyAlive;
		
}

void Enemy::spawn(float spawn_x, float spawn_y, int type)
{
	EnemyAlive = true;

	enemy_type = type;
	switch (type)
	{
	case 0:
		enemy_anim.SwitchAnimation("enemy1");
		enemy_speed = enemy1_SPEED;
		enemy_health = enemy1_HEALTH;
		break;

	case 1:
		enemy_anim.SwitchAnimation("enemy2");
		enemy_speed = enemy1_SPEED;
		enemy_health = enemy1_HEALTH;
		break;
	}


	enemy_position.x = spawn_x;
	enemy_position.y = spawn_y;
	enemy_sprite.setOrigin(25, 25);
	enemy_sprite.setPosition(enemy_position);


}

void Enemy::Dead() {
	

	switch (enemy_type)
	{
	case 0: enemy_anim.SwitchAnimation("enemy1death");break;
	case 1: enemy_anim.SwitchAnimation("enemy2death");break;
	}
	enemyUpdateMove = false;
}

sf::FloatRect Enemy::getPosition()
{
	auto myGlobalBounds = sf::FloatRect(enemy_sprite.getGlobalBounds().left + 40, enemy_sprite.getGlobalBounds().top + 40,
		enemy_sprite.getGlobalBounds().width - 80, enemy_sprite.getGlobalBounds().height - 80);

	return myGlobalBounds;
}

sf::Sprite Enemy::get_enemy_sprite() const
{
	return enemy_sprite;
}



void Enemy::update(sf::Time deltaTime, sf::Vector2f playerPosition, sf::Vector2f resolution)
{

	enemy_anim.Update(deltaTime);

	if (enemy_anim.getEndAnim())
	{
		EnemyAlive = false;
	}

	enemyMoveTime += deltaTime;

	if (enemyUpdateMove){
		if (enemyMoveTime > sf::microseconds(1000)) {
			float playerX = playerPosition.x;
			float playerY = playerPosition.y;
			enemyMoveTime = sf::microseconds(0);

			if (playerX > enemy_position.x)
			{
				enemy_position.x = enemy_position.x + enemy1_SPEED;
			}
			if (playerY > enemy_position.y)
			{
				enemy_position.y = enemy_position.y + enemy1_SPEED / (100 / (resolution.y / (resolution.x / 100)));

			}
			if (playerX < enemy_position.x)
			{
				enemy_position.x = enemy_position.x - enemy1_SPEED;

			}
			if (playerY < enemy_position.y)
			{
				enemy_position.y = enemy_position.y - enemy1_SPEED / (100 / (resolution.y / (resolution.x / 100)));

			}

			enemy_sprite.setPosition(enemy_position);

			auto angle = static_cast<float>((atan2(playerY - enemy_position.y, playerX - enemy_position.x) * 180) / 3.141);
			if (angle >= 90 and angle <= 270) enemy_sprite.setScale(-1.f, 1.f);
			else enemy_sprite.setScale(1.f, 1.f);
		}
	}
}

