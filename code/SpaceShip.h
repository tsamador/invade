#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"
#include "game_state.h"
#include "invade_inputs.h"

#define SPEED 5;

struct Bullet {
    float xOffset;
    float yOffset;
    float radius;
    bool active;
};

struct SpaceShip : Entity
{
    Bullet bullets[2];

    void Init(int screenWidth, int screenHeight)
    {
        size.x = 3.0f;
        size.y = 3.0f;
        size.z = 0.0f;
        pos.x = screenWidth/ 2.0f;
        pos.y = screenHeight - 50;
        pos.z = 0.0f; // 2d game, no need for z coordinate
    }

    void Update(invade_inputs& inputs)
    {
        if(inputs.left)
        {
            if(pos.x > 25) { pos.x -= SPEED;}
        }

        if(inputs.right)
        {
           if(pos.x < 750) { pos.x += SPEED;}
        }

        if(inputs.space)
        {
            inputs.space = false;
            Shoot();    
        }
    }

    void Shoot()
    {
        
        puts("Shoot!");
    }
};

#endif