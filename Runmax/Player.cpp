#include "Player.h"


Player::Player()
{
	auto& idleForward = player_anim.CreateAnimation("idleForward", "graphics/player.png", sf::seconds(0.5), true);
	idleForward.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(135, 105), 4, 1);


}
