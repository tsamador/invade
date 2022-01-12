#include "Enemy.h"

Direction Enemy::direction{RIGHT};

void Enemy::SetLocation(float x, float y)
{
    xOffset = 0;
    yOffset = 0;
}

bool Enemy::Update()
{

    switch (direction)
    {
        case LEFT:
        {
            xOffset -= 0.00001f;
        } break;
        case RIGHT:
        {
            xOffset += 0.00001f;
        } break;
    }

    if (xOffset > 0.9f)
    {
        direction = LEFT;
        return true;
    }
    else if (xOffset < -0.9f)
    {
        direction = RIGHT;
        return true;
    }

    return false;
}

void EnemyArray::UpdateAll()
{
    bool ShuffleDown = false;
    for(int i = 0; i <  NUM_ENEMIES; i++)
    {
        if(enemies[i].Update())
        {
            ShuffleDown = true;
        }

    }

    if(ShuffleDown)
    {
        for(int i = 0; i < NUM_ENEMIES; i++)
        {
            enemies[i].yOffset -= 0.01f;
        }
    }
}