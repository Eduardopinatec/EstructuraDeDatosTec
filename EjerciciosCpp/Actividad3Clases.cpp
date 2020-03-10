#include <iostream>
#include <math.h>

using namespace std;

class Figura {
    public:
        double peri = 0.0, area = 0.0, ladoTF = 0.0, ladoCF = 0.0;
        virtual double calPerimetro()=0;
        virtual double calArea()=0;
};

class Triangulo: public Figura{
    public:
        Triangulo(double ladoT){
            ladoTF = ladoT;
        }
        double totalP = 0.0, totalA = 0.0;
        double calPerimetro (){
            totalP = ladoTF *3;
            return totalP;
        }
        double calArea(){
            totalA = (ladoTF * (ladoTF*sin(60)))/2;
            return totalA;
        }
};

class Cuadrado: public Figura{
    public: 
        Cuadrado(double ladoC){
            ladoCF = ladoC;
        }
        double totalP = 0.0, totalA = 0.0;
        double calPerimetro (){
            totalP = ladoCF * 4;
            return totalP;
        }
        double calArea(){
            totalA = ladoCF*ladoCF;
            return totalA;
        }
};

int main(){
    double ladoC = 0.0, ladoT = 0.0;
    cout<<"Dame el lado de tu cudrado: \n";
    cin>>ladoC;
    cout<<"Dame el lado de tu triangulo: \n";
    cin>>ladoT;
    Triangulo t (ladoT);
    Cuadrado c (ladoC);
    cout<<"El perimetro de tu cuadrado es: "<<endl;
}