#include "leerArchivo.cpp"
#include<string.h>


using namespace std;

void menu(){

  Archivos archivo;
  archivo.leerTxt();
  Matrix graph;
  string src, destiny;
  
  for (int i; i < archivo.vectorViajes.size(); i++){
    string origen = archivo.vectorViajes[i].origen;
    string destino = archivo.vectorViajes[i].destino;
    int costo = archivo.vectorViajes[i].costo;
    float tiempo = archivo.vectorViajes[i].tiempo;
    graph.InsertarArista(origen, destino, costo, tiempo);
  }

    int opcion=0;
    system("clear"); //PARA USAR EN MAC
    //system("CRL"); //CAMBIAR PARA USAR EN WINDOWS
    do{
        cout<<" "<<endl;
        cout<<"------- Menu viajes -------"<<endl;
        cout<<"1. Ver matriz de costos."<<endl;
        cout<<"2. Ver matriz de tiempos."<<endl;
        cout<<"3. Calcular viaje mas economico."<<endl;
        cout<<"4. Calcular viaje mas rapido."<<endl;
        cout<<"5. Salir."<<endl;
        cout<<"Que deseas hacer?: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                system("clear");
                cout<<"------- Matriz de costos -------"<<endl;            
                graph.ImprimirMatrizCosto();
                break;
            case 2:
                system("clear"); 
                cout<<"------- Matriz de tiempos -------"<<endl;    
                graph.ImprimirMatrizTiempo();
                break;
            case 3:
                system("clear");
                cout<<"------- Buscar costo minimo -------"<<endl; 
                cout<<"Ingrese la clave de la terminal de origen:";
                cin>>  src;
                cout<<"Ingrese la clave de la terminal de destino:";
                cin>>  destiny;
                graph.BuscarCostoMinimo(src, destiny);
                break;
            case 4:
                system("clear");
                cout<<"------- Buscar tiempo minimo -------"<<endl; 
                cout<<"Ingrese la clave de la terminal de origen:";
                cin>>  src;
                cout<<"Ingrese la clave de la terminal de destino:";
                cin>>  destiny;
                graph.BuscarTiempoMinimo(src, destiny);
                break;
            case 5:
                system("clear"); 
                cout<<"Programa Finalizado."<<endl;
                break;
            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(opcion!=5);
}//Fin funcion menu


int main(){
    menu();
    return 0;
    system("PAUSE");
};
