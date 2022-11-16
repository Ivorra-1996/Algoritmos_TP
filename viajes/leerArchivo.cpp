#include "caminoMinimo.cpp"
#include "viajes.h"
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include <vector>

using namespace std;

class Archivos{
  public:
 
  vector<Viaje> vectorViajes;
  
  void leerTxt(){
    ifstream lectura;
    lectura.open("viajes.txt",ios::out|ios::in);
    string linea;
    string origen, destino;
    int costo;
    float tiempo;
    if (lectura.is_open())
        {
            while (getline(lectura, linea))
            {
                stringstream ss(linea);
                ss >> origen >> destino >> costo >> tiempo;
                //cout << costo << endl;
                //listaNombres.push_back(origen);
                Viaje viajes;
                viajes.origen = origen;
                viajes.destino = destino;
                viajes.costo = costo;
                viajes.tiempo = tiempo;

                vectorViajes.push_back(viajes);
                //cout << vectorViajes[0].tiempo << endl;
            }
            lectura.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo viajes.txt" << endl;
        }    
  }
};