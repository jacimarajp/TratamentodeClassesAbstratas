#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"
#include "screen.h"
#include "reta.h"
class Retangulo:public FiguraGeometrica
{
private:
    int x0,y0,altura,largura;
    bool fillmode;
    Reta r;
public:
    Retangulo(int _x0, int _y0, int _altura, int _largura, bool _fillmode);
    void draw(Screen &t);
};

#endif // RETANGULO_H
