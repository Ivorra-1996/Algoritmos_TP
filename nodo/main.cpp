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


int obtenerIndice(std::string clave){
    terminales.resize(10);//tamaño del array
    int acc = 0;
    for (int i = 0; i < clave.size(); i++)
    {
        acc += clave[i];//RET -> R -> E -> T
    }
    
    return acc % terminales.size();

}

/*
void funcionHash(std::string clave, Terminal terminal){
    terminales.insert(terminales.begin() + obtenerIndice(clave),terminal);

}
*/

int main(){
    Lista lista1;
    Terminal terminal1,terminal2;
    terminal1.clave = "ROC";
    terminal1.nombre = "Terminal_de_Retiro";
    terminal1.ciudad = "Buenos_A";
    terminal1.pais = "FALOPA";
    terminal1.superficie = 2.3;
    terminal1.cantidad_terminales = 2;
    terminal1.destinos_nacionales = 3;
    terminal1.destinos_internacionales = 10;

    terminal2.clave = "COR";
    terminal2.nombre = "Terminal_de_Retiro";
    terminal2.ciudad = "Buenos_A";
    terminal2.pais = "FALOPA";
    terminal2.superficie = 2.3;
    terminal2.cantidad_terminales = 2;
    terminal2.destinos_nacionales = 3;
    terminal2.destinos_internacionales = 10;

    int index1 = obtenerIndice(terminal1.clave);
    int index2 = obtenerIndice(terminal2.clave);


   

    terminales[index1].alta(terminal1,1);
    terminales[index2].alta(terminal2,1);
    terminales[index2].alta(terminal2,1);
    
    for (int i = 0; i < terminales.size(); i++)
    {
        cout<<"Posicion: "<<i;
        terminales[i].mostrar();
    }
    
    /*
    for (int i = 0; i < 1; i++)
    {
        Lista lista;
        terminales.push_back(lista);
    }

    for (int i = 0; i < terminales.size(); i++)
    {
        cout<<"Posicion"<<i<<endl;
        cout<<terminales[i].obtener_largo();
    }
    */
    

   // terminales.push_back(lista1);


    return 0;
}