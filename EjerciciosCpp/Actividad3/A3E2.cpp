#include <iostream>

using namespace std;

class Estudiante {
    public:
        string nombre = "";
        int matricula  = 0;
        Estudiante (string n, int m){
            nombre = n;
            matricula = m;
        }
        Estudiante (const Estudiante& ho){
            size = ho.size;
            horario = new int [size]();
            horarioI = horario;
            for (int i = 0; i<size; i++)
            {
                horario[i]=ho.horario[i];
            }
        }
        void crearHorario(int tamano){
            size = tamano*2;
            horario = new int [size]();
            horarioI = horario;
        }
        void setHorario(int hora){
            *horario++ = hora;
        }
        void cambiarHorario(int clase, int nuevoHI, int nuevoHF){
            int total = (clase-1)*2;
            for (int i = 0; i<total; i++)
            {
                *horario++;
            }
            *horario++ = nuevoHI;
            *horario=nuevoHF;
            resetPointer();
        }
        void resetPointer(){
            horario = horarioI;
        }
        int getHorario(){
            int i = 0;
            i = *horario++;
            return i;
        }
        ~Estudiante(){
            delete[] horario;
        }
    private: 
        int *horario, *horarioI;
        int size;
};

int main(){
    int materia = 0, horaI = 0, horaF = 0, clase = 0;
    string cambio = "";
    Estudiante Eduardo ("Eduardo", 01027604);
    cout<<"Cuantas materias vas a llevar? "<<endl;
    cin>>materia;
    Eduardo.crearHorario(materia);
    cout<<"Ingresa el horario de tus clases, en horario militar, escribe la hora a la que empieza la clase, seguido por la hora que termina"<<endl;
    for (int i = 0; i < materia; i++)
    {
        cout<<"Inicio de clase: ";
        cin>>horaI;
        Eduardo.setHorario(horaI);
        cout<<"Fin de clase: ";
        cin>>horaI;
        Eduardo.setHorario(horaI);
    }
    Eduardo.resetPointer();
    cout<<"El horario de "<<Eduardo.nombre<<" es: "<<endl;
    for (int i = 0; i < materia; i++)
    {
        cout<<"Clase "<<i+1<<": "<<Eduardo.getHorario()<<" a "<<Eduardo.getHorario()<<endl;
    }
    Eduardo.resetPointer();
    Estudiante Lorenzo = Eduardo;
    Lorenzo.nombre = "Lorenzo";
    Lorenzo.matricula = 01027605;
    cout<<"El horario de "<<Lorenzo.nombre<<" es: "<<endl;
    for (int i = 0; i < materia; i++)
    {
        cout<<"Clase "<<i+1<<": "<<Lorenzo.getHorario()<<" a "<<Lorenzo.getHorario()<<endl;
    }
    Lorenzo.resetPointer();
    cout<<"Deseas hacer algun cambio en el horario de Lorenzo?"<<endl;
    cin>>cambio;
    if (cambio=="si")
    {
        cout<<"Que clase deseas modificar? "<<endl;
        cin>>clase;
        cout<<"Ingresa la hora del inicio de la clase "<<clase<<":"<<endl;
        cout<<"Inicio de la clase: ";
        cin>>horaI;
        cout<<"Fin de la clase: ";
        cin>>horaF;
        Lorenzo.cambiarHorario(clase, horaI, horaF);
    }
    for (int i = 0; i < materia; i++)
    {
        cout<<"Clase "<<i+1<<": "<<Lorenzo.getHorario()<<" a "<<Lorenzo.getHorario()<<endl;
    }
    for (int i = 0; i < materia; i++)
    {
        cout<<"Clase "<<i+1<<": "<<Eduardo.getHorario()<<" a "<<Eduardo.getHorario()<<endl;
    }
}