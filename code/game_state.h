#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SpaceShip.h"

struct invade_inputs
{
    bool left;
    bool right;
    bool space;
};

struct game_state
{
    bool active;
    invade_inputs input;
    ShaderLoader* shader;
    SpaceShip* ship;

};

#endif