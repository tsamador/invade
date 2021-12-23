#ifndef INVADE_H
#define INVADE_H

#include "gl_invade.h"
#include "game_state.h"

void InvadeMainLoop();
void InitGameState();
void UpdateEntities(game_state* gameState);

#endif