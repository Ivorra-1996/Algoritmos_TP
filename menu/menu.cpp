#include "../terminales/terminales.cpp"


void menuTerminales(){
    int opcion=0;
    system("clear"); //PARA USAR EN MAC
    //system("CRL"); //CAMBIAR PARA USAR EN WINDOWS
    do{
        cout<<" "<<endl;
        cout<<"------- Menu terminales -------"<<endl;
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
                system("clear");
                cout<<"------- Dar alta una terminal -------"<<endl;     
                altas();
                break;
            case 2:
                system("clear");
                cout<<"------- Dar de baja una terminal -------"<<endl;     
                bajas();
                break;
            case 3:
                system("clear");
                cout<<"------- Consultar una terminal -------"<<endl;     
                consultarTerminal();
                break;
            case 4:
                system("clear");
                cout<<"------- Distribucion tabla hash de terminales -------"<<endl;     
                mostrarTerminalesHash();
                break;
            case 5:
                system("clear");
                cout<<"------- Consultar todas las terminales y sus datos -------"<<endl;     
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
    menuTerminales();
    return 0;
    system("PAUSE");
};

