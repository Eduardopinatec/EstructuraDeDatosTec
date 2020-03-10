#include <iostream>

using namespace std;

class Ejemplo {
    public: 
        int a;
        Ejemplo (int valor){
            a = valor;
        }
        ~Ejemplo(){
            delete[] a;
        }
};

int main (){
    Ejemplo *e = new Ejemplo (10); //Cuando uso new regresa un apuntador.
    cout<<e->a<<endl;
}