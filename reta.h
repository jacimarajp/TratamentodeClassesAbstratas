#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"
#include "screen.h"

class Reta:public FiguraGeometrica{
private:
    int x0,y0,x1,y1;
public:
    Reta(int _x0,int _y0,int _x1,int _y1);
    Reta();
    void draw(Screen &t);
};

#endif // RETA_H
