#include <iostream>

using namespace std;

int main ()
{
    int a = 56;
    int *b =&a;
    cout<<"el valor de a es: "<<a<<endl;
    cout<<"la direccion de memoria de a es: "<<&a<<endl;
    cout<<"el valor de b es: "<<*b<<endl;
    cout<<"El apuntador b tiene: "<<b<<endl;
    int c[3]={1,2,3};
    int *d=c;
    cout<<b<<endl;

    cout<<c[1]<<endl;
    cout<<*c+1<<endl;
    return 0;
}