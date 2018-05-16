#include "retangulo.h"

Retangulo::Retangulo(int _x0,int _y0,int _altura,int _largura, bool _fillmode)
{
    x0=_x0;
    y0=_y0;
    altura=_altura;
    largura=_largura;
    fillmode=_fillmode;
}


void Retangulo::draw(Screen &t)
{
    if(fillmode == true){

        for(int i=x0; i<=altura; i++){
            for(int j=y0; j<=largura; j++){
                t.setPixel(i,j);
            }
        }




    }
    else{
        t.setPixel(x0,y0);

        for(int i=0;i<largura;i++){
            t.setPixel(x0,y0+i);
            t.setPixel(x0+altura-1,y0+i);
        }
        for(int i=1;i<altura;i++){
            t.setPixel(x0+i,y0);
            t.setPixel(x0+i,y0+largura-1);
        }
    }

}

