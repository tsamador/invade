#ifndef INVADE_H
#define INVADE_H

#include "gl_invade.h"
#include "game_state.h"
#include "Enemy.h"
#include <windows.h>
#include <timeapi.h>
#include "invade_types.h"

void InvadeMainLoop();
void InitGameState();
void UpdateEntities(game_state* gameState);
static SpaceShip* InitSpaceShip();
static void InitEnemyShips();
void UpdateGameStateWindow(int width, int height);
static void InitBullets();

#endif