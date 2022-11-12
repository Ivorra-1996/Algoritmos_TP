#include "../terminales/terminales.cpp"


void menu(){
    int opcion=0;
    do{
        cout<<"Manejo de Archivos en C++"<<endl;
        cout<<"1. Dar alta una terminal."<<endl;
        cout<<"2. Dar de baja una terminal."<<endl;
        cout<<"3. Consultar una terminal."<<endl;
        cout<<"4. Consultar todas las terminales."<<endl;
        cout<<"5. Salir."<<endl;
        cout<<"Que deseas hacer?.";
        cin>>opcion;
        switch(opcion){
            case 1:
                altas();
                break;
            case 2:
                bajas();
                break;
            case 3:
                //leerArchivo();
                consultarTerminal();
                break;
            case 4:
                //buscarTerminal();
                cantidadeDeTerminales();
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
    //ordenarLista();
    leerTxt();
    menu();
    //aca iria un ordena la lista.
    return 0;
    system("PAUSE");
}


// Problemas con los espacios a la hora de ingresar las terminales por alta.

// el programa cuando inicia, tiene que leer el archivo y carga todos los datos en la tabla terminales, 
// despues cuando se hace el alta, debe verificar que no este alguno duplicado en la tabla, 
// sino lo agrega lo mas bien a la tabla hash.
// Si se da de baja alguno lo saca de la tabla hash si existe.
// Hacer 2 funciones una que lea toda la tabla hash ordenada y la pritea por pantalla.
//  y otra que es cargar datos del txt a la tabla hash cuando inicia el programa.
// Cuando finaliza el programa todos los datos que estan cargados en la tabla hash y ordenados, los agrega en un txt auxiliar y luego le cambiamos
// el nombre por terminales.txt y lo reemplaza todo ordenado, esto lo hace a lo ultimo antes de finalizar el programa.