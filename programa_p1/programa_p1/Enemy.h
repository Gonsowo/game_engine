#pragma once
#include "Obstacle.h"
#include <string>
class Enemy : public Obstacle
{
public:
    Enemy(string ruta, float size) : Obstacle(ruta, size) {};

    bool CheckCollision(Player* p, Solid* b);
};