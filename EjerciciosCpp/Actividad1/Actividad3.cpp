#include <iostream>
#include <string>

using namespace std;

int main () {
    string frase = "", palabra = "";
    int lenF = 0, lenP = 0, veces  = 0, ubi = 0, cont = 0;
    cout<<"Dame una frase: ";
    getline (cin, frase);
    cout<<"Palabra que deseas buscar: ";
    cin>>palabra;
    lenF = frase.length();
    lenP = palabra.length();
    for (int i = 0; i<lenF; i++)
    {
        cont=0;
        if(palabra.at(0)==frase.at(i))
        {
            for(int k = 1, j = i+1; k<lenP; j++, k++)
            {
                if (palabra.at(k)==frase.at(j))
                {
                    cont++;
                }
                else
                {
                    break;
                }
            }
        }
        if(cont == lenP-1)
        {
            veces++;
        }
    }
    cout<<"La palabra "<<palabra<<" se repite "<<veces<<" veces"<<endl;
}