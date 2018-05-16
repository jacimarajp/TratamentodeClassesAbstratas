#ifndef SCREEN_H
#define SCREEN_H
#include <ostream>
#include <vector>
using namespace std;
class Screen{
private:
    int nlin, ncol;
    char brush;
   vector <vector<char>> mat;
public:
    Screen(int nlin, int ncol);
    Screen();
    int getLin();
    int getCol();
    void setPixel(int x, int y);
    void setBrush(char _brush);
    void setBrush();
    void clear();
    friend ostream& operator<<(ostream &os, Screen &t);
};
#endif // SCREEN_H
