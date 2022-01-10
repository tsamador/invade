#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"
#include "game_state.h"
#include "invade_inputs.h"

struct SpaceShip : Entity
{
    void Update(invade_inputs inputs)
    {
        if(inputs.left)
        {
            //move left
            if(xOffset > -0.95f)
            {
                xOffset -= 0.001f;
            }
            
        }

        if(inputs.right)
        {
            if(xOffset < 0.95f)
            {
                xOffset += 0.001f;
            }
            
        }

        if(inputs.space)
        {
            Shoot();    
        }
    }

    void Shoot()
    {

    }
};
#endif
