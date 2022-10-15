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

int main(){
    leerArchivo();
    system("pause");
    return 0 ;
}
