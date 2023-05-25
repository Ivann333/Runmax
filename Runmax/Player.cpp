#include "Player.h"


Player::Player()
{


	spawn(3520, 1500);

	auto& HeroIdle = player_anim.CreateAnimation("HeroIdle", "image/HeroIdleSprite.png", sf::seconds(0.5), true);
	HeroIdle.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(64, 100), 4, 1);


	auto& HeroRun = player_anim.CreateAnimation("HeroRun", "image/HeroRunSprite.png", sf::seconds(0.5), true);
	HeroRun.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(64, 100), 4, 1);
	
	auto& HeroAttack = player_anim.CreateAnimation("HeroAttack", "image/HeroAttack2Sprite.png", sf::seconds(0.7), false);
	HeroAttack.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(93, 100), 5, 1);

	player_anim.Update(sf::seconds(0)); 
	player_sprite.setOrigin(player_sprite.getGlobalBounds().width / 2, player_sprite.getGlobalBounds().height / 2);



	rotation = 0;
	shooting = false;
}


sf::Vector2f Player::getCenter() const
{
	return player_position;
}

sf::Sprite Player::get_player_Sprite() const
{
	return player_sprite;
}

void Player::spawn(int x, int y)
{

	doNothingAnim();
	player_position.x = static_cast<float>(x/ 2);
	player_position.y = static_cast<float>(y/2);

	player_sprite.setPosition(player_position);


}

void Player::update(sf::Time deltaTime)
{
	time_moving += deltaTime;

	player_anim.Update(deltaTime);

	player_sprite.move(stepx, stepy);

}

bool Player::getShooting() const
{
	return shooting;
}

void Player::shootAnim()
{

	shooting = true;
	player_anim.SwitchAnimation("HeroAttack");
	
	
	
}


float Player::getPlayerRotation()
{
	return rotation;
}




void Player::moveLeft()
{
	
	stepx = -5.0f;
	if (player_anim.GetCurrentAnimationName() != "HeroRun") player_anim.SwitchAnimation("HeroRun");
	player_sprite.setScale(-1.f, 1.f);
	rotation = 180;
}
void Player::moveRight()
{
	stepx = 5.0f;
	if (player_anim.GetCurrentAnimationName() != "HeroRun") player_anim.SwitchAnimation("HeroRun");
	player_sprite.setScale(1.f, 1.f);
	rotation = 0;
}
void Player::moveUp()
{

	stepy = -5.0f;
	if (player_anim.GetCurrentAnimationName() != "HeroRun") player_anim.SwitchAnimation("HeroRun");
	
}
void Player::moveDown()
{
	stepy = 5.0f;
	if (player_anim.GetCurrentAnimationName() != "HeroRun") player_anim.SwitchAnimation("HeroRun");
	
}




void Player::setStepx(float x)
{
	stepx = x;
}


void Player::setStepy(float y)
{
	stepy = y;
}

void Player::doNothingAnim()
{
	if (player_anim.GetCurrentAnimationName() != "HeroIdle") player_anim.SwitchAnimation("HeroIdle");
}