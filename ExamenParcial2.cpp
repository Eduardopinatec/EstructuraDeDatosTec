#include <iostream>
#include <stdlib.h>
#include "sort.cpp"//Import the file sort
#include "AlgoritmosDeBusqueda.cpp"//Import file busqueda
#include "vector.cpp"//Import filel vector
#include "linkList.cpp"//Import file linkList

using namespace std;

/*typedef struct node{
    int turno;
    struct node *next;    
}node;*/

//Creating class Banco
template <class T>
class Banco : public Vector<T>{
    public:
        //Creating all the objects
        Vector <int> numeroCliente;
        Vector <int> dinero;
        LinkedList <int> linklist;
        QuickSort <int> quickSort;
        MergeSort <int> mergeSort;
        //Creating method for adding clients
        int agregarCliente (int numCliente, int dineroAgregar){
            int existe = -2;
            //Search if the client already exists.
            existe = buscar(numCliente, numeroCliente.a);
            if (existe == -1){
                //If the client dosen't exist append the new client number and append also the amount of money for that account
                numeroCliente.append(numCliente);
                dinero.append(dineroAgregar);
                cout<<"Cliente: "<<numCliente<<" Agregado exitosamente."<<endl;
                //dinero.insert(dineroAgregar, busquedaBinaria(numeroCliente.a, 0, numeroCliente.size, numCliente));
            }
            else{
                //If the client already exist
                cout<<"El numero de cliente ya existe"<<endl;
            }   
            //Calling funtion to order the new appends
            ordenar();
        }
        void ordenar (){
            //Using Quick Sort to sort the elements, but sorting this by client number, not by money in there account, and
            //the money in the account keeps the same position that the client number position.
            quickSort.sort(numeroCliente.a, dinero.a, numeroCliente.count);
        }
        //Searching with Binary Search.
        int buscar (int num, T *c){
            return (busquedaBinaria(c, 0, numeroCliente.count, num));
        }
        //Unsubscribe a client.
        void bajaCliente (int numCliente){
            int index = -2, deuda = -1;
            //Searching for the client number.
            index = buscar(numCliente, numeroCliente.a);
            if (index == -1){
                //If the client dosen't exist.
                cout<<"El cliente no Existe"<<endl;
            }
            else{
                //If the client exist.
                //Searching for the balance of that account
                deuda = dinero.a[index];
                if (deuda == 0){
                    //If the client number has no balance or equals to 0
                    //Moving the last element added to the position that what to be delete.
                    numeroCliente.a[index] = numeroCliente.a[numeroCliente.count-1];
                    //Moving the money from the account that we just move.
                    dinero.a[index]= dinero.a[dinero.count-1];
                    //Setting the values of account number and money to default
                    numeroCliente.a[numeroCliente.count-1]=-1;
                    dinero.a[dinero.count-1]=-1;
                    //Making the respective adjustment for the counts in clients number and money.
                    numeroCliente.count--;
                    dinero.count--;
                    //Sorting the element that we just move.
                    ordenar();
                    cout<<"Cliente: "<<numCliente<<" dado de baja."<<endl;

                }
                else {
                    //If the client has money in there accounts.
                    cout<<"El cliente: "<<numCliente<<" debe: "<<deuda<<" Por lo que no se puede dar de baja"<<endl;
                }
            }
        }
        void deposito(int numCliente, int cantidad){
            //Searching for the client
            int index = buscar(numCliente, numeroCliente.a);
            if (index == -1){
                //If the client dosen't exist.
                cout<<"El cliente no existe."<<endl;
            }
            else{
                //Adding the money to the client account 
                dinero.a[index]+=cantidad;
                cout<<"Deposito de "<<cantidad<<" exitoso a cuenta del cliente "<<numCliente<<endl;
                //cout<<"Saldo: "<<dinero.a[index]<<endl;
            }
        }
        void retirar (int numCliente, int cantidad){
            //Searching for the client number
            int index = buscar(numCliente, numeroCliente.a);
            if (index == -1){
                //If the client dosen't exist.
                cout<<"El cliente no existe."<<endl;
            }
            else{
                //If the client exist.
                if (cantidad > dinero.a[index]){
                    //The Client exist but it dosen't have all the money that he wants to withdraw
                    cout<<"Cliente "<<numCliente<<" no tiene "<<cantidad<<" para retirar."<<endl;
                    //cout<<"Saldo: "<<dinero.a[index]<<endl;
                }
                else{
                    //Successful withdraw
                    dinero.a[index]-=cantidad;
                    cout<<"Retiro de "<<cantidad<<" exisitoso de cuenta del cliente "<<numCliente<<endl;
                    //cout<<"Saldo: "<<dinero.a[index]<<endl;
                }
            }
        }
        void asignarTurno (int numCliente){
            //Finding if this is a client
            if (buscar(numCliente, numeroCliente.a)==-1){
                //The client dosen't exist.
                cout<<"Cliente no existe"<<endl;
            }
            else{
                //The client exist and he/she will receive a turn
                linklist.append(numCliente);
            }
        }
        int atenderSiguiente (){
            //Calling the next turn
            int turno = -1;
            if (linklist.root==NULL){
                cout<<"No hay clientes por atentender en este momento."<<endl;
                return -1;
            }
            else{
                turno = linklist.imprimirTurno();
                cout<<"Turno del cliente: "<<linklist.imprimirTurno()<<endl;
                linklist.removePos(0);
                return turno;
            }
        }
        void principalesClientes (){
            //Seeing if the bank at least have more than 10 clients.
            //if (numeroCliente.count>10){
                //The bank has more than 10 clients.
                int pos = 0, count = dinero.count;
                //Creating a new array for the money so we can sort that data.
                int prinClientes[count];
                //Coping all the info that the money array has to the new array.
                for (int i = 0; i < count; i++){
                    prinClientes[i]=dinero.a[i];
                }
                //Sorting the new array.
                mergeSort.sort(prinClientes, count);
                //Seeing the biggest numbers from money array.
                int j = 0;
                for (int i = count-1; i >= count-numeroCliente.count; i--){
                    j++;
                    //Searching the exact number form the new array in the money array and getting the position so 
                    //we can see which clients is.
                    pos = busquedaSecuencial(dinero.a, prinClientes[i], count);
                    //Printing the top 10 clients that have more money in the bank.
                    cout<<"Lugar "<<j<<": Cliente: "<<numeroCliente.a[pos]<<" Con la cantidad de: "<<dinero.a[pos]<<endl;
                }
                //delete[] prinClientes;
            //}
            //else{
                //The bank dosen't have more than 10 clients.
              //  cout<<"No tienes mas de 10 clientes"<<endl;
            //}
        }
        void consultarBalance (int numCuenta){
            int index = buscar (numCuenta, numeroCliente.a);
            if ( index == -1){
                cout<<"El numero de cuenta de cliente no existe."<<endl;
            }
            else{
                int cantidad = dinero.a[index];
                cout<<"Cliente: "<<numCuenta<<" balance: "<<cantidad<<endl;
            }
        }

};

