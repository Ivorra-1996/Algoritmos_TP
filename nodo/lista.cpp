#include "lista.h"
#include <iomanip>
using namespace std;

Lista::Lista() {
    primero = 0;
    largo = 0;
}

bool Lista::vacia() {
    return (largo == 0);
}

void Lista::alta(Terminal t, int pos) {
    Nodo* nuevo = new Nodo(t);

    if (pos == 1) {
        nuevo -> cambiar_siguiente(primero);
        primero = nuevo;
    } 
    else {
        Nodo* anterior = obtener_nodo(pos-1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    
    for (int i=1; i<pos; i++) {
        aux = aux->obtener_siguiente();
    }
    return aux;
}

Terminal Lista::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista::baja(int pos) {
    Nodo* borrar;

    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    largo--;
}

Lista::~Lista() {
    while (!vacia()) {
        baja(1);
    }
}

int Lista::obtener_largo() {
    return largo;
}

void Lista::mostrar(){
    cout << "[";
    if (!vacia()) {
        for (int i=1; i<largo; i++) {
            cout << this->consulta(i).clave<<",";
        }
        cout << consulta(largo).clave;
    }
    cout << "]" <<endl;
}

void Lista::mostrarTodo(){
    if (!vacia()) {
        for (int i=1; i<largo+1; i++) {
            cout << this->consulta(i).clave<<" ";
            cout << this->consulta(i).nombre<<" ";
            cout << this->consulta(i).ciudad<<" ";
            cout << this->consulta(i).pais<<" ";
            cout << this->consulta(i).superficie<<" ";
            cout << this->consulta(i).cantidad_terminales<<" ";
            cout << this->consulta(i).destinos_nacionales<<" ";
            cout << this->consulta(i).destinos_internacionales<<" ";
            cout << " " <<endl;
        }
    }
}

string Lista::retornaTodo(){
    string lista = "";
    stringstream ss;
    if (!vacia()) {
        for (int i=1; i<largo+1; i++) {
            lista = lista + this->consulta(i).clave + " ";
            lista = lista + this->consulta(i).nombre + " ";
            lista = lista + this->consulta(i).ciudad + " ";
            lista = lista + this->consulta(i).pais + " ";
            ss << fixed<<setprecision(2)<<this->consulta(i).superficie;
            lista = lista + ss.str() + " ";
            ss.str("");
            lista = lista + std::to_string(this->consulta(i).cantidad_terminales) + " ";
            lista = lista + std::to_string(this->consulta(i).destinos_nacionales) + " ";
            lista = lista + std::to_string(this->consulta(i).destinos_internacionales);
            lista = lista + "\r\n"; 
        }
    }
    return lista;
}

