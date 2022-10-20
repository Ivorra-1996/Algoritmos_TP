#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

//Funciones...
void altas();
void bajas();
void buscar();
void consultas();
void salir();
void menu();
//Variables Globales
string clave = " ",nombreDeCiudad = " ",pais = " ",auxClave = " ";
float superficie = 0.0;
int cantidad_terminales = 0,destinos_nacionales = 0,destinos_internacionales = 0;

bool encontrado;



int main(){
    menu();
    return 0;
    system("PAUSE");
}
void menu(){
    int opcion=0;
    do{
        cout<<"Manejo de Archivos en C++"<<endl;
        cout<<"1. Altas"<<endl;
        cout<<"2. Bajas"<<endl;
        cout<<"3. Consultas"<<endl;
        cout<<"4. Buscar un Registro"<<endl;
        cout<<"5. Salir"<<endl;
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
                //consultas();
            break;
            case 4:
                buscar();
                cout<<"entro al menu opcion 4"<<endl;
            break;
            case 5:
                salir();
            break;
            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(opcion!=5);
}//Fin funcion menu
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



void bajas(){
}

void buscar(){
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("terminales.txt",ios::out|ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    bool encontrado = false;
    cout<<"Entro a buscar"<<endl;
    if(lectura.is_open()){
        cout<<"Ingresa la Clave de la terminal que deseas Buscar: ";
        cin>>auxClave;
        lectura>>clave;//lectura adelantada

        while(!lectura.eof()){
            lectura>>nombreDeCiudad>>pais>>superficie>>cantidad_terminales>>destinos_nacionales>>destinos_internacionales;//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            if(auxClave==clave){
                cout<<"____________________________________________________"<<endl;
                cout<<clave<<" "<<nombreDeCiudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
                <<destinos_internacionales<<endl;
                cout<<"_____________________________________________________"<<endl;
                encontrado=true;
            }
            lectura>>clave;//lectura adelantada, sigue consultado las siguientes claves.
        }
        if(encontrado==false){
            cout<<"No hay registros con la Clave "<<auxClave<<endl;
        }
    }else{
        cout<<"No se pudoAbrir el Archivo, aun no ha sido Creado"<<endl;
    }
    //cerrando el archivo
    lectura.close();
}





void salir(){
    cout<<"Programa Finalizado"<<endl;
}