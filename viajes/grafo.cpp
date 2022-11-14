

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define INFINITO 9999

using namespace std;

class Matrix {
  public:
  vector<string> listaNodo;
  vector<vector<int> > matrizAdjunta; 

  //redimensiona la matriz de adyasencia y copia en los valores anteiores
  void  Redimensionar(size_t nuevoLargo){
    vector<vector<int> > matrizAnterior = matrizAdjunta;
    matrizAdjunta = vector<vector<int> >(nuevoLargo, vector<int>(nuevoLargo, INFINITO));

    for (size_t fila = 0; fila < min(nuevoLargo, matrizAnterior.size()); ++fila) {
      for (size_t col = 0; col < min(nuevoLargo, matrizAnterior[fila].size()); ++col) {
        matrizAdjunta[fila][col] = matrizAnterior[fila][col];
      }
    }
  }

  void InsertarNodo(string nombre) {
    // esta el nodo en el grafo ?
    if (find(listaNodo.begin(), listaNodo.end(), nombre) == listaNodo.end()) {
      listaNodo.push_back(nombre);

      Redimensionar(listaNodo.size());
    }
  }


  void BorrarNodo(string nombre) {
    //solo remueve si el nodo existe
    auto it = find(listaNodo.begin(), listaNodo.end(), nombre);
    if ( it != listaNodo.end()) {
      // buscar el indice de este nombre en la lista de nodos
      int index = it - listaNodo.begin();

      // remueve todas las columans de la matriz adjunta
      for (auto& fila : matrizAdjunta) {
        fila.erase(fila.begin() + index);
      }
      // remueve todas las filas de la matriz 
      matrizAdjunta.erase(matrizAdjunta.begin() + index);

      // remueve las etiquetas de la lista de nodos
      listaNodo.erase(it);

    }else{
      cout << "Nodo " << nombre << " no existe en el grafo" << endl;
    }
  }

  vector<string>::iterator SearchNode(string nombre) {
    return find(listaNodo.begin(), listaNodo.end(), nombre);
  }

  void InsertarArista(string nodoOrigen, string nodoDestino, int distancia) {
    // se fija que ambos nodos esten en la matriz y agrega la distancia
    //si no llega, la distancia es infinito

    auto nodoDestinoIt = SearchNode(nodoDestino);
    if (nodoDestinoIt == listaNodo.end()){
      InsertarNodo(nodoDestino);
    }

    auto fromNodeIt = SearchNode(nodoOrigen);
    if (fromNodeIt == listaNodo.end()){
      InsertarNodo(nodoOrigen);
    }

    //insert edge
    int nodoOrigenIndice = SearchNode(nodoOrigen) - listaNodo.begin();
    int nodoDestinoIndice = SearchNode(nodoDestino) - listaNodo.begin();
    matrizAdjunta[nodoOrigenIndice][nodoDestinoIndice] = distancia;
  }

  void BorrarArista(string nodoOrigen, string nodoDestino){
    // is the frin bide un the graph?
    auto fromNodeIt = SearchNode(nodoOrigen);
    if (fromNodeIt != listaNodo.end()) {
      //is the ti nide un the graph?
      auto nodoDestinoIt = SearchNode(nodoDestino);
      if (nodoDestinoIt != listaNodo.end()) {
        //remove the path/edge
        int nodoOrigenIndice = SearchNode(nodoOrigen) - listaNodo.begin();
        int nodoDestinoIndice = SearchNode(nodoDestino) - listaNodo.begin();
        matrizAdjunta[nodoOrigenIndice][nodoDestinoIndice] = INFINITO;
      }
    }
  }

  bool BuscarArista(string nodoOrigen, string nodoDestino) {
    // is the from node in the graph?
     auto fromNodeIt = SearchNode(nodoOrigen);
      if (fromNodeIt != listaNodo.end()) {
        //is the ti nide un the graph?
        auto nodoDestinoIt = SearchNode(nodoDestino);
        if (nodoDestinoIt != listaNodo.end()) {
          int nodoOrigenIndice = SearchNode(nodoOrigen) - listaNodo.begin();
          int nodoDestinoIndice = SearchNode(nodoDestino) - listaNodo.begin();
          return matrizAdjunta[nodoOrigenIndice][nodoDestinoIndice] != INFINITO;
        }
      }
      return false;
  }

  void Imprimir() {
    size_t numNodes = listaNodo.size();
    int largoCampo = 5;

    //print col labels on top line
    cout << setw(largoCampo) << " ";
    for (size_t col = 0; col < numNodes; ++col) {
      cout << setw(largoCampo) << listaNodo[col];
    }
    cout << endl;

    // print the adj matrix with a label before each fila
    for (size_t fila = 0; fila < numNodes; ++fila) {
      //print fila label
      cout << setw(largoCampo) << listaNodo[fila];

      // print each fila - one column at time
      for (size_t col = 0; col < numNodes; ++col) {
        cout << setw(largoCampo) << matrizAdjunta[fila][col];
      }
      cout << endl;
    }
  }
};


int main(){
  Matrix graph;
  graph.InsertarArista("USH", "SAL",5403);
  graph.InsertarArista("SAL", "ROS",632 );
  graph.InsertarArista("ROS", "ERT",9843);
  graph.InsertarArista("MDP", "ERT",912 );
  graph.InsertarArista("ERT", "MDZ",311 );
  graph.InsertarArista("MDZ", "RET",1082);
  graph.InsertarArista("RET", "ROS",1987);
  graph.InsertarArista("TUC", "MDP",382 );
  graph.InsertarArista("COR", "TUC",111 );
  graph.Imprimir();
}