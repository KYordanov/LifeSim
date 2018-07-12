#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <list>
#include "../inc/Life.hpp"
#include "../inc/SimHead.hpp"

typedef struct Tile {
    unsigned char food_available; // how much food is there

} Tile;

void init(void);
void genWorld(Tile world[][WORLD_SIZE]);
void genFauna(std::list<Life>& Fauna);
void showWorld(Tile world[][WORLD_SIZE]);
unsigned char rollFoodPerTile(void);
void processInput(sf::RenderWindow& window);
void update(sf::RenderWindow& window, Tile world[][WORLD_SIZE], std::list<Life>& Fauna);

int main()
{
    Tile world[WORLD_SIZE][WORLD_SIZE] = {0};
    std::list<Life> Fauna;
    srand(time(NULL));   // should only be called once

    sf::RenderWindow window(sf::VideoMode(800, 800), "Life!");

    genWorld(world);
    genFauna(Fauna);

    while (window.isOpen())
    {
        processInput(window);
        update(window, world, Fauna);
        window.display(); // render
    }

    return 0;
}

void init(void)
{

}

void genWorld(Tile world[][WORLD_SIZE])
{
    for(int i = 0; i < WORLD_SIZE; i++)
    {
        for(int j = 0; j < WORLD_SIZE; j++)
        {
            world[i][j].food_available = rollFoodPerTile();
        }
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

unsigned char rollFoodPerTile(void)
{
    unsigned char chance = rand() % 100;
    if(MORE_FOOD_CHANCE > chance)
    {
        return (unsigned char)2;
    } else if(FOOD_CHANCE > chance)
    {
        return (unsigned char)1;
    } else
    {
        return 0;
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

void update(sf::RenderWindow& window, Tile world[][WORLD_SIZE], std::list<Life>& Fauna)
{
    window.clear();

    // Draw World
    sf::RectangleShape shape(sf::Vector2f(40, 40));
    shape.setPosition(0, 0);
    shape.setOutlineThickness(-1);
    shape.setOutlineColor(sf::Color::Black);

    for(int i = 0; i < WORLD_SIZE; i++)
    {
        for(int j = 0; j < WORLD_SIZE; j++)
        {
            shape.setFillColor(sf::Color(150, 50, 100 * world[i][j].food_available));
            window.draw(shape);
            shape.move(sf::Vector2f(40, 0));
        }
        shape.move(sf::Vector2f(-800, 40));
    }

    // Draw Life
    std::list<Life>::iterator it;
    sf::CircleShape animal(15);
    animal.setFillColor(sf::Color::Green);

    for(it = Fauna.begin(); it != Fauna.end(); it++)
    {
        animal.setPosition(it->position_x * 40 + 5, it->position_y * 40 + 5);
        window.draw(animal);
    }

    //showWorld(world);
}
