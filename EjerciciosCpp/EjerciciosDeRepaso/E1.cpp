#include <iostream>
#include <stdlib.h>

using namespace std;

class Avion {
    public:
        int *numPasajero;
        int numeroAsientos = 0;
        Avion (int numAsientos){
            numPasajero = new int [numAsientos]();
            numeroAsientos = numAsientos;
            for (int i = 0; i < numeroAsientos; i++){
                numPasajero[i] = 0;
            }
        }
        void checkIn (int numeroPasajero, int numeroAsiento){
            numPasajero[numeroAsiento] = numeroPasajero;
        }
        bool verificar (int numeroPasajero){
            for (int i = 0; i < numeroAsientos; i++){
                if (numPasajero[i]==numeroPasajero){
                    return true;
                }
            }
            return false;
        }
        ~Avion (){
            delete[] numPasajero;
        }
};

int main (){
    int numeroAsiento = 0, numCliente = 0;
    bool alta = false, busCliente = false, existe = false;
    int counter = 0;
    cout<<"Cuantos asientos tiene tu avion"<<endl;
    cin>>numeroAsiento;
    Avion Boing747 (numeroAsiento);
    cout<<"Deseas dar de alta a alguien? (Yes = 1, No = 0)"<<endl;
    cin>>alta;
    while (alta == true)
    {
        cout<<"Asiento: "<<counter<<endl;
        numCliente = rand()%99999999 + 100;
        cout<<"Numero de cliente: "<<numCliente<<endl;
        Boing747.checkIn(numCliente, counter);
        counter++;
        cout<<"Dar de alta a alguien más? (Yes = 1, No = 0)"<<endl;
        cin>>alta;
    }
    cout<<"Buscar cliente existente? (Yes = 1, No = 0)"<<endl;
    cin>>busCliente;
    while (busCliente == true)
    {
        cout<<"numero de cliente ?"<<endl;
        cin>>numCliente;
        existe = Boing747.verificar(numCliente);
        if (existe == true){
            cout<<"El cliente con numero de cliente: "<<numCliente<<" si existe."<<endl;
        }
        else{
            cout<<"el cliente con numero de cliente: "<<numCliente<<" no existe."<<endl;
        }
        cout<<"Buscar nuevamente (Yes = 1, No = 0)"<<endl;
        cin>>busCliente;
    }
    
}