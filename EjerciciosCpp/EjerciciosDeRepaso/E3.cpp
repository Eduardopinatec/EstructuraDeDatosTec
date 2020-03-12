#include <iostream>

using namespace std;

//id, nombre, edad y padecimiento.

class Paciente {
    public: 
        int id = 0;
        int edad = 0;
        string nombre = "";
        string padecimiento = "";
};

int busqueda (int *a, int buscando, int tamaño){
    for (int i = 0; i < tamaño; i++ ){
        if (a[i]==buscando){
            return i;
        }
    }
    return -1;
}

class Hospital{
    private:
        int *numCamPasiente;
        string *pacientes;
    public: 
        int numCamas = 0;
        void ingresarPaciente(int id, string nombre, int edad, string enfermedad){
            int index = 
        }
};

int main (){

}