#include <stdlib.h>
#include "../inc/Life.hpp"
#include "../inc/SimHead.hpp"

Life::Life()
{
	energy = 4;
	energy_consumption = (10 + (rand() % 5)) * 0.01;
	position_x = rand() % WORLD_SIZE;
	position_y = rand() % WORLD_SIZE;
	//Fauna.push_back(baby);
}

Life::smell()
{

}
