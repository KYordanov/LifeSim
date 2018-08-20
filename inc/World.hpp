
class PhysicalEntity { // have world coordinates

public:
    int position_x;
    int position_y;
};

class Food : public PhysicalEntity { // have world coordinates

public:
    float avaibleFood;
    Food();
};
