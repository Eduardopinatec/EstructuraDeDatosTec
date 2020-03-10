#include <iostream>

using namespace std;

int busquedaSecuencial(int *a, int num, int size){
    for (int i = 0; i < size; i++)
    {
        if(a[i]==num){
            return i;
        }
    }
    return -1;
}

int busquedaOrdenada2(int *a, int num, int size){
    if (a[size]<num)
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i]==num)
            {
                return i;
            }
            else if (a[i]>num)
            {
                return -1;
            }
        }
    }
    else if(a[size]==num)
    {
        return size;
    }
    else
    {
        return -1;
    }
}
int busquedaAux(int *a, int inicio, int fin, int busqueda){
    for (int i = inicio; i<fin; i++)
    {
        if(a[i]==busqueda)
        {
            return i;
        }
    }
    return -1;
}
int  busquedaOrdenada3 (int *a, int size, int buscado, int paso){
    for (int i = paso; i<=size; i+= paso)
    {
        if (a[i-1]>=buscado)
        {  
            return busquedaAux(a, i-paso, i, buscado);
        }
    }
    return -1;
}

int main () {
    int size = 6;
    int a[size] = {1,2,3,4,5,6};
    cout<<busquedaOrdenada3(a, size, 6, 2)<<endl;
    /*int size = 10;
    int *a = new int [size]();
    for (int i = 0; i < size; i++){
        a[i]=i;
    }*/
}