
#include "invade.h"
#include "gl_invade.h"

game_state gameState;
ShaderLoader shader;

static SpaceShip* InitSpaceShip();

void InvadeMainLoop()
{

    InitGameState();

    while(gameState.active)
    {
        ProcessInput(&gameState);

        UpdateEntities(&gameState);

        Render(&gameState);

    }

}

void InitGameState()
{
    gameState.active = true;
    shader.Init("..\\code\\shader.vs", "..\\code\\shader.fs");
    gameState.shader = &shader;
    gameState.ship = InitSpaceShip();

}

void UpdateEntities(game_state* gameState)
{

}

static SpaceShip* InitSpaceShip()
{
    SpaceShip* ship = (SpaceShip*)malloc(sizeof(SpaceShip));

    float vertices[] =  {
        //Vertices              //Colors            //TODO(Texture Coordinates)
        -0.01f, 0.0f, 0.0f,     0.0f, 0.0f, 1.0f, //bottom left
        0.0f, 0.01f, 0.0f,      0.0f, 0.0f, 1.0f, //Top
        0.01f, 0.0f, 0.0f,      0.0f, 0.0f, 1.0f  //bottom right
    };
    
    ship->VAO = CreateVAO(vertices, sizeof(vertices));

    return ship;
}




