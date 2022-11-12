#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

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
class Nodo {

    private:
        //atributos
        Terminal terminal;
        Nodo* siguiente;
    
    public:
        // metodos
        // constructor
        // PRE:
        // POS: crea un nodo con dato = d y siguiente = 0 (NULL)
        Nodo (Terminal t);

        void cambiar_dato(Terminal t);

        void cambiar_siguiente(Nodo* s);

        Terminal obtener_dato();
        
        Nodo* obtener_siguiente();
};

#endif //NODO_H_INCLUDED