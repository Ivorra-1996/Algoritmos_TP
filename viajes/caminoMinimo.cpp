#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include<fstream>
#define INF 99999

using namespace std;

class Matrix {
  public:
  vector<string> listaNodo;
  vector<vector<float> > matrizAdjuntaTiempo;
  vector<vector<int> > matrizAdjuntaCosto;   

  vector<string>::iterator SearchNode(string nombre) {
    return find(listaNodo.begin(), listaNodo.end(), nombre);
  }

  //redimensiona la matriz de adyasencia y copia en los valores anteiores
  void  Redimensionar(size_t nuevoLargo){
    vector<vector<int> > matrizAnterior = matrizAdjuntaCosto;
    vector<vector<float> > matrizAnteriorValor = matrizAdjuntaTiempo;
    
    matrizAdjuntaCosto = vector<vector<int> >(nuevoLargo, vector<int>(nuevoLargo, INF));
    matrizAdjuntaTiempo = vector<vector<float> >(nuevoLargo, vector<float>(nuevoLargo, 0));

    for (size_t fila = 0; fila < min(nuevoLargo, matrizAnterior.size()); ++fila) {
      for (size_t col = 0; col < min(nuevoLargo, matrizAnterior[fila].size()); ++col) {
        matrizAdjuntaCosto[fila][col] = matrizAnterior[fila][col];
      }
    }

    for (size_t fila = 0; fila < min(nuevoLargo, matrizAnteriorValor.size()); ++fila) {
      for (size_t col = 0; col < min(nuevoLargo, matrizAnteriorValor[fila].size()); ++col) {
        matrizAdjuntaTiempo[fila][col] = matrizAnteriorValor[fila][col];
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

  void InsertarArista(string nodoOrigen, string nodoDestino, int distancia, float valor) {
    // se fija que ambos nodos esten en la matriz y agrega la distancia
    //si no llega, la distancia es INF

    auto nodoDestinoIt = SearchNode(nodoDestino);
    if (nodoDestinoIt == listaNodo.end()){
      InsertarNodo(nodoDestino);
    }

    auto nodoOrigenIt = SearchNode(nodoOrigen);
    if (nodoOrigenIt == listaNodo.end()){
      InsertarNodo(nodoOrigen);
    }
    //inserta aristas
    int nodoOrigenIndice = SearchNode(nodoOrigen) - listaNodo.begin();
    int nodoDestinoIndice = SearchNode(nodoDestino) - listaNodo.begin();
    matrizAdjuntaCosto[nodoOrigenIndice][nodoDestinoIndice] = distancia;
    matrizAdjuntaTiempo[nodoOrigenIndice][nodoDestinoIndice] = valor;
  }

  int BuscarNodo(string nombreNodo){
    auto nombreNodoIt = SearchNode(nombreNodo);
    if (nombreNodoIt != listaNodo.end()) {
        int nombreNodoIndice = SearchNode(nombreNodo) - listaNodo.begin();
        return nombreNodoIndice;
      }
    }

  void ImprimirMatrizCosto() {
    size_t numNodes = listaNodo.size();
    int largoCampo = 7;

    //imprime el titulo de las columnas 
    cout << setw(largoCampo) << " ";
    for (size_t col = 0; col < numNodes; ++col) {
      cout << setw(largoCampo) << listaNodo[col];
    }
    cout << endl;

    // imprime la matriz adujunta
    for (size_t fila = 0; fila < numNodes; ++fila) {
      //imprime el nombre de la fila
      cout << setw(largoCampo) << listaNodo[fila];

      // imprime cada fila y columna
      for (size_t col = 0; col < numNodes; ++col) {
        int valor = matrizAdjuntaCosto[fila][col];
        
        if (fila == col) {
          cout << setw(largoCampo) << "0";
        } else if (valor == INF){
          cout << setw(largoCampo) << "x";
        }else {
          cout << setw(largoCampo) << matrizAdjuntaCosto[fila][col];   
        }
      }
      cout << endl;
    }
  }

    void ImprimirMatrizTiempo() {
    size_t numNodes = listaNodo.size();
    int largoCampo = 7;

    //imprime el titulo de las columnas 
    cout << setw(largoCampo) << " ";
    for (size_t col = 0; col < numNodes; ++col) {
      cout << setw(largoCampo) << listaNodo[col];
    }
    cout << endl;

    // imprime la matriz adujunta
    for (size_t fila = 0; fila < numNodes; ++fila) {
      //imprime el nombre de la fila
      cout << setw(largoCampo) << listaNodo[fila];

      // imprime cada fila y columna
      for (size_t col = 0; col < numNodes; ++col) {
        int valor = matrizAdjuntaTiempo[fila][col];
        
        if (fila == col) {
          cout << setw(largoCampo) << "0";
        } else if (valor == INF){
          cout << setw(largoCampo) << "x";
        }else {
          cout << setw(largoCampo) << matrizAdjuntaTiempo[fila][col];   
        }
      }
      cout << endl;
    }
  }

  void ImprimirSolucionCosto(int dist[], int parent[], int src, int destiny) {
    string srcNode = listaNodo[src];
    string destNode = listaNodo[destiny];
    int calc = dist[destiny];
    string path, parentCity = "";

    if (calc != INF && calc != 0 && src != destiny) {
      cout << "El precio mas economico entre " << srcNode << " y " << destNode << " es de $" << calc << endl;
      cout << "La ruta es: ";
      cout << destNode;
      while (parent[destiny] != src) {
            parentCity = listaNodo[parent[destiny]];
            path = path + " <- " + parentCity;
            destiny = parent[destiny];
      }
      path = path + " <- " + srcNode;
      cout << path << endl;
    }else {
      cout << "No es posible llegar de " << srcNode << " a " << destNode << endl;
    }
  }

  void ImprimirSolucionTiempo(float dist[], int parent[], int src, int destiny) {
    string srcNode = listaNodo[src];
    string destNode = listaNodo[destiny];
    float calc = dist[destiny];
    string path, parentCity = "";

    if (calc != INF && calc != 0 && src != destiny) {
      cout << "El menor tiempo entre: " << srcNode << " y " << destNode << " es de " << calc << " Hs." << endl;
      cout << "La ruta es: ";
      cout << destNode;
      while (parent[destiny] != src) {
            parentCity = listaNodo[parent[destiny]];
            path = path + " <- " + parentCity;
            destiny = parent[destiny];
      }
      path = path + " <- " + srcNode;
      cout << path << endl;
    }else {
      cout << "No es posible llegar de " << srcNode << " a " << destNode << endl;
    }
  }

  int minimumDist(int dist[], bool sptSet[]) {
    // Initialize min value
    int min = INF, min_index;
    int numNodes = matrizAdjuntaCosto.size();//CAMBIO -1

    for (int v = 0; v < numNodes; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
            //cout << "min_index: "<< min_index << endl;
    return min_index;
  }

   int minimumDistTiempo(float dist[], bool sptSet[]) {
    // Initialize min value
    float min = 99999.9;
    int min_index;
    int numNodes = matrizAdjuntaCosto.size();//CAMBIO -1

    for (int v = 0; v < numNodes; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
            //cout << "min_index: "<< min_index << endl;
    return min_index;
  }

  void dijkstraCosto(int src, int destiny) {
    int MAX_NODES = listaNodo.size();
    int dist[MAX_NODES]; 
    bool sptSet[MAX_NODES]; 
    int parent[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < MAX_NODES; count++) {
        int u = minimumDist(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < MAX_NODES; v++)

            if (!sptSet[v] && matrizAdjuntaCosto[u][v] && dist[u] != INT_MAX && dist[u] + matrizAdjuntaCosto[u][v] < dist[v]) {
  
                dist[v] = dist[u] + matrizAdjuntaCosto[u][v];
                parent[v] = u;            
            }
    }
    // print the constructed distance array
    ImprimirSolucionCosto(dist, parent, src, destiny);
  }

  void dijkstraTiempo(int src, int destiny) {
    int MAX_NODES = listaNodo.size();
    float dist[MAX_NODES]; 
    bool sptSet[MAX_NODES]; 
    int parent[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++)
        dist[i] = INF, sptSet[i] = false;

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < MAX_NODES; count++) {
        int u = minimumDistTiempo(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < MAX_NODES; v++)

            if (!sptSet[v] && matrizAdjuntaTiempo[u][v] && dist[u] != INT_MAX && dist[u] + matrizAdjuntaTiempo[u][v] < dist[v]) {
  
                dist[v] = dist[u] + matrizAdjuntaTiempo[u][v];
                parent[v] = u;            
            }
    }
    // print the constructed distance array
    ImprimirSolucionTiempo(dist, parent, src, destiny);
  }

  void BuscarCostoMinimo(string src, string destiny) {
    int indexSrc = BuscarNodo(src);
    int indexDest = BuscarNodo(destiny);
    dijkstraCosto(indexSrc, indexDest);
  }

  void BuscarTiempoMinimo(string src, string destiny) {
    int indexSrc = BuscarNodo(src);
    int indexDest = BuscarNodo(destiny);
    dijkstraTiempo(indexSrc, indexDest);
  }
};

/*
int main(){
  Matrix graph;
  graph.InsertarArista("USH", "SAL",5403, 10.1);
  graph.InsertarArista("SAL", "ROS",632, 24.6 );
  graph.InsertarArista("ROS", "ERT",843, 1004.5);
  graph.InsertarArista("MDP", "ERT",912, 6.5 );
  graph.InsertarArista("ERT", "MDZ",311, 10.0);
  graph.InsertarArista("MDZ", "RET",1082, 173.54);
  graph.InsertarArista("RET", "ROS",1987, 66.5);
  graph.InsertarArista("TUC", "MDP",382, 6.3 );
  graph.InsertarArista("COR", "TUC",111, 55.8 );
  graph.InsertarArista("SAL", "MDZ",2110, 5.8 );
  graph.ImprimirMatrizCosto();
  cout << "----------------------------------" << endl;
  graph.BuscarCostoMinimo("COR", "TUC");
  graph.BuscarCostoMinimo("USH", "SAL");
  graph.BuscarCostoMinimo("SAL", "MDZ");
  graph.BuscarCostoMinimo("USH", "TUC");
  graph.BuscarCostoMinimo("USH", "USH");
  graph.BuscarCostoMinimo("COR", "COR");
  cout << "----------------------------------" << endl;
  graph.ImprimirMatrizTiempo();
  cout << "----------------------------------" << endl;
  graph.BuscarTiempoMinimo("COR", "TUC");
  graph.BuscarTiempoMinimo("USH", "SAL");
  graph.BuscarTiempoMinimo("SAL", "MDZ");
  graph.BuscarTiempoMinimo("USH", "TUC");
  graph.BuscarTiempoMinimo("USH", "USH");
  graph.BuscarTiempoMinimo("COR", "COR");

}
*/