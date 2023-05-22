#include "Player.h"


Player::Player()
{


	spawn(3520, 1500);

	auto& idleright = player_anim.CreateAnimation("idleright", "image/idle.png", sf::seconds(0.5), true);
	idleright.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(64, 200), 4, 1);

	auto& idleleft = player_anim.CreateAnimation("idleleft", "image/idleleft.png", sf::seconds(0.5), true);
	idleleft.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(64, 200), 4, 1);


	auto& runRight = player_anim.CreateAnimation("runRight", "image/spriteRunRight.png", sf::seconds(0.5), true);
	runRight.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(64, 200), 4, 1);

	auto& runLeft = player_anim.CreateAnimation("runLeft", "image/spriteRunLeft.png", sf::seconds(0.5), true);
	runLeft.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(64, 200), 4, 1);

	
	player_anim.Update(sf::seconds(0)); 
	
}

void Player::setPlayerRotateX(float x)
{
	player_rotateX = x;
}
void Player::setPlayerRotateY(float y)
{
	player_rotateY = y;
}



float Player::getPlayerRotateX() const
{
	return player_rotateX;

}

float Player::getPlayerRotateY() const
{
	return player_rotateY;

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

	doNothingAnim(1);
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



void Player::moveLeft()
{
	
	stepx = -5.0f;
	if (player_anim.GetCurrentAnimationName() != "runLeft") player_anim.SwitchAnimation("runLeft");

}
void Player::moveRight()
{
	
	stepx = 5.0f;
	if (player_anim.GetCurrentAnimationName() != "runRight") player_anim.SwitchAnimation("runRight");
}
void Player::moveUp()
{

	stepy = -5.0f;
	if (player_anim.GetCurrentAnimationName() != "runLeft") player_anim.SwitchAnimation("runLeft");
	
}
void Player::moveDown()
{
	stepy = 5.0f;
	if (player_anim.GetCurrentAnimationName() != "runRight") player_anim.SwitchAnimation("runRight");
	
}


void Player::setStepx(float x)
{
	stepx = x;
}


void Player::setStepy(float y)
{
	stepy = y;
}

void Player::doNothingAnim(int status)
{
	switch (status)
	{
	case 1: player_anim.SwitchAnimation("idleright"); break;
	case 2: player_anim.SwitchAnimation("idleleft"); break;
	}
	

}