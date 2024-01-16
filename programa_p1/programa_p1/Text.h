#pragma once
#include "Solid.h"
#include <GL/glut.h>
#include <String>

using namespace std;

class Text :
    public Solid
{
private:
    string text;

public:
    Text() : text("Texto por defecto"), Solid() {}
    Text(string texto, vector3D coord) {
        this->setText(texto);
        this->setCoordinates(coord);
    }

    //GETTER
    inline string getText() const { return this->text; }

    //SETTER
    inline void setText(const string& dtext) { this->text = dtext; }

    void Render();
};

