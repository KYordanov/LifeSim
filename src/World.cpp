#include <stdlib.h>
#include "World.hpp"
#include "SimHead.hpp"

float rollFoodPerTile(void);

Food::Food()
{
    position_x = rand() % WORLD_SIZE;
    position_y = rand() % WORLD_SIZE;
    avaibleFood = rollFoodPerTile();
}

float rollFoodPerTile(void)
{
    unsigned char chance = rand() % 100;
    if(MORE_FOOD_CHANCE > chance)
    {
        return (float)2 + ((rand() % 5) * 0.1);
    } else if(FOOD_CHANCE > chance)
    {
        return (float)(rand() % 5) * 0.1;
    } else
    {
        return 0;
    }
}
