#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
int main() {
    //string x = "This is C++.";
    //ofstream of("d:/tester.txt");
    //of << x;
    //of.close();

    string x;



    ifstream read("terminales.txt");
    read >> x;
    cout << x << endl ;
}
*/


int main(){
    string linea;
    std ::string clave = "";
    string renglon;
    ifstream terminales("terminales.txt");
    while (getline(terminales,linea))
    {
        cout<<linea<<endl;
        for(int i = 0; i <= 2;i++){
            clave += linea[i];
        }
        cout<<clave<<'\n';
        clave = "asdasdasdas";
    }
    
    return 0;
}
