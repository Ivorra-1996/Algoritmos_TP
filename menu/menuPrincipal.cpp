#include "menu.cpp"
#include "../viajes/menuViajes.cpp"


void menu(){
    int opcion=0;
    system("clear"); //PARA USAR EN MAC
    //system("CRL"); //CAMBIAR PARA USAR EN WINDOWS
    do{
        cout<<" "<<endl;
        cout<<"------- Menu principal -------"<<endl;
        cout<<"1. Terminales."<<endl;
        cout<<"2. Viajes."<<endl;
        cout<<"3. Salir."<<endl;
        cout<<"Que deseas hacer?: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                menuTerminales();
                break;
            case 2:  
                menuViajes();
                break;
            case 3:
                cout<<"Programa Finalizado."<<endl;
                break;
            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(opcion!=3);
}//Fin funcion menu


int main(){
    menu();
    return 0;
    system("PAUSE");
};
