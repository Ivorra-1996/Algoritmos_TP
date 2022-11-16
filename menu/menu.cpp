#include "../terminales/terminales.cpp"


void menu(){
    int opcion=0;
    system("clear"); //PARA USAR EN MAC
    //system("CRL"); //CAMBIAR PARA USAR EN WINDOWS
    do{
        cout<<"Manejo de Archivos en C++"<<endl;
        cout<<"1. Dar alta una terminal."<<endl;
        cout<<"2. Dar de baja una terminal."<<endl;
        cout<<"3. Consultar una terminal."<<endl;
        cout<<"4. Distribucion tabla hash de terminales."<<endl;
        cout<<"5. Consultar todas las terminales y sus datos."<<endl;
        cout<<"6. Salir."<<endl;
        cout<<"Que deseas hacer?: ";
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
                mostrarTerminalesHash();
                break;
            case 5:
                mostrarTerminalesCompletas();
                break;
            case 6:
                cout<<"Programa Finalizado. Se guardan las modificaciones"<<endl;
                escribirTxt();
                break;
            default:
                cout<<"¡Opcion Incorrecta!"<<endl;
        }
    }while(opcion!=6);
}//Fin funcion menu


int main(){
    leerTxt();
    menu();
    return 0;
    system("PAUSE");
};
