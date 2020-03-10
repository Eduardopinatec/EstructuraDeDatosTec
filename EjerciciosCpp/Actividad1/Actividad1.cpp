#include <iostream>

using namespace std;

int main ()
{
    int a = 0;
    cout<<"Dame un año: ";
    cin>>a;
    if (a%4 == 0)
    {
        if (a%100 == 0)
        {
            if (a%400 == 0)
            {
                cout<<("Es año bisiesto") << endl;
            }
            else
            {
                cout<<("No año bisiesto") << endl;
            }
        }
        else 
        {
            cout<<("Es año bisiesto") << endl;
        }
    }
    else 
    {
        cout<<("No es año bisiesto") << endl;
    }

}