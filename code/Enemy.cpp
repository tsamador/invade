#include "Enemy.h"

const float ENEMY_HORIZ_SPEED = 0.125f;

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
            pos.x -= ENEMY_HORIZ_SPEED;
        } break;
        case RIGHT:
        {
            pos.x += ENEMY_HORIZ_SPEED;
        } break;
    }

    if (pos.x > 750)
    {
        direction = LEFT;
        pos.x -= ENEMY_HORIZ_SPEED;
        return true;
    }
    else if (pos.x < 50)
    {
        direction = RIGHT;
        pos.x += ENEMY_HORIZ_SPEED;
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