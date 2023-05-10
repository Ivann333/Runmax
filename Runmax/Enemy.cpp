#include "Enemy.h"


Enemy::Enemy()
{
	spawn(30, 30);

	auto& enemy_idle = enemy_anim.CreateAnimation("enemy_idle", "image/f.png", sf::seconds(0.5), true);
	enemy_idle.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(64, 200), 4, 1);


}

void Enemy::spawn(float spawn_x, float spawn_y)
{
	enemy_anim.SwitchAnimation("enemy_idle");
	enemy_position.x = spawn_x;
	enemy_position.y = spawn_y;

	enemy_sprite.setPosition(enemy_position);


}


void Enemy::update(sf::Time deltaTime)
{

	enemy_anim.Update(deltaTime);


}

sf::Sprite Enemy::get_enemy_sprite() const
{
	return enemy_sprite;
}