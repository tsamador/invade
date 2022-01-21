
#include "invade.h"


game_state gameState;
ShaderLoader shader;

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

    InitEnemyShips();

}

void UpdateEntities(game_state* gameState)
{
    gameState->ship->Update(gameState->input);

    //TODO(Tanner): Stop using 10 as a literal here
    for(int i = 0; i < 10; i ++)
    {
        gameState->enemies.UpdateAll();
    }

}

static SpaceShip* InitSpaceShip()
{
    SpaceShip* ship = (SpaceShip*)malloc(sizeof(SpaceShip));

    float vertices[] =  {
        //Vertices              //Colors            //TODO(Texture Coordinates)
        -0.5f, 0.0f, 0.0f,     0.0f, 0.0f, 1.0f, //bottom left
        0.0f, 0.5f, 0.0f,      0.0f, 0.0f, 1.0f, //Top
        0.5f, 0.0f, 0.0f,      0.0f, 0.0f, 1.0f  //bottom right
    };
    
    ship->VAO = CreateVAO(vertices, sizeof(vertices));
    ship->alive = true;
    ship->xOffset = 0.0f;
    ship->yOffset = -0.8f;

    return ship;
}

static void InitEnemyShips()
{

    //TODO(Tanner): May want to the enemies to be squares??? Will need to refactor CreateVAO
    float vertices[] = {
        //Vertices              //Colors            //TODO(Texture Coordinates)
        -0.05f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f, //bottom left
        0.0f, 0.05f, 0.0f,      1.0f, 0.0f, 0.0f, //Top
        0.05f, 0.0f, 0.0f,      1.0f, 0.0f, 0.0f  //bottom right
    };

    gameState.EnemyVAO = CreateVAO(vertices, sizeof(vertices));

    float xStart = -0.9f;
    for(int i = 0; i < 10; i++)
    {
        gameState.enemies.enemies[i].alive = true;
        gameState.enemies.enemies[i].yOffset = 0.90f;
        gameState.enemies.enemies[i].xOffset = xStart;
        xStart += 0.18f;
    }

}




