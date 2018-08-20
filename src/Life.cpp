#include "Life.hpp"

Life::Life()
{
	energy = 4;
	energy_consumption = (10 + (rand() % 5)) * 0.01; //
	position_x = rand() % WORLD_SIZE;
	position_y = rand() % WORLD_SIZE;
}

void Life::interact_world()
{
    sense_world();
    act();
}

void Life::sense_world()
{
    smell();
}

void Life::smell()
{
    int target_x = 4, target_y = 5;
    desires.push([=]{this->approach(target_x, target_y);});
}

void Life::act()
{
    desires.front()();
    desires.pop();
}

void Life::approach(int app_pos_x, int app_pos_y)
{
    std::cout << "execute approach " << app_pos_x << ", " << app_pos_y << std::endl;
}

void Life::move_away(int away_pos_x, int away_pos_y)
{

}
