#ifndef CIRCULO_H
#define CIRCULO_H
#include "screen.h"
#include "figurageometrica.h"

class Circulo:public FiguraGeometrica
{
private:
    int xc,yc,raio;
    bool fillmode;
public:
    Circulo(int _xc,int _yc,int _raio, bool _fillmode);
    void draw(Screen &t);
};

#endif // CIRCULO_H
