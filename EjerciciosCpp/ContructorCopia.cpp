#include <iostream>

using namespace std;

class Valores{
    public:
        int *a;
        int size;

        Valores (int tam){
            size=tam;
            a = new int (size);
        }
};

int main (){
    Valores v (5);
    for (int i = 0; i < 5; i++)
    {
        v.a[i]=10*i;
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<v.a[i]<<endl;
    }
    Valores copia (5);
        for (int i = 0; i < 5; i++)
    {
        copia.a[i]=v.a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<copia.a[i]<<endl;
    }
}