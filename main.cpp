#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

//Variables Globales
string clave = " ",nombre = " ",ciudad = " ",pais = " ",auxClave = " ";
float superficie = 0.0;
int cantidad_terminales = 0,destinos_nacionales = 0,destinos_internacionales = 0;
bool encontrado;
fstream archivo;

// Funcio de altas de terminales, crea la terminal.
void altas(){
    ofstream escritura; //variable de escritura del txt
    ifstream consulta; // variable de consulta
    bool repetido = false;
    escritura.open("terminales.txt",ios::out|ios::app); //abre el archivo txt con formato de entrada y salida.
    consulta.open("terminales.txt",ios::in); // y abre otro archivo del mismo txt, pero de consulta.
    if(escritura.is_open() && consulta.is_open()){ //verifica si ambos estan abiertos.
        cout<<"Ingresa la Clave de la termnal: ";
        cin>>auxClave; //Ingresamos la clave auxiliar.
        consulta>>clave; // consulta la copia del archivo la primera clave y la inicializa.
        while(!consulta.eof()){ // el bucle deja de funcionar cuando no tiene mas renglones(sean escritos o vacios).
            //
            consulta>>nombre>>ciudad>>pais>>superficie>>cantidad_terminales>>destinos_nacionales>>destinos_internacionales;
            if(clave == auxClave){
                cout<<"Ya Existe un Registro con esta Clave"<<endl;
                repetido=true;
                break;
            }
            consulta>>clave;
        }
        if(repetido==false){
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
            escritura<<auxClave<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
            <<destinos_internacionales<<endl;
            cout<<"Registro Agregado."<<endl;
        }

    }else{
        cout<<"Error, el archivo NO se pudo abrir o NO ha sido creado"<<endl;
    }
    //Cierra ambos archivos para que no alla futuros errores y no queden abiertos.
    escritura.close();
    consulta.close();
}//Fin funcion altas de terminales......

void bajas(){
    ofstream archivoAux;
    ifstream lectura;
    string elecccion  = " ";
    encontrado = false;
    string auxClave = " ";
    archivoAux.open("Auxterminales.txt",ios::out);
    lectura.open("terminales.txt",ios::in);
    if(archivoAux.is_open() && lectura.is_open()){
        cout<<"Ingresa la clave de la terminal a dar de baja: ";
        cin>>auxClave;
        lectura>>clave;
        while (!lectura.eof())
        {
            lectura>>nombre>>ciudad>>pais>>superficie>>cantidad_terminales>>destinos_nacionales>>destinos_internacionales;
            if(auxClave == clave){
                encontrado = true;
                cout<<"____________________________________________________"<<endl;
                cout<<clave<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
                <<destinos_internacionales<<endl;
                cout<<"____________________________________________________"<<endl;
                
            }else{
                archivoAux<<clave<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
                <<destinos_internacionales<<endl;
            }
            lectura>>clave;
        }
        
    }else{
        cout<<"No se puedo abrir el archivo. Verifique que haya sido creado o no este dañado."<<endl;
    }
    if (encontrado == false)
    {
        cout<<"No se encontro ninguna terminal con esa clave"<<endl;
    }
    archivoAux.close();
    lectura.close();
    remove("terminales.txt");
    rename("Auxterminales.txt","terminales.txt");
}


void leerArchivo(){
    ofstream viajes;
    viajes.open("viajes.txt",ios::out);
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
    viajes.close();
}

void buscarTerminal(){
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
            lectura>>nombre>>ciudad>>pais>>superficie>>cantidad_terminales>>destinos_nacionales>>destinos_internacionales;//leyendo los campos del registro
            //Comparar cada registro para ver si es encontrado
            if(auxClave==clave){
                cout<<"____________________________________________________"<<endl;
                cout<<clave<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
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
                bajas();
                break;
            case 3:
                leerArchivo();
                break;
            case 4:
                buscarTerminal();
                break;
            case 5:
                cout<<"Programa Finalizado"<<endl;
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
}


// Problemas con los espacios a la hora de ingresar las terminales por alta.

