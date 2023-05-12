#include "Enemy.h"


Enemy::Enemy()
{


	auto& enemy_idle = enemy_anim.CreateAnimation("enemy_idle", "image/enemy_run_right.png", sf::seconds(0.5), true);
	enemy_idle.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(52, 200), 4, 1);

	auto& enemy_run2 = enemy_anim.CreateAnimation("enemy_run2", "image/enemy_run2.png", sf::seconds(0.5), true);
	enemy_run2.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(79, 200), 4, 1);

}

void Enemy::spawn(float spawn_x, float spawn_y, int type)
{
	
	enemy_type = type;
	switch (type)
	{
	case 0:
		enemy_anim.SwitchAnimation("enemy_idle");
		enemy_speed = enemy1_SPEED;
		enemy_health = enemy1_HEALTH;
		break;

	case 1:
		enemy_anim.SwitchAnimation("enemy_run2");
		enemy_speed = enemy1_SPEED;
		enemy_health = enemy1_HEALTH;
		break;
	}


	enemy_position.x = spawn_x;
	enemy_position.y = spawn_y;
	enemy_sprite.setOrigin(25, 25);
	enemy_sprite.setPosition(enemy_position);


}

sf::FloatRect Enemy::getPosition()
{
	auto myGlobalBounds = sf::FloatRect(enemy_sprite.getGlobalBounds().left + 40, enemy_sprite.getGlobalBounds().top + 40,
		enemy_sprite.getGlobalBounds().width - 80, enemy_sprite.getGlobalBounds().height - 80);

	return myGlobalBounds;
}


void Enemy::update(sf::Time deltaTime)
{

	enemy_anim.Update(deltaTime);


}

sf::Sprite Enemy::get_enemy_sprite() const
{
	return enemy_sprite;
}

