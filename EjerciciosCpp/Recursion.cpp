#include <iostream>

using namespace std;

int factorial(int num){
    int res = 1;
    for (int i = num; i>0; i--)
    {
        res *= i;
    }
    return res;
}

double factorialR (int n){
    if (n==1){
        return 1;
    }
    else 
    {
        return n*factorialR(n-1);
    }
}

int main ()
{
    double res = factorialR (300);
    cout<<res<<endl;
}