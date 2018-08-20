#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <list>
#include "SimHead.hpp"
#include "Life.hpp"
#include "World.hpp"

typedef struct Tile {
    unsigned char food_available; // how much food is there

} Tile;

void genWorld(std::list<Food>& FoodInWorld);
void genFauna(std::list<Life>& Fauna);
void processInput(sf::RenderWindow& window);
void update(sf::RenderWindow& window, std::list<Food>& FoodInWorld, std::list<Life>& Fauna);

int main()
{
    std::list<Food> FoodInWorld;
    std::list<Life> Fauna;
    srand(time(NULL));   // should only be called once

    sf::RenderWindow window(sf::VideoMode(800, 800), "Life!");

    genWorld(FoodInWorld);
    genFauna(Fauna);

    while (window.isOpen())
    {
        processInput(window);
        update(window, FoodInWorld, Fauna);
        window.display(); // render
    }

    return 0;
}

void genWorld(std::list<Food>& FoodInWorld)
{
    int foodCount = 50 + (rand() % 20);
    for(int i = 0; i < foodCount; i++)
    {
        Food foodPile;
        FoodInWorld.push_back(foodPile);
    }
}

void genFauna(std::list<Life>& Fauna)
{
    //std::list<Life>::iterator it;
	//for (it = Fauna.begin(); it != Fauna.end(); it++)

	for(int i = 0; i < INIT_LIFE_NUM; i++)
	{
	    Life baby;
		Fauna.push_back(baby);
	}
}

void processInput(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void update(sf::RenderWindow& window, std::list<Food>& FoodInWorld, std::list<Life>& Fauna)
{
    window.clear();

    // Draw World
    std::list<Food>::iterator foodIt;
    sf::CircleShape foodPileImg(7);
    foodPileImg.setFillColor(sf::Color::Yellow);

    for(foodIt = FoodInWorld.begin(); foodIt != FoodInWorld.end(); foodIt++)
    {
        foodPileImg.setPosition(foodIt->position_x, foodIt->position_y);
        window.draw(foodPileImg);
    }

    // Draw Life
    std::list<Life>::iterator it;
    sf::CircleShape life_Shape(15); // represent the life entity on the gui
    life_Shape.setFillColor(sf::Color::Green);

    for(it = Fauna.begin(); it != Fauna.end(); it++)
    {
        it->interact_world();
        life_Shape.setPosition(it->position_x, it->position_y); // Map actual life entity to gui
        window.draw(life_Shape);
    }
}
