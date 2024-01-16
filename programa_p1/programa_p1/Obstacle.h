#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Player.h"
#include <iostream>
#include <string>

class Obstacle : public ModelLoader
{
private:
    Model* model;
    ModelLoader* loader;

public:
    Obstacle(string ruta, float size) {
        loader = new ModelLoader();
        loader->setSize(size);
        model = new Model;
        loader->LoadModel(ruta);
        *model = loader->getModel();
    }

    inline Model* GetModel() { return this->model; }
    inline void ClearLoader() { loader->Clear(); }
    virtual bool CheckCollision(Player* p, Solid* b) = 0;
};

