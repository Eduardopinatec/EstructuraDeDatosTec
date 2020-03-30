#include <iostream>

using namespace std;

class Fibo {
    private:
    int fibonacciAux (int index, int num, int antes){
        index--;
        int tot = 0;
        if (index == 0){
            return num;
        }
        else{
            if (antes == 0){
                return fibonacciAux(index, num, num);
            }
            else{
                tot = num+antes;
                return fibonacciAux(index, tot, num);
            }
        }
    }
    public:
        int fibonacci (int index){
        return fibonacciAux(index, 1, 0);
        }
};
class Secuencial{
    public:
        int busquedaSecuencial(int* a, int buscado, int size){
            return busquedaSecuencialAux(a, buscado, size, 0);
        }
    private:
        int busquedaSecuencialAux(int* a, int buscado, int size, int pos){
            if (a[pos]==buscado){
                return pos;
            }
            else if (pos>size){
                return -1;
            }
            else
            {
                return busquedaSecuencialAux(a, buscado, size, pos+1);
            }
        }

};
class Ordenada1{
    public:
        int busquedaOrdenada1(int *a, int buscado, int size){
            return busquedaOrdenada1Aux (a, buscado, size, 0);
        }
    private:
        int busquedaOrdenada1Aux(int* a, int buscado, int size, int pos){
            if (buscado>a[size-1]||pos>size){
                return -1;
            }
            else if (a[pos]==buscado){
                return pos;
            }
            else{
                return busquedaOrdenada1Aux(a, buscado, size, pos+1);
            }            
        }
};
class Ordenada2{
    public:
        int busquedaOrdenada2(int *a, int size, int buscado, int paso){
            return busquedaOrdenada2Aux(a, size, buscado, paso, 0);
        }
        int busquedaAux(int *a, int inicio, int fin, int buscado){
            if (a[inicio]==buscado){
                return inicio;
            }
            else if (inicio>fin){
                return -1;
            }
            else{
                return busquedaAux(a, inicio+1, fin, buscado);
            }
        }
    private:
        int busquedaOrdenada2Aux(int* a, int size, int buscado, int paso, int pos){
            int fin = pos+paso-1;
            if(size-1<fin){
                fin = size-1;
            }
            if(a[fin]>=buscado){
                return busquedaAux(a, pos, fin, buscado);
            }
            else if(pos>size){
                return -1;
            }
            else{
                return busquedaOrdenada2Aux(a, size, buscado, paso, pos+paso);
            }
        }
};
int main (){
    Fibo Fibo;
    int fib = 0;
    cout<<"Que posición fibonacci quieres?"<<endl;
    cin>>fib;
    cout<<Fibo.fibonacci(fib)<<endl;
    Secuencial Secu;
    int num = -1;
    int size=5;
	int *a=new int[size]();
    a[0]=1;
    a[1]=3;
    a[2]=5;
    a[3]=7;
    a[4]=9;
    cout<<"Que numero deseas buscar?"<<endl;
    cin>>num;
    cout<<Secu.busquedaSecuencial(a,num,size)<<endl;
    Ordenada1 Ordenadito1;
    cout<<Ordenadito1.busquedaOrdenada1(a, num, size)<<endl;
    Ordenada2 Ordenadito2;
    cout<<Ordenadito2.busquedaOrdenada2(a, size, num, 2)<<endl;
}