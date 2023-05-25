#include "Bullet.h"

Bullet::Bullet()
{

	auto& BulletFly = bullet_anim.CreateAnimation("BulletFly", "image/BulletFlightSprite.png", sf::seconds(1), true);
	BulletFly.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(58, 11), 4, 1);

	
}
	
sf::FloatRect Bullet::getPosition()
{
	auto myGlobalBounds = sf::FloatRect(bullet_sprite.getGlobalBounds().left + 40, bullet_sprite.getGlobalBounds().top + 40,
		bullet_sprite.getGlobalBounds().width - 80, bullet_sprite.getGlobalBounds().height - 80);

	return myGlobalBounds;
}
void Bullet::stop()
{
	bulletInFlight = false;
}

void Bullet::shoot(float start_x, float start_y, int rotation)
{

	bullet_position.x = start_x;
	bullet_position.y = start_y;
	
	
	switch (rotation)
	{
	case 0: bullet_sprite.setRotation(0); bullet_stepx = 5.0f; bullet_stepy = 0; break;
	case 180: bullet_sprite.setRotation(0); bullet_sprite.setScale(-1.f, 1.f); bullet_stepx = -5.0f; bullet_stepy = 0;break;
	}

	bullet_sprite.setPosition(bullet_position);
	bulletInFlight = true;

}

void Bullet::update(sf::Time deltaTime)
{
	if (bulletInFlight)
	{
		bullet_sprite.move(bullet_stepx, bullet_stepy);

		bullet_anim.Update(deltaTime);
	}

}

void Bullet::bullet_setStepx(float x)
{
	bullet_stepx = x;
}


void Bullet::bullet_setStepy(float y)
{
	bullet_stepy = y;
}

bool Bullet::get_fly() const
{
	return bulletInFlight;
}

sf::Sprite Bullet::get_bullet_Sprite() const
{
	return bullet_sprite;
}