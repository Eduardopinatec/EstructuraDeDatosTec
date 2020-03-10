#include <iostream>

using namespace std;

class Avion {
    public:
    int asientos = 0, asientoPas = 0;
    int *numPasajero;
    int *inicio;
    Avion (int numAsientos){
        asientos = numAsientos;
        numPasajero = new int [numAsientos];
        inicio = numPasajero;
    }
    void CheckIn (int numPas, int numAsiento){
        asientoPas = numAsiento;
        numPasajero[asientoPas] = numPas;
    }
    bool Vericar (int numPas){
        for (int i = 0; i <asientos; i++){
            if (numPasajero[i] == numPas){
                return true;
            }
        }
        return false;
    }
    ~Avion(){
        delete [] numPasajero;
    }
};

int main (){
    Avion am301 (10);
    am301.CheckIn(353, 0);
    am301.CheckIn(300123, 1);
    cout<<(am301.Vericar(353))<<endl;
    cout<<(am301.Vericar(1))<<endl;
}