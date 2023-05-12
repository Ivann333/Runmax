#include "Creater.h"


void createHorde(int numMonster, std::deque<Enemy>& monster, sf::IntRect arena,sf::Vector2i monstertype)
{

	std::random_device rd;

	std::mt19937 gen(rd());

	for (int i = 0; i < numMonster; i++)
	{
		monster.emplace_back();
	}

	

	auto max = sf::Vector2i(arena.width - 100, arena.height - 100);
	auto min = sf::Vector2i(arena.left + 100, arena.top + 100);
	std::uniform_int_distribution<> rLR(min.x, max.x);
	std::uniform_int_distribution<> rTB(min.y, max.y);


	std::uniform_int_distribution<> rtype(monstertype.x, monstertype.y);

	bool collis;

	for (int i = 0; i < numMonster; i++) {
		auto type = rtype(gen);
		do {

			sf::Vector2f pos;
			collis = false;
			pos.x = static_cast<float>(rLR(gen));
			pos.y = static_cast<float>(rTB(gen));
			monster[i].spawn(pos.x, pos.y, type);


			for (int j = 0; j < i; j++)
			{
				if (monster[i].getPosition().intersects(monster[j].getPosition())) collis = true;
			}
		} while (collis);

	}

}

void createBullet(int numbullet, std::deque<Bullet>& bullets, sf::Vector2f playerPosition)
{
	for (int i = 0; i < numbullet; i++)
	{
		bullets.emplace_back();
	}




}