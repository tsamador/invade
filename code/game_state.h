#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SpaceShip.h"
#include "Enemy.h"
#include "invade_inputs.h"

//TODO(Tanner): May want to rethink how this is defined or gets passed in.
const int NumberOfEnemies = 10; 

struct game_state
{
    bool active;
    invade_inputs input;
    ShaderLoader* shader;
    SpaceShip* ship;
    Enemy enemies[NumberOfEnemies];
    int EnemyVAO;

};

#endif