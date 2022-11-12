#include <iostream>
using namespace std;
#include "nodo_clase.cpp"
#include "lista.cpp"
//#include "..\terminales\terminal_clase.cpp"
#include<cstdlib>

#include<fstream>
#include<string.h>
#include<vector>
#include<sstream>


vector<Lista>terminales;

int main(){
    Lista Lista0;
    Lista lista1;
    Terminal terminal1,terminal2;
    terminal1.clave = "RET";
    terminal1.nombre = "Terminal_de_Retiro";
    terminal1.ciudad = "Buenos_A";
    terminal1.pais = "FALOPA";
    terminal1.superficie = 2.3;
    terminal1.cantidad_terminales = 2;
    terminal1.destinos_nacionales = 3;
    terminal1.destinos_internacionales = 10;

    terminal2.clave = "MARTINI";
    terminal2.nombre = "Terminal_de_Retiro";
    terminal2.ciudad = "Buenos_A";
    terminal2.pais = "FALOPA";
    terminal2.superficie = 2.3;
    terminal2.cantidad_terminales = 2;
    terminal2.destinos_nacionales = 3;
    terminal2.destinos_internacionales = 10;

    lista1.alta(terminal1,1);
    lista1.alta(terminal2,1);

    lista1.mostrar();

   // terminales.push_back(lista1);


    return 0;
}