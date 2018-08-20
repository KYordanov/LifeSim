#include <stdlib.h>
#include "SimHead.hpp"
#include <iostream>
#include <queue>
#include <functional>

class Life {
    std::queue<std::function<void()>> desires; // stores/prioritize actions to be done
    unsigned char energy; // how much energy the organism have
    //float speed; //
    float energy_consumption; // per movement
    unsigned char smell_radius;

    void sense_world();
    void smell();

    void act();
    void approach(int app_pos_x, int app_pos_y);
    void move_away(int away_pos_x, int away_pos_y);

public:
    int position_x;
    int position_y;
    int orientation;
    int field_of_vision;
    int view_distance;
    Life(); // Constructor
    void interact_world();
};
