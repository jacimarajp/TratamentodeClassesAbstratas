#include "circulo.h"

Circulo::Circulo(int _xc, int _yc, int _raio, bool _fillmode)
{
    xc=_xc;
    yc=_yc;
    raio=_raio;
    fillmode = _fillmode;
}
void Circulo::draw(Screen &t)
{

    if(fillmode == true){

        for(int i=xc-raio; i<=xc+raio; i++){
            for(int j=yc-raio; j<=yc+raio; j++){
                if((i-xc)*(i-xc) + (j-yc)*(j-yc) <= raio*raio){
                    t.setPixel(i,j);
                }
            }
        }

    }

    else{
        int x,y,d;
        x = 0;
        y = raio;
        d = 1 - raio;
        t.setPixel(xc,yc+raio);
        t.setPixel(xc,yc-raio);
        t.setPixel(xc+raio,yc);
        t.setPixel(xc-raio,yc);
        while(y >= x){
            if(d < 0){
                d = d + 2*x + 3;
                x = x + 1;
            }
            else{
                d = d + 2*(x-y) + 5;
                x = x + 1;
                y = y - 1;
            }
            t.setPixel(y+xc,x+yc);
            t.setPixel(x+xc,y+yc);
            t.setPixel(xc-x,yc+y);
            t.setPixel(xc-y,x+yc);
            t.setPixel(xc-y,yc-x);
            t.setPixel(x+xc,yc-y);
            t.setPixel(y+xc,yc-x);
            t.setPixel(xc-x,yc-y);

        }
    }
}
