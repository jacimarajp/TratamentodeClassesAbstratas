#include "screen.h"

Screen::Screen(int _nlin, int _ncol)
{

    mat = vector<vector<char>> (_nlin, vector<char> (_ncol,'0'));
    nlin = _nlin;
    ncol = _ncol;

}
Screen::Screen(){

    nlin=0;
    ncol=0;
}

int Screen::getLin()
{
    return nlin;
}

int Screen::getCol()
{
    return ncol;
}

void Screen::setPixel(int x, int y)
{
    if(x>=0&&y>=0)
   {
    mat[x][y] = brush;
   }
}

void Screen::clear()
{
    for(int i=0; i<nlin; i++){
        for(int j=0; j<ncol; j++){
            mat[i][j] = '0';
        }
    }
}


void Screen::setBrush(char _brush)
{
    brush = _brush;
}

void Screen::setBrush()
{
    brush = ' ';
}

ostream& operator<<(ostream &os, Screen &t)
{
    for(int i=0; i<t.nlin; i++){
        for(int j=0; j<t.ncol; j++){
             os << t.mat[i][j];
        }
        os<<endl;
    }
    return os;
}

