#include "Bullet.h"

Bullet::Bullet()
{

	auto& enemy_idle = bullet_anim.CreateAnimation("enemy_idle", "image/bullet.png", sf::seconds(0.5), true);
	enemy_idle.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(52, 200), 4, 1);

}

void Bullet::shoot(float start_x, float start_y, float target_x, float target_y)
{


	bulletInFlight = true;
	bullet_position.x = start_x;
	bullet_position.y = start_y;
	bullet_sprite.setPosition(bullet_position);
	

}

void Bullet::spawn(sf::Vector2f playerPosition)
{
	bullet_position= playerPosition;

	bulletInFlight = true;
}

void Bullet::update(float elapsedTime)
{
	


}

void reload(int bullNumb, std::deque<Bullet> bullet)
{
	for (int i = 0; i < bullNumb; i++)
	{
		bullet.emplace_back();
	}


}

bool Bullet::get_fly() const
{
	return bulletInFlight;
}

sf::Sprite Bullet::get_bullet_Sprite() const
{
	return bullet_sprite;
}