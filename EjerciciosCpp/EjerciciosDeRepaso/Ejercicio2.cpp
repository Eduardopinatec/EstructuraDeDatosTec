#include <iostream>

using namespace std;

class Paciente {
    public: 
    int id = 0, edad = 0;
    string nombre = "", padecimiento = "";
};

class Hospital {
    private:
        int *camas;
        Paciente* pacientes;
        int camaDisponibles;
    public:
        int numCamas;
    Hospital (int nCamas){
        numCamas = nCamas;
        camas = new int [numCamas]();
        pacientes = new Paciente[numCamas]();
        camaDisponibles = 0;
    }
    void asignarPaciente (int id, string nombre, int edad){
        if (camaDisponibles >= numCamas){
            cout<<"No hay camas"<<endl;
            return;
        }
        camas[camaDisponibles]=id;
        pacientes[camaDisponibles].nombre = nombre;
        pacientes[camaDisponibles].edad = edad;
        pacientes[camaDisponibles].id = id;
        camaDisponibles++;
    }
    void asignarEnfermedad (int id, string enfermedad){
    int cama = busquedaSecuencial(camas, id, numCamas);
    if (cama!=1){
        paciente[cama].enfermedad=enfermedad;
    }
}
};