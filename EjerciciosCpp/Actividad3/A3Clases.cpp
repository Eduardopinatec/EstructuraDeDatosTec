/* Author: Eduardo Alejandro Piña Pazos
Date: 27/02/2020 */
#include <iostream>
#include <math.h>

#define sen .866025

using namespace std;

//Creating Object Figura
class Figura {
    public: 
        virtual void calPerimetro ()=0;
        virtual void calArea()=0;
};

//Creating Cuadrado 
class Cuadrado : public Figura{
    public: 
        double ladoC = 0.0, perimetro = 0.0, area = 0.0;
        Cuadrado (double lado){
            ladoC = lado;
        }
        void calPerimetro(){
            perimetro = ladoC*4;
        }
        void calArea(){
            area = ladoC*ladoC;
        }
};

//Creating Triangulo
class Triangulo : public Figura{
    public:
        double ladoT = 0.0, perimetro = 0.0, area = 0.0;
        Triangulo (double lado){
            ladoT = lado;
        }
        void calPerimetro(){
            perimetro = ladoT*3;
        }
        void calArea(){
            cout<<ladoT<<endl;
            area = (ladoT * (sen*ladoT))/2;
            cout<<sin(60)<<endl;
        }
};

//Main funtion 
int main (){
    //Variables
    double ladoT = 0.0, ladoC = 0.0, area = 0.0, perimetro = 0.0;
    //Asking for the value of the figures
    cout<<"Porfavor dame el lado de tu cuadrado: \n";
    cin>>ladoC;
    cout<<"Porfavor dame el lado de tu triangulo: \n";
    cin>>ladoT;
    //Objects
    Cuadrado c (ladoC);
    Triangulo t (ladoT);
    //Calling the funtions of the objects for Cuadrado 
    c.calArea();
    c.calPerimetro();
    //Calling the funtions of Triangulo
    t.calArea();
    t.calPerimetro();
    cout<<"El perimetro de tu cuadrado es: "<<c.perimetro<<endl;
    cout<<"El area de tu triangulo es: "<<c.area<<endl;
    cout<<"El perimetro de tu triangulo es: "<<t.perimetro<<endl;
    cout<<"El area de tu triangulo es: "<<t.area<<endl;
}