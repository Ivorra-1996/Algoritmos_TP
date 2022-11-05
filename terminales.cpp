#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>

using namespace std;

//Variables Globales
string clave = " ",nombre = " ",ciudad = " ",pais = " ",auxClave = " ";
float superficie = 0.0;
int cantidad_terminales = 0,destinos_nacionales = 0,destinos_internacionales = 0;
bool encontrado;
fstream archivo;

class Terminal{
    public:
    string clave;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidad_terminales;
    int destinos_nacionales;
    int destinos_internacionales;
};

vector<Terminal> terminales;

unsigned long long CharToInt(char entrada)
{
	unsigned long long Salida;
	Salida = entrada;
	return Salida;
}



// Funcio de altas de terminales, crea la terminal.
void altas(){
    ofstream escritura; //variable de escritura del txt
    ifstream consulta; // variable de consulta
    bool repetido = false;
    escritura.open("terminales.txt",ios::out|ios::app); //abre el archivo txt con formato de entrada y salida.
    consulta.open("terminales.txt",ios::in); // y abre otro archivo del mismo txt, pero de consulta.
    if(escritura.is_open() /*&& consulta.is_open()*/){ //verifica si ambos estan abiertos.
        cout<<"Ingresa la Clave de la termnal: ";
        cin>>auxClave; //Ingresamos la clave auxiliar.
        for (int i = 0; i < terminales.size(); i++)
        {
            if (terminales[i].clave == auxClave)
            {
                cout<<endl;
                cout<<"Ya existe una terminal con ese codigo en la tabla hash"<<endl;
                cout<<endl;
                repetido=true;
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
            terminal.nombre = nombre;
            terminal.clave = auxClave;
            terminal.ciudad = ciudad;
            terminal.pais = pais;
            terminal.superficie = superficie;
            terminal.cantidad_terminales = cantidad_terminales;
            terminal.destinos_nacionales = destinos_nacionales;
            terminal.destinos_internacionales = destinos_internacionales;
            //lo pushea a la lista.
            terminales.push_back(terminal);
        }
        //antes de entrar al bucle consulta la primera clave.
            //consulta>>clave; // consulta la copia del archivo la primera clave y la inicializa.
            while(!consulta.eof()){ // el bucle deja de funcionar cuando no tiene mas renglones(sean escritos o vacios).
                consulta>>clave>>nombre>>ciudad>>pais>>superficie>>cantidad_terminales>>destinos_nacionales>>destinos_internacionales;
                if(clave == auxClave){
                    cout<<"---------------"<<endl;
                    cout<<"Ya Existe un Registro con esta Clave en txt"<<endl;
                    cout<<"-------------------"<<endl;
                    //break;
                    escritura.close();
                    consulta.close();
                    return;
                }
                consulta>>clave;
            }
           /*escritura<<auxClave<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
            <<destinos_internacionales<<endl;*/
            for (int i = 0; i < terminales.size(); i++)
            {
                escritura<< terminales[i].clave << " " << terminales[i].nombre << " " << terminales[i].ciudad << " " << terminales[i].pais << " " 
                << terminales[i].superficie << " " << terminales[i].cantidad_terminales << " " << terminales[i].destinos_nacionales << " " 
                << terminales[i].destinos_internacionales << endl;
            }
            cout<<"Registro Agregado."<<endl;

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


// Compila, falta probarlo.
long obtenerPosicion(std::string entrada){
	long Salida = 0;
	for(int i = 0;entrada[i] != '\0';i++){
		if(entrada[1+i] == '\0' && i==0)
			Salida += CharToInt(entrada[i]);
		else{
			if(i==0){
				Salida += CharToInt(entrada[i]);
				continue;
                }
			else{
                    int miChar = CharToInt(entrada[i]);
                    if(miChar>99){
                        Salida*=1000;
                        }
                    else if(miChar>9){
                        Salida*=100;
                        }
                    Salida += miChar;
                }	
		}
	}
	return Salida;
}



/*
void leerArchivo(){
    ifstream read("terminales.txt");
    consulta.open("terminales.txt",ios::in);

    archivo.open("terminales.txt",ios::in);//importamos y leemos el archivo
    
    int posicion;
    string entrada = "";
    if(archivo.is_open()){
        cout<<"___________________________________________________________"<<endl;
        while(!consulta.eof() && consulta.is_open()){
            entrada = read>>clave;
            posicion = obtenerPosicion(entrada);
            cout<<"posicion"<<posicion<<"";
        }
        cout<<"___________________________________________________________"<<endl;
        archivo.close();
    }
    else{
        cout<<"Error en leer el archivo...";
    }
    consulta.close();
}*/

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




