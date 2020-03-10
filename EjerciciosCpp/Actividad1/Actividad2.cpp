#include <iostream>

using namespace std;

int main(){
    int n = 0, count = 0, num = 0, sum = 0;
    cout<<"Cuantos numeros deseas sumar: ";
    cin>>n;
    while (count < n)
    {
        cout<<("Dame un numero: ");
        cin>>num;
        sum += num;
        count++;
    }
    sum = sum/n;
    cout<<"El promedio es: "<<sum<<endl;
}