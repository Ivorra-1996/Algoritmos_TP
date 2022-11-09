#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"terminales/terminales.cpp"

using namespace std;

// Cambiar instrucciones de funciones.
int obtenerIndice(std::string clave){
    terminales.resize(30); //tamaño del array
    int acc = 0;
    for (int i = 0; i < clave.size(); i++)
    {
        acc += clave[i];
    }
    
    return acc % terminales.size();

}


void funcionHash(std::string clave, Terminal terminal){
    terminales.insert(terminales.begin() + obtenerIndice(clave),terminal);

}

Terminal crearTerminal(){
    Terminal terminal;
    terminal.clave = "MARTIN";
    terminal.nombre = "nombre";
    terminal.ciudad = "ciudad";
    terminal.pais = "pais";
    terminal.superficie = 32;
    terminal.cantidad_terminales = 3;
    terminal.destinos_nacionales = 2;
    terminal.destinos_internacionales = 1;

    return terminal;

}

int main(){
    cout<<obtenerIndice("RET")<<endl;
    cout<<obtenerIndice("COR")<<endl;
    cout<<obtenerIndice("USH")<<endl;
    funcionHash((crearTerminal().clave),crearTerminal());

    for (int i = 0; i < terminales.size(); i++)
    {
        cout<<terminales[i].clave<<endl;
    }
    


    return 0 ;
}