#include <iostream>

using namespace std;

class Animal {
    public:
        virtual void sonido()=0;//Metodos virtuales solo en clases.
};

class Perro : public Animal{
    public:
        void sonido();
};

void Perro::sonido(){
    cout<<"guau"<<endl;
}

int main (){
    Perro p;
    p.sonido();
    return 0;
}