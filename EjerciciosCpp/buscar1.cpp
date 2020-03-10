#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string frase = "";
    string palabra ="";
    cout<<"Dame una frase: ";
    getline(cin, frase);
    cout<<"Que palabra deseas buscar: ";
    getline(cin, palabra);

    int count = 0;
    int pos = 0;
    pos = frase.find(palabra);
    while (pos!=1)
    {
        count++;
        pos = frase.find(palabra, pos+1);
        cout<<"Estoy en el while";
    }
    cout<<"Se encontro la palabra "<<count<< " veces"<< endl;
}