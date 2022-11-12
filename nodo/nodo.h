#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Dato{
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
        Dato dato;
        Nodo* siguiente;
    
    public:
        // metodos
        // constructor
        // PRE:
        // POS: crea un nodo con dato = d y siguiente = 0 (NULL)
        Nodo (Dato d);

        void cambiar_dato(Dato d);

        void cambiar_siguiente(Nodo* s);

        Dato obtener_dato();
        
        Nodo* obtener_siguiente();
};

#endif //NODO_H_INCLUDED