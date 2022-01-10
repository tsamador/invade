
#ifndef INVADE_ENEMY_H
#define INVADE_ENEMY_H

#include "Entity.h"
#include "Direction.h"


struct Enemy : Entity {

    //TODO(Tanner): Why does this being static not work??
    Direction direction;

    Enemy()
    {
        direction = RIGHT;
    }

    void SetLocation(float x, float y)
    {
        xOffset = 0;
        yOffset = 0;
    }

    void Update()
    {

        switch(direction)
        {
            case LEFT: 
            {
                xOffset -= 0.0001f;
            } break;
            case RIGHT:
            {
                xOffset += 0.0001f;
            } break;
        }

        if(xOffset > 0.9f)
        {
            direction = LEFT;
            yOffset += -0.075f;
        }
        else if(xOffset < -0.9f)
        {
            direction = RIGHT;
            yOffset += -0.075f;
        }
    }
};

#endif