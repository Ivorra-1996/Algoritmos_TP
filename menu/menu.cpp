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
                consultarTerminal();
                break;
            case 4:
                mostrarTerminales();
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
    leerTxt();
    menu();
    return 0;
    system("PAUSE");
};


// COMENTARIOS EXTRAS:
// 1- SE DEBERIA BORRA LOS OBJETOS EN LAS VARIABLES..........
// 2- SE DEBERIA HACER UN CONTRO DE QUE NO AGREGUE DUPLICADOS POR LA FUNCION leerTxt()....
// 3- SE DEBERIA PODER HACER QUE UNA VEZ QUE FINALICE EL PROGRAMA, ANTES DEBA CARGAR TODO LO QUE TIENE EN EL 
// VECTOR TERMINALES EN UN NUEVO TXT Y QUE PISE EL VIEJO TXT TERMINALES, POR ENDE QUEDARIA ORDENADO. PARA UTILIZARLO
// EN VIAJES......