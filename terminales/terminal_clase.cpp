#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<sstream>

using namespace std;

class Terminal{
    public:
    string clave;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;
};