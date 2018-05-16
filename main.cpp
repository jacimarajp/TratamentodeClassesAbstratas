#include <iostream>
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"
#include "figurageometrica.h"
#include "screen.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    vector <FiguraGeometrica*> figuras;
    ofstream fout;
    ifstream fin;
    string teste;
    //stringstream sin;
    int linhas, colunas, x0,y0,x1,y1,x_ret,y_ret,altura, largura, op_ret,op_circ,raio,x_centro,y_centro;
    char caracter;

    Screen t;


    fin.open("C:/Users/Thiago/Desktop/Tratamento_de_Classes_Abstratas/entrada_de_dados.txt");
    if(!fin.is_open()){
        cout<<"erro ao abrir arquivo"<<endl;
        exit(0);
    }

    while(fin.good()){
        getline(fin,teste);
        stringstream sin(teste);
        sin >> teste;
        if(teste == "dim"){
            sin>>linhas>>colunas;
            t = Screen(linhas,colunas);

        }
        if(teste == "brush"){
            sin>>caracter;
            t.setBrush(caracter);
        }
        if(teste == "reta"){
            sin>>x0>>y0>>x1>>y1;
            figuras.push_back(new Reta(x0,y0,x1,y1));;
        }
        if(teste == "retangulo"){
            sin>>x_ret>>y_ret>>altura>>largura>>op_ret;
            figuras.push_back(new Retangulo(x_ret,y_ret,altura,largura,op_ret));
        }
        if(teste == "circulo"){
            sin>>x_centro>>y_centro>>raio>>op_circ;
            figuras.push_back(new Circulo(x_centro,y_centro,raio,op_circ));
        }
    }



    for(int i=0; i<figuras.size(); i++){
        figuras[i]->draw(t);
    }
    cout<<t;
    fin.close();


    fout.open("C:/Users/Thiago/Desktop/Tratamento_de_Classes_Abstratas/saida_de_dados.txt");
    if(!fout.is_open()){
        cout<<"erro ao abrir arquivo"<<endl;
        exit(0);
    }
    fout<<t;
    fout.close();


   return 0;

}


/*
    Screen t(10,10);
    t.setBrush('*');
    //Reta rt(0,0,9,9);
    //rt.draw(t);
   //Retangulo ret(0,0,5,11,0);
   //ret.draw(t);
   //cout<<t;

    Circulo c(3,5,4,0);
    c.draw(t);
    cout<<t;

*/

/*
    vector <FiguraGeometrica*> figuras;
    ofstream fout;
    ifstream fin;
    string teste;
    stringstream sin;
    int linhas, colunas, x0,y0,x1,y1,x_ret,y_ret,altura, largura, op_ret,op_circ,raio,x_centro,y_centro;
    char caracter;

    Screen t;


    fin.open("C:/Users/Thiago/Desktop/Tratamento_de_Classes_Abstratas/entrada_de_dados.txt");
    if(!fin.is_open()){
        cout<<"erro de entrada"<<endl;
        exit(0);
    }

    while(fin.good()){
        getline(fin,teste);
        sin >> teste;
        if(teste == "dim"){
            sin>>linhas>>colunas;
            t = Screen(linhas,colunas);

        }
        if(teste == "brush"){
            sin>>caracter;
            t.setBrush(caracter);
            cout<<t;
        }
        if(teste == "reta"){
            sin>>x0>>y0>>x1>>y1;
            figuras.push_back(new Reta(x0,y0,x1,y1));;
        }
        if(teste == "retangulo"){
            sin>>x_ret>>y_ret>>altura>>largura>>op_ret;
            figuras.push_back(new Retangulo(x_ret,y_ret,altura,largura,op_ret));
        }
        if(teste == "circulo"){
            sin>>x_centro>>y_centro>>raio>>op_circ;
            figuras.push_back(new Circulo(x_centro,y_centro,raio,op_circ));
        }
    }



    for(int i=0; i<figuras.size(); i++){
        t.setBrush(caracter);
        figuras[i]->draw(t);
    }
    cout<<t;
    fin.close();


    fout.open("C:/Users/Thiago/Desktop/Tratamento_de_Classes_Abstratas/saida_de_dados.txt");
    if(!fout.is_open()){
        cout<<"erro de saida"<<endl;
        exit(0);
    }
    fout<<t;
    fout.close();




*/
