#pragma once
#include"Libs.h"
#include "Enemy.h"
#include "Bullet.h"

void createHorde(int numMonster, std::deque<Enemy>& monster, sf::IntRect arena, sf::Vector2i monstertype);
void createBullet(int numbullet, std::deque<Bullet>& bullets, sf::Vector2f playerPosition);