
#include "invade.h"


const int TARGET_FPS = 60;
const int MS_PER_SECOND = 1000;
const long int msPerFrame = MS_PER_SECOND/TARGET_FPS;

game_state gameState;
ShaderLoader shader;

static inline u64 GetPerfFrequency()
{
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    return frequency.QuadPart;
}

static inline u64 GetWallClock()
{
    LARGE_INTEGER wallClock;
    QueryPerformanceCounter(&wallClock);
    return wallClock.QuadPart;
}

void InvadeMainLoop()
{
    timeBeginPeriod(1); //Set the windows sleep granularity to 1 msa
    
    InitGameState();

    u64 startFrame, deltaFrame;
    u64 perfFrequency = GetPerfFrequency();
    startFrame = GetWallClock();


    while(gameState.active)
    {
        ProcessInput(&gameState);

        UpdateEntities(&gameState);

        Render(&gameState);
        
        deltaFrame = GetWallClock() - startFrame;
        u64 timeElapsed = deltaFrame/(perfFrequency/MS_PER_SECOND);

        if(timeElapsed < msPerFrame)
        {
            //Todo(Tanner):Sleep is Pretty bad, but we will use it here for now
            Sleep(msPerFrame - timeElapsed);
        }
        
       
        deltaFrame = GetWallClock() - startFrame;
        timeElapsed = deltaFrame/(perfFrequency/MS_PER_SECOND);
        f64 FPS = (f64)perfFrequency/deltaFrame;
        printf("Main Loop Time elapsed: %d\nFPS: %f \n", timeElapsed, FPS);
        startFrame = GetWallClock(); 
    }

}

void InitGameState()
{
    gameState.active = true;
    gameState.screenWidth = 800;
    gameState.screenHeight = 800;

    shader.Init("..\\code\\shader.vs", "..\\code\\shader.fs");
    gameState.shader = &shader;
    gameState.ship = InitSpaceShip();

    InitBullets();

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
    ship->Init(gameState.screenWidth, gameState.screenHeight);
    float vertices[] =  {
        //Vertices              //Colors            //TODO(Texture Coordinates)
        10.0f, 0.0f, 0.0f,     0.0f, 0.0f, 1.0f, //bottom left
        0.0f, 10.0f, 0.0f,      0.0f, 0.0f, 1.0f, //Top
        20.0f, 10.0f, 0.0f,      0.0f, 0.0f, 1.0f  //bottom right
    };
    
    ship->VAO = CreateVAO(vertices, sizeof(vertices));
    ship->alive = true;
    

    return ship;
}

static void InitEnemyShips()
{

    //TODO(Tanner): May want to the enemies to be squares??? Will need to refactor CreateVAO
    float vertices[] = {
        //Vertices              //Colors            //TODO(Texture Coordinates)
        10.0f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f, //bottom left
        0.0f, 10.0f, 0.0f,      1.0f, 0.0f, 0.0f, //Top
        20.0f, 10.0f, 0.0f,      1.0f, 0.0f, 0.0f  //bottom right
    };

    gameState.EnemyVAO = CreateVAO(vertices, sizeof(vertices));

    int xStart = 100;
    for(int i = 0; i < 10; i++)
    {
        gameState.enemies.enemies[i].alive = true;
        gameState.enemies.enemies[i].size.x = 2.0f;
        gameState.enemies.enemies[i].size.y = 2.0f; 
        gameState.enemies.enemies[i].pos.y = 100;
        gameState.enemies.enemies[i].pos.x = xStart;
        xStart += 60;
    }

}

static void InitBullets()
{
    float vertices[] = {
        5.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f, // Top
        0.0f, 20.0f, 0.0f,    0.0f, 1.0f, 0.0f, // bottom left 
        10.0f, 20.0f, 0.0f,   0.0f, 1.0f, 0.0f, // bottom right
    };

    gameState.ship->bulletVAO = CreateVAO(vertices, sizeof(vertices));
    

}

void UpdateGameStateWindow(int width, int height)
{
    gameState.screenHeight = height;
    gameState.screenWidth = width;
}


