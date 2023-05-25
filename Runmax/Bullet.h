#pragma once
#include "Libs.h"
#include "Animator.h"
class Bullet
{
public:
	Bullet();
	void update(sf::Time deltaTime);
	void shoot(float start_x, float start_y, int rotation);
	sf::Sprite get_bullet_Sprite() const;
	bool get_fly() const;
	void bullet_setStepx(float x);
	void bullet_setStepy(float y);
	sf::FloatRect getPosition();
	void stop();

private:

	float bullet_stepx = 0.0f;
	float bullet_stepy = 0.0f;

	sf::Vector2f bullet_position;
	bool bulletInFlight = false;
	float bulletSpeed = 1000;
	sf::Sprite bullet_sprite;
	Animator bullet_anim = Animator(bullet_sprite);

};

