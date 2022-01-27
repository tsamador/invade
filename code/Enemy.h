
#ifndef INVADE_ENEMY_H
#define INVADE_ENEMY_H

#include "Entity.h"

enum Direction {
        LEFT,
        RIGHT
};


//TODO(Tanner): I kind of feel like i want to rework this entire enemy system :(
struct Enemy : Entity {
    static Direction direction;
    void SetLocation(float x, float y);
    bool Update(); 
};

struct EnemyArray {
    const int NUM_ENEMIES = 10;
    Enemy enemies[10];
    void UpdateAll();

};
#endif