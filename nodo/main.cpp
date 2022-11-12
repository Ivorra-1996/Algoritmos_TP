#include <iostream>
using namespace std;
#include "nodo_clase.cpp"
#include "lista.cpp"
#include "..\terminales\terminal_clase.cpp"
#include<cstdlib>

#include<fstream>
#include<string.h>
#include<vector>
#include<sstream>


vector<Lista>terminales;

int main(){
    Lista Lista0;
    Lista lista1;
    Dato dato,pepito;
    dato.clave = "RET";
    dato.nombre = "Terminal_de_Retiro";
    dato.ciudad = "Buenos_A";
    dato.pais = "FALOPA";
    dato.superficie = 2.3;
    dato.cantidad_terminales = 2;
    dato.destinos_nacionales = 3;
    dato.destinos_internacionales = 10;

    pepito.clave = "MARTIN";
    pepito.nombre = "Terminal_de_Retiro";
    pepito.ciudad = "Buenos_A";
    pepito.pais = "FALOPA";
    pepito.superficie = 2.3;
    pepito.cantidad_terminales = 2;
    pepito.destinos_nacionales = 3;
    pepito.destinos_internacionales = 10;

    lista1.alta(dato,1);
    lista1.alta(pepito,1);

    lista1.mostrar();

    terminales.push_back(lista1);

    for (int i = 1; i < terminales.size(); i++){
        cout<<"[";
        cout<<"Posicion: "<<i<<endl;
        terminales[i].mostrar();
        cout<<"]";
    };
    
  



    return 0;
}