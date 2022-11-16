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
            cout << "No se pudo abrir el archivo terminales.txt" << endl;
        }    
  }
};




/*
int main(){
  Archivos archivo;
  archivo.leerTxt();
  Matrix graph;
  
  for (int i; i < archivo.vectorViajes.size(); i++){
    string origen = archivo.vectorViajes[i].origen;
    string destino = archivo.vectorViajes[i].destino;
    int costo = archivo.vectorViajes[i].costo;
    float tiempo = archivo.vectorViajes[i].tiempo;

    graph.InsertarArista(origen, destino, costo, tiempo);
  }
  
  graph.ImprimirMatrizCosto();
  graph.BuscarTiempoMinimo("COR", "TUC");
  graph.BuscarTiempoMinimo("USH", "SAL");
  graph.BuscarTiempoMinimo("SAL", "MDZ");
  graph.BuscarTiempoMinimo("USH", "TUC");
  graph.BuscarTiempoMinimo("USH", "USH");
  graph.BuscarTiempoMinimo("COR", "COR");
}
*/