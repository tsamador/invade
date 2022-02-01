#include "Enemy.h"

Direction Enemy::direction{RIGHT};

void Enemy::SetLocation(float x, float y)
{
    pos.x = x;
    pos.y = y;
}

bool Enemy::Update()
{

    switch (direction)
    {
        case LEFT:
        {
            pos.x -= 0.5f;
        } break;
        case RIGHT:
        {
            pos.x += 0.5f;
        } break;
    }

    if (pos.x > 750)
    {
        direction = LEFT;
        pos.x -= 0.5f;
        return true;
    }
    else if (pos.x < 50)
    {
        direction = RIGHT;
        pos.x += 0.5f;
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
            enemies[i].pos.y += 5;
        }
    }
}