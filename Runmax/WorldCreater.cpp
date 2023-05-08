#include "WorldCreater.h"
#include "Engine.h"


std::random_device rd;
std::mt19937 gen(rd());


const int w = 100; // world width
const int h = 50; // world height 

sf::Texture maptexture;
sf::Sprite world;

int** worldcreate()
{


	int** worldsetup = new int* [h]; //is a pointer to a pointer to a object of type int


	for (int i = 0; i < h; ++i) 
	{
		worldsetup[i] = new int[w];

		for (int b = 0; b < w; ++b)
		{
			if (i == 0 or i == (h-1) or b == 0 or b == (w-1))
			{
				worldsetup[i][b] = 0;
			}
			else
			{
				worldsetup[i][b] = 1;
			}
			


		}
	}
	return worldsetup;
}

sf::Sprite& getSprite()
{
	return world;
}



int worldDraw(int** arr, sf::RenderWindow& window)
{


	maptexture.loadFromFile("image/bg.png");
	world.setTexture(maptexture);

	for (int i = 0; i < h; i++)
	{
		for (int b = 0; b < w; b++)
		{
			

			if (arr[i][b] == 0) world.setTextureRect(sf::IntRect(160, 0, 32, 32));
			if (arr[i][b] == 1) world.setTextureRect(sf::IntRect(0, 0, 32, 32));
			world.setPosition(b * 32, i * 32);
			
			window.draw(world);

		}


	}
	return 0;

}

void printArray(int** arr)
{
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


