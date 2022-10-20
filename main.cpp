#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

//Funciones...
void altas();




void salir();
void menu();
//Variables Globales
string clave = " ",nombreDeCiudad = " ",pais = " ",auxClave = " ";
float superficie = 0.0;
int cantidad_terminales = 0,destinos_nacionales = 0,destinos_internacionales = 0;

fstream archivo;

void altas(){
    ofstream escritura;
    ifstream consulta;
    bool repetido = false;
    escritura.open("terminales.txt",ios::out|ios::app);
    consulta.open("terminales.txt",ios::in);
    if(escritura.is_open() && consulta.is_open()){
        cout<<"Ingresa la Clave de la termnal: ";
        cin>>auxClave;
        consulta>>clave;
        while(!consulta.eof()){
            consulta>>nombreDeCiudad>>pais>>superficie>>cantidad_terminales>>destinos_nacionales>>destinos_internacionales;
            if(clave == auxClave){
                cout<<"Ya Existe un Registro con esta Clave"<<endl;
                repetido=true;
                break;
            }
            consulta>>clave;
        }
        if(repetido==false){
            cout<<"Ingresa el nombre de ciudad: ";
            cin>>nombreDeCiudad;
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
            escritura<<auxClave<<" "<<nombreDeCiudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
            <<destinos_internacionales<<endl;
            cout<<"Registro Ageragado"<<endl;
        }

    }else{
        cout<<"Error, el Archivo No se Pudo Abrir o No ha sido Creado"<<endl;
    }
    escritura.close();
    consulta.close();
}//Fin funcion altas de terminales......


void leerArchivo(){
    archivo.open("terminales.txt",ios::in);//importamos y leemos el archivo
    if(archivo.is_open()){
        string linea;
        cout<<"___________________________________________________________"<<endl;
        while(getline(archivo,linea)){
            cout<<linea<<endl;
        }
        cout<<"___________________________________________________________"<<endl;
        archivo.close();
    }
    else{
        cout<<"Error en leer el archivo...";
    }
}



void salir(){
    cout<<"Programa Finalizado"<<endl;
}

void menu(){
    int opcion=0;
    do{
        cout<<"Manejo de Archivos en C++"<<endl;
        cout<<"1. Altas"<<endl;
        cout<<"2. Bajas"<<endl;
        cout<<"3. Consultas"<<endl;
        cout<<"4. Buscar un Registro"<<endl;
        cout<<"5. Modificaciones"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Que deseas hacer? ";
        cin>>opcion;
        switch(opcion){
            case 1:
                altas();
            break;
            case 2:
                //bajas();
            break;
            case 3:
                leerArchivo();
            break;
            case 4:
                //buscar();
            break;
            case 5:
                //modificaciones();
            break;
            case 6:
                salir();
            break;
            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(opcion!=6);
}//Fin funcion menu


int main(){
    menu();
    return 0;
    system("PAUSE");
}




// codigo viejo 
/*

void modificaciones(){
    ofstream auxiliar;
    ifstream lectura;
    bool encontrado=false;
    string claveDeTerminal =" ";
    char terminal;
    auxiliar.open("auxiliar.txt",ios::out);
    lectura.open("alumnos.txt",ios::in);
    if(auxiliar.is_open() && lectura.is_open()){
        cout<<"Ingresa la clave de la terminal que desea modificar; ";
        cin>>claveDeTerminal;
        

    }
    else{
        cout<<"Error al abrir el archivo"<<endl;
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
}*/
