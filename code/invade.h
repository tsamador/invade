#ifndef INVADE_H
#define INVADE_H

#include "gl_invade.h"
#include "game_state.h"
#include "Direction.h"
#include "Enemy.h"


void InvadeMainLoop();
void InitGameState();
void UpdateEntities(game_state* gameState);
static SpaceShip* InitSpaceShip();
static void InitEnemyShips();

#endif