#ifndef GL_INVADE_H
#define GL_INVADE_H

#include "..\lib\glad\glad.h"
#include "..\lib\GLFW\glfw3.h"
#include "ShaderLoader.h"
#include "stb_image.h"
#include "game_state.h"
#include "invade.h"

void Render(game_state* gameState);
void ProcessInput(game_state *gameState);
int CreateVAO(float* vertices, int verticesSize);

#endif
