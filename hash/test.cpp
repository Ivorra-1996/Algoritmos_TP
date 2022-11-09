#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class TablaHash { 
    private:
        static const int largoIndice = 10;
        list<pair<int, string> > indice[largoIndice];
    
    public:
        bool estaVacia() const;
        int hash(int codigo);
        void insertarItem(int codigo, string valor);
        void borrarItem(int codigo);
        string buscar(int codigo);
        void imprimir();
};

bool TablaHash::estaVacia() const {
    int sum;
    for (int i=0; i < largoIndice; i++) {
        sum += indice[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int TablaHash::hash(int codigo) {
    return codigo % largoIndice; 
}

void TablaHash::insertarItem(int codigo, string valor) {
    int hashValue = hash(codigo);
    auto&& cell = indice[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == codigo) {
            keyExists = true;
            bItr->second = valor;
            cout << "El codigo ya existe, reemplazarlo." << endl;
            break;
        }
    }
    if (!keyExists) {
        cell.emplace_back(codigo, valor);
    }
    return;
}

void TablaHash::borrarItem(int codigo) {
    int hashValue = hash(codigo);
    auto&& cell = indice[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == codigo) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "Item reemplazado" << endl;
            break;
        }
    }
    if (!keyExists) {
        cout << "codigo no encontrada" << endl;
    }
    return;
}

void TablaHash::imprimir() {
    for (int i=0; i < largoIndice; i++) {
        if (indice[i].size() == 0) continue;

        auto bItr = indice[i].begin();
        for (; bItr != indice[i].end(); bItr++) {
            cout << "Key: " << bItr->first << "Valor: " << bItr->second << endl;
        }
    }
    return;
}

int main() {
    TablaHash HT;

    if (HT.estaVacia()) {
        cout << "la tabla esta vacia" << endl;
    }else {
        cout << "la tabla no esta vacia" << endl;
    }

HT.insertarItem(100, "Martin");
HT.insertarItem(201, "Maria");
HT.insertarItem(332, "Pepe");
HT.insertarItem(124, "Seba");
HT.insertarItem(929, "Juan");
HT.insertarItem(929, "Segundo");

HT.imprimir();

HT.borrarItem(332);
HT.borrarItem(100);

if (HT.estaVacia()) {
    cout << "hay que revisar el codigo" << endl;
 } else {
    cout << "correcto!" << endl;
 }

}



