#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

fstream archivo;

void leerArchivo(){
    archivo.open("terminales.txt",ios::in);//importamos y leemos el archivo
    if(archivo.is_open()){
        string linea;
        while(getline(archivo,linea)){
            cout<<linea<<endl;
        }
        archivo.close();
    }
    else{
        cout<<"Error en leer el archivo...";
    }
}

void escribirArchivo(){
    archivo.open("terminales.txt",ios::out);
    if(archivo.is_open()){
        cout<<"Escriba exit para terminar el archivo..\n";
        string salida_linea_texto;
        while(true){
            string linea; //lee cada linea
            getline(cin,linea);
            if(linea == "exit"){
                break;
            }
            salida_linea_texto += linea+'\n';    
        }
        archivo<<salida_linea_texto;
        archivo.close();
    }
    else{
        cout<<"No se encontro el archivo";
    }
}

int main(){
    leerArchivo();
    escribirArchivo();
    leerArchivo();
    system("pause");
    return 0 ;
}
