#include "Bullet.h"

Bullet::Bullet()
{

	auto& bulletRight = bullet_anim.CreateAnimation("bulletRight", "image/bulletright.png", sf::seconds(1), true);
	bulletRight.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(79, 200), 4, 1);

	auto& bulletLeft = bullet_anim.CreateAnimation("bulletLeft", "image/bulletleft.png", sf::seconds(1), true);
	bulletLeft.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(79, 200), 4, 1);

}

void Bullet::shoot(float start_x, float start_y, float bulletRotatex, float bulletRotatey)
{

	bullet_position.x = start_x;
	bullet_position.y = start_y;
	bullet_sprite.setPosition(bullet_position);
	
	if (bulletRotatex < 0) {
		
		if (bullet_anim.GetCurrentAnimationName() != "bulletLeft") bullet_anim.SwitchAnimation("bulletLeft");
		bullet_stepx = -7.0f;
	}
		
	if (bulletRotatex > 0) {
	
		if (bullet_anim.GetCurrentAnimationName() != "bulletRight") bullet_anim.SwitchAnimation("bulletRight");
		bullet_stepx = 7.0f;
	}
		
	if (bulletRotatey > 0)
		bullet_stepy = -7.0f;
	if (bulletRotatey < 0)
		bullet_stepy = 7.0f;
	if (bulletRotatey == 0)
		bullet_stepy = 0;

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