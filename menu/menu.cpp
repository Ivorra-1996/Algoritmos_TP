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
// SE DEBERIA BORRA LOS OBJETOS EN LAS VARIABLES..........
// SE DEBERIA HACER UN CONTRO DE QUE NO AGREGUE DUPLICADOS POR LA FUNCION leerTxt()....
