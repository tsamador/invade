#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"

struct SpaceShip : Entity
{
    SpaceShip()
    {
        alive = true;
        yOffset = -0.8f;
        xOffset = 0.0f;

    }
};
#endif
