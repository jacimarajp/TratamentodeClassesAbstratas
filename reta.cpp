#include "reta.h"
#include <stdlib.h>
#include <math.h>

Reta::Reta(int _x0,int _y0,int _x1,int _y1)
{
    x0=_x0;
    y0=_y0;
    x1=_x1;
    y1=_y1;
}
Reta::Reta()
{

}


void Reta::draw(Screen &t)
{
    int x=x0,y=y0,Delta_x,Delta_y,new_e,Temp,Troca;

    Delta_x = abs(x1 - x0);
    Delta_y = abs(y1 - y0);

    if(Delta_y > Delta_x){
        Temp = Delta_x;
        Delta_x = Delta_y;
        Delta_y = Temp;
        Troca = 1;
    }


    else{
        Troca = 0;
    }
    new_e = 2*Delta_y - Delta_x;

    for(int i=1; i<= Delta_x; i++)
    {
        t.setPixel(x,y);

        while (new_e >= 0){
            if(Troca == 1)
            {
                //Muda para a proxima linha de rasterizaÃ§Ã£o
                x = x + 1;
            }
            else
            {
                y = y + 1;
            }
            new_e = new_e - 2*Delta_x;
        }
        //Permanece nesta linha de rasterizaÃ§Ã£o
        if(Troca == 1){
            y = y + 1;
        }
        else{
            x = x + 1;
        }
        new_e= new_e + 2*Delta_y;
    }
    t.setPixel(x1,y1);
}
