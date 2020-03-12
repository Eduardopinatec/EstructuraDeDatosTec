#include <iostream>

using namespace std;

class Libreria {
    public:
    int canLibros = 0;
    int *libros;
    int *prestado;
    Libreria(int cantidadLibros){
        canLibros = cantidadLibros;
        libros = new int [canLibros];
        prestado = new int[canLibros];
        for (int i = 0; i < canLibros; i++){
            libros[i]=i;
            //0 means that the book isn't loan and 1 means that it is loan.
            prestado[i]=0;
        }
    }
    Libreria(const Libreria& libreriaOriginal){
        canLibros = libreriaOriginal.canLibros;
        libros = new int [canLibros];
        prestado = new int[canLibros];
        for (int i = 0; i < canLibros; i++){
            libros[i]=libreriaOriginal.libros[i];
            prestado[i]=libreriaOriginal.prestado[i];
        }
    }
    void Prestar(int numLibro){
        //0 means that the book isn't loan and 1 means that it is loan.
        if (prestado[numLibro]==1){
            cout<<"El libro ya esta prestado."<<endl;
        }
        else if (numLibro>canLibros){
            cout<<"No se tiene ese libro en esta librería"<<endl;
        }
        else {
            cout<<"Prestamo autorizado."<<endl;
            prestado[numLibro]=1;
        }
        
    }
    void Regresar(int numLibro){
        //0 means that the book isn't loan and 1 means that it is loan.
        prestado[numLibro]=0;
        cout<<"Regreso actualizado"<<endl;
    }
};

int main (){
    int numLibros = 0, libroP = -1;
    bool prestar = false, regresar = false, proceso = false;
    cout<<"Cuantos libros tiene tu librería?"<<endl;
    cin>>numLibros;
    Libreria porrua (numLibros);
    do {
        cout<<"Deseas prestar algun libro (yes = 1, no = 0)"<<endl;
        cin>>prestar;
        cout<<"Deseas regresar algun libro (yes = 1, no = 0)"<<endl;
        cin>>regresar;
        if (prestar == 1){
            cout<<"Que libro deseas prestar?"<<endl;
            cin>>libroP;
            porrua.Prestar(libroP-1);
        }
        if (regresar == 1){
            cout<<"Que libro deseas regresar?"<<endl;
            cin>>libroP;
            porrua.Regresar(libroP-1);
        }
        cout<<"Deseas hacer otro proceso? (yes = 1, no = 0)"<<endl;
        cin>>proceso;
    }while (proceso);
    Libreria lalo = porrua;
    for (int i = 0; i < numLibros; i++){
        cout<<porrua.prestado[i]<<endl;
    }
    for (int i = 0; i < numLibros; i++){
        cout<<lalo.prestado[i]<<endl;
    }
}