//Main Method
int main(){
    Banco <int> b;
    b.agregarCliente(100, 1500.0);
    b.agregarCliente(200, 300.15);
    b.agregarCliente(300, 100.0);
    b.agregarCliente(20, 100351.0);
    int turno=b.atenderSiguiente();
    b.asignarTurno(200);
    b.asignarTurno(100);
    b.asignarTurno(300);
    turno=b.atenderSiguiente();
    b.consultarBalance(turno);
    b.deposito(turno, 100);
    b.consultarBalance(turno);
    turno=b.atenderSiguiente();
    b.consultarBalance(turno);
    b.retirar(turno, 1000);
    b.consultarBalance(turno);
    b.retirar(turno,1000);
    b.bajaCliente(turno);
    b.retirar(turno, 500);
    b.bajaCliente(turno);
    b.bajaCliente(turno);
    b.principalesClientes();
}

/*int main (){


    
    //Initialize the random seed
    srand (time(NULL));
    //Creating my new object.
    Banco <int> banquito;
    //Adding clients
    for (int i = 0; i < 15; i++){
        banquito.agregarCliente(i, rand()%100000 + 100);
    }

    //Command that we used to make try outs.
    banquito.numeroCliente.imprimir();
    banquito.dinero.imprimir();
    banquito.retirar(10, banquito.dinero[10]);
    banquito.bajaCliente(10);
    banquito.bajaCliente(11);
    banquito.deposito(0, 999999);
    banquito.numeroCliente.imprimir();
    banquito.dinero.imprimir();
    banquito.retirar(10, 500);
    banquito.retirar(12, 100);
    banquito.retirar(1, 99999999);
    banquito.numeroCliente.imprimir();
    banquito.dinero.imprimir();
    banquito.asignarTurno(2);
    banquito.asignarTurno(5);
    banquito.asignarTurno(10);
    banquito.atenderSiguiente();
    banquito.atenderSiguiente();
    banquito.principalesClientes();
    banquito.numeroCliente.imprimir();
    banquito.dinero.imprimir();
    banquito.agregarCliente(10924, 100);
    banquito.agregarCliente(10645, 105);
    banquito.agregarCliente(1348, 0);
    banquito.bajaCliente(1348);
    banquito.bajaCliente(1342);
    banquito.numeroCliente.imprimir();
    banquito.dinero.imprimir();
    banquito.agregarCliente(548, 147);
    banquito.numeroCliente.imprimir();
    banquito.dinero.imprimir();
    banquito.deposito(548, 2000000);
    banquito.numeroCliente.imprimir();
    banquito.dinero.imprimir();}

    //Problemas teoricos.
    /*int arregloProblema1 [size] = {1, 12, 17, 19, 20};
    busquedaBinaria(arregloProblema1, 0, size-1, 12, 1);
    int arregloProblema2 [size] = {19, 1, 20, 17, 12};
    InsertionSort<int> sor; 
    sor.sort(arregloProblema2, size);
    int arregloProblema3 [size] = {19, 1, 20, 17, 12};
    QuickSort<int> quickSort;
    quickSort.sort(arregloProblema3, size);
}*/