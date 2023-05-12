#pragma once
#include "Libs.h"
#include "Animator.h"
class Bullet
{
public:
	Bullet();
	void update(float elapsedTime);
	void shoot(float start_x, float start_y, float target_x, float target_y);
	sf::Sprite get_bullet_Sprite() const;
	bool get_fly() const;
	void spawn(sf::Vector2f playerPosition);
		
private:


	sf::Vector2f bullet_position;
	bool bulletInFlight;
	float bulletSpeed = 1000;
	sf::Sprite bullet_sprite;
	Animator bullet_anim = Animator(bullet_sprite);

};

