#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<sstream>
#include"../nodo/nodo.h"
#include"../nodo/lista.cpp"
#include"../nodo/nodo_clase.cpp"
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

Terminal crearTerminal(string clave,string nombre,string ciudad,string pais,float superficie,int cantidad_terminales,
    int destinos_nacionales,int destinos_internacionales){
    Terminal terminal;
    terminal.clave = clave;
    terminal.nombre = nombre;
    terminal.ciudad = ciudad;
    terminal.pais = pais;
    terminal.superficie = superficie;
    terminal.cantidad_terminales = cantidad_terminales;
    terminal.destinos_nacionales = destinos_nacionales;
    terminal.destinos_internacionales = destinos_internacionales;
    return terminal;
}


void altas(){
    string opcion;
    bool repetido = false;
    cout<<"Ingrese la clave de la terminal:";
    cin>>auxClave;
    int indice = obtenerIndice(auxClave);//hash
    for (int i = 0; i < (terminales[indice].obtener_largo()); i++){
        if (terminales[indice].consulta(i+1).clave == auxClave){
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
        terminal = crearTerminal(auxClave,nombre,ciudad,pais,superficie,cantidad_terminales,destinos_nacionales
        ,destinos_internacionales);
        terminales[indice].alta(terminal,1);
    }
}
//Fin funcion altas de terminales......


void bajas(){
    cout<<"Ingresa la clave de la terminal a eliminar:";
    cin>>auxClave;
    int index = obtenerIndice(auxClave);//Me sirve para possicionarme en una poscion del vector..
    for(int i = 0 ; i < terminales[index].obtener_largo();i++){
        if (terminales[index].consulta(i+1).clave == auxClave)
        {
            cout<<endl;
            cout<<"Terminal eliminada"<<endl;
            cout<<endl;
            terminales[index].baja(i+1);
            return;
        }
    }
    cout<<"----------------------------------------------"<<endl;
    cout<<"Terminal no encontrada en la base datos"<<endl;
    cout<<"------------------------------------------"<<endl;
}


void consultarTerminal(){
    cout<<"Ingresar clave de terminal a consultar:";
    cin>>auxClave;
    int index = obtenerIndice(auxClave);
    for (int i = 0; i < (terminales[index].obtener_largo()); i++)
    {
        if (terminales[index].consulta(i+1).clave == auxClave){
            Terminal terminal = terminales[index].consulta(i+1);
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Datos de la terminal: "<<endl;
            cout<<"Clave: ";
            cout<<terminal.clave<<endl;
            cout<<"Nombre: ";
            cout<<terminal.nombre<<endl;
            cout<<"Ciudad: ";
            cout<<terminal.ciudad<<endl;
            cout<<"Pais: ";
            cout<<terminal.pais<<endl;
            cout<<"Superficie: ";
            cout<<terminal.superficie<<endl;
            cout<<"Cantidad de terminales: ";
            cout<<terminal.cantidad_terminales<<endl;
            cout<<"Cantidad de destinos nacionales: ";
            cout<<terminal.destinos_nacionales<<endl;
            cout<<"Cantidad de destinos internacionales: ";
            cout<<terminal.destinos_internacionales<<endl;
            cout<<"--------------------------------------------------"<<endl;
            return;
        }
    }
    cout<<"----------------------------------------------"<<endl;
    cout<<"Terminal no encontrada en la base datos"<<endl;
    cout<<"------------------------------------------"<<endl;
};


void mostrarTerminalesHash(){
    for (int i = 0; i < terminales.size(); i++)
    {
        cout<<"Posicion ->"<<i<<" ";
        terminales[i].mostrar();
    }

}

void mostrarTerminalesCompletas(){
    for (int i = 0; i < terminales.size(); i++)
    {
        terminales[i].mostrarTodo();
    }

}

string retornarTodasLasTerminales(){
    string term = "";
    for (int i = 0; i < terminales.size(); i++)
    {
        term = term + terminales[i].retornaTodo();
    }
    return term;
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
                Terminal terminal = crearTerminal(clave,nombre,ciudad,pais,superficie,
                cantidad_terminales,destinos_nacionales,destinos_internacionales);
                int indice = obtenerIndice(terminal.clave);
                terminales[indice].alta(terminal,1);

            }
            lectura.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo terminales.txt" << endl;
        }    
}

void escribirTxt(){
    ofstream archivo;
    //archivo.open("terminales_salida.txt", ios::out|ios::in);
    archivo.open("terminales_salida.txt", ios::out | ios::trunc);
    string linea;
    if (archivo.is_open()) {
        archivo << retornarTodasLasTerminales();
        archivo << endl;
    }
    archivo.close();
}

