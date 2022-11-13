#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<sstream>
#include"../nodo/nodo.h"
#include"..\nodo\lista.cpp"
#include"..\nodo\nodo_clase.cpp"
using namespace std;

//Variables Globales
string clave = " ",nombre = " ",ciudad = " ",pais = " ",auxClave = " ";
float superficie = 0.0;
int cantidad_terminales = 0,destinos_nacionales = 0,destinos_internacionales = 0;
bool encontrado;
fstream archivo;

vector<Lista> terminales;


int obtenerIndice(std::string clave){
    terminales.resize(10);//tamaño del array
    int acc = 0;
    for (int i = 0; i < clave.size(); i++)
    {
        acc += clave[i];
    }
    
    return acc % terminales.size();

}

/*
void funcionHash(std::string clave, Terminal terminal){
    terminales.insert(terminales.begin() + obtenerIndice(clave),terminal);

}*/


//NO printea repetidos......
void altas(){
    bool repetido = false;
    cout<<"Ingrese la clave de la terminal:";
    cin>>auxClave;
    int indice = obtenerIndice(auxClave);//hash
    Lista lista = terminales[indice]; // Me posicion en la fila del vector.
    for (int i = 0; i < (lista.obtener_largo()+1); i++){
        if (lista.consulta(i).clave == auxClave){
            cout<<endl;
            cout<<"Ya existe una terminal con ese codigo en la tabla hash"<<endl;
            cout<<endl;
            repetido=true;
            break;
        }
    }
    if(repetido==false){
        Terminal terminal;
        cout<<"Ingresa el nombre de terminal: ";
        cin>>nombre;
        cout<<"Ingrese nombre de ciudad: ";
        cin>>ciudad;
        cout<<"Ingresa el nombre del pais: ";
        cin>>pais;
        cout<<"Ingresa la superficie(float): ";
        cin>>superficie;
        cout<<"Ingresa la cantidad de terminales: ";
        cin>>cantidad_terminales;
        cout<<"Ingresa la cantidad de destinos nacionales: ";
        cin>>destinos_nacionales;
        cout<<"Ingresa la destinos internacionales: ";
        cin>>destinos_internacionales;

        //Agrega los atributos a la terminal objeto.
        terminal.clave = auxClave;
        terminal.nombre = nombre;
        terminal.ciudad = ciudad;
        terminal.pais = pais;
        terminal.superficie = superficie;
        terminal.cantidad_terminales = cantidad_terminales;
        terminal.destinos_nacionales = destinos_nacionales;
        terminal.destinos_internacionales = destinos_internacionales;
        //lo pushea a la lista.
        terminales[indice].alta(terminal,1);
    }
}
//Fin funcion altas de terminales......


/*
void bajas(){
    
    cout<<"Ingresa la clave de la terminal a eliminar:";
    cin>>auxClave;
    int index = obtenerIndice(auxClave);
    Lista lista = terminales[index];
    for(int i = 0 ; i < lista.obtener_largo();i++){
        if (lista.consulta(i).clave == auxClave)
        {
            cout<<"Terminal eliminada"<<endl;
            //Se elimina el elemento por posicion;
            lista.baja(i);
            //terminales.erase(terminales.begin() + i);
            break;
        }
    }
}
*/
/*
void consultarTerminal(){
    cout<<"Ingresar clave de terminal a consultar:";
    cin>>auxClave;
    for (int i = 0; i < terminales.size(); i++){
        if (terminales[i].clave == auxClave){
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Datos de la terminal: "<<endl;
            cout<<"Clave: ";
            cout<<terminales[i].clave<<endl;
            cout<<"Nombre: ";
            cout<<terminales[i].nombre<<endl;
            cout<<"Ciudad: ";
            cout<<terminales[i].ciudad<<endl;
            cout<<"Pais: ";
            cout<<terminales[i].pais<<endl;
            cout<<"Superficie: ";
            cout<<terminales[i].superficie<<endl;
            cout<<"Cantidad de terminales: ";
            cout<<terminales[i].cantidad_terminales<<endl;
            cout<<"Cantidad de destinos nacionales: ";
            cout<<terminales[i].destinos_nacionales<<endl;
            cout<<"Cantidad de destinos internacionales: ";
            cout<<terminales[i].destinos_internacionales<<endl;
            cout<<"--------------------------------------------------"<<endl;
            return;
        }
    }
    cout<<"----------------------------------------------"<<endl;
    cout<<"Terminal no encontrada en la base datos"<<endl;
    cout<<"------------------------------------------"<<endl;
}
*/
void mostrarTerminales(){
    for (int i = 0; i < terminales.size(); i++)
    {
        cout<<"Posicion ->"<<i<<" ";
        terminales[i].mostrar();
    }

}



void leerTxt(){
    ifstream lectura;
    lectura.open("terminales.txt",ios::out|ios::in);
    string linea;
    if (lectura.is_open())
        {
            while (getline(lectura, linea))
            {
                stringstream ss(linea);
                ss >> clave >> nombre >> ciudad >> pais >> superficie >> cantidad_terminales 
                >> destinos_nacionales >> destinos_internacionales;
                //Se podria hacer una funcion que le pasen los parametros y cargue los datos.
                Terminal terminal;
                terminal.clave = clave;
                terminal.nombre = nombre;
                terminal.ciudad = ciudad;
                terminal.pais = pais;
                terminal.superficie = superficie;
                terminal.cantidad_terminales = cantidad_terminales;
                terminal.destinos_nacionales = destinos_nacionales;
                terminal.destinos_internacionales = destinos_internacionales;
                //funcionHash((terminal.clave),terminal);
                //terminales.push_back(terminal);
                int indice = obtenerIndice(terminal.clave);
                terminales[indice].alta(terminal,1);

            }
            lectura.close();
            for (int i = 0; i < terminales.size(); i++)
            {
                cout<<"Posicion :"<< i <<endl;
                terminales[i].mostrar();
            }
        }
        else
        {
            cout << "No se pudo abrir el archivo terminales.txt" << endl;
        }    
}

