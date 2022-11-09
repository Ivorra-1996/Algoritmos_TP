#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<sstream>

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

vector<string>listaDePrueba;

unsigned long long CharToInt(char entrada)
{
	unsigned long long Salida;
	Salida = entrada;
	return Salida;
}



void altas(){
    bool repetido = false;
    cout<<"Ingre la clave de la terminal:";
    cin>>auxClave;
    for (int i = 0; i < terminales.size(); i++){
        if (terminales[i].clave == auxClave){
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
        terminales.push_back(terminal);
    }
}


/*
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
        for (int i = 0; i < terminales.size(); i++)
        {
            if (terminales[i].clave == auxClave)
            {
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
            terminales.push_back(terminal);
        }
        //antes de entrar al bucle consulta la primera clave.
        //consulta>>clave; // consulta la copia del archivo la primera clave y la inicializa.
        



        //NO lee bien el txt.....
        /*
        while(!consulta.eof()){ // el bucle deja de funcionar cuando no tiene mas renglones(sean escritos o vacios).
            consulta>>clave>>nombre>>ciudad>>pais>>superficie>>cantidad_terminales>>destinos_nacionales
            >>destinos_internacionales;
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
           escritura<<auxClave<<" "<<nombre<<" "<<ciudad<<" "<<pais<<" "<<superficie<<" "<<cantidad_terminales<<" "<<destinos_nacionales<<" "
            <<destinos_internacionales<<endl;
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
}*/



//Fin funcion altas de terminales......

void bajas(){
    
    cout<<"Ingresa la clave de la terminal a eliminar:";
    cin>>auxClave;
    for(int i = 0 ; i <terminales.size();i++){
        if (terminales[i].clave == auxClave)
        {
            cout<<"Terminal eliminada"<<endl;
            //Se elimina el elemento por posicion;
            terminales.erase(terminales.begin() + i);
            return;
        }
    }

    // Esto era para printear los elementos de la lista y ver que estan cargados. 
    for (int i = 0; i < terminales.size(); i++)
    {
        cout<<(terminales[i].clave)<<endl;
    }
    cout<<"Terminal no encontrada"<<endl;
}

/*
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
}*/


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

// Carga la terminales a la lista.
// No anda.
void cargarTerminales(){
    string linea;
    std ::string clave;
    ifstream terminales("terminales.txt");
    if(terminales.is_open()){
        while (getline(terminales,linea)){
            //cout<<linea<<endl;
            for(int i = 0; i <= 2;i++){
                clave += linea[i];
            }
            cout<<clave<<'\n';
            //cout<<obtenerPosicion(clave)/100000<<endl;
            listaDePrueba.insert(listaDePrueba.begin() + obtenerPosicion(clave),linea);
            //listaDePrueba[obtenerPosicion(clave)/100000] = linea;
            clave = "";
            listaDePrueba.push_back(linea);
        }
        cout<<"fuera del while"<<endl;
        for (int i = 0; i < listaDePrueba.size(); i++)
        {
            cout<<"for 2"<<endl;
            cout<<listaDePrueba[i]<<endl;
        }
    }
    else{
        cout<<"Error en leer el archivo...";
    }
    terminales.close();
    cout<<"Fin"<<endl;
}


void cantidadeDeTerminales(){
    int cant = 0;
    for (int i = 0; i < terminales.size(); i++){
        // cout<<"--------------------------------------------------"<<endl;
        // cout<<"Datos de la terminal: "<<endl;
        //cout<<"Clave: ";
        cout<<"Nombre: ";
        cout<<terminales[i].nombre<<endl;
        cant +=1;
        /*
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
        */
    }
    cout<<"Cantidad de terminales:";
    cout<<cant<<endl;
}

/*
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

*/

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
                terminales.push_back(terminal);
            }
            lectura.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo terminales.txt" << endl;
        }

        // Esto era para printear los elementos de la lista y ver que estan cargados. 
        for (int i = 0; i < terminales.size(); i++)
        {
            cout<<(terminales[i].clave)<<endl;
        }
    
}

