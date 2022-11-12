#include "nodo.h"


Nodo::Nodo(Terminal t) {
    terminal = t;
    siguiente = 0;
}

void Nodo::cambiar_dato(Terminal t){
    terminal = t;
}

void Nodo::cambiar_siguiente(Nodo* s) {
    siguiente = s;
}

Terminal Nodo::obtener_dato() {
    return terminal;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}
