#pragma once
#include "Obstacle.h"
#include "Player.h"
#include <string>
class Bonus : public Obstacle
{
public:
    Bonus(string ruta, float size) : Obstacle(ruta, size) {};

    bool CheckCollision(Player* p, Solid* b);
};

