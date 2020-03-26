#include <iostream>

using namespace std;

int main (){
    int a[]={50, 40, 30, 20, 10};
    int *b = a;
    int c = *b;
    cout<<(c)<<endl;
    c = *b+2;
    cout<<(c)<<endl;
    c = (*b+3);
    cout<<(c)<<endl;
    c = *++b;
    cout<<(c)<<endl;
    c = *(b+1);
    cout<<(c)<<endl;
    b++;
    c = *b+1;
    cout<<(c)<<endl;
    c = (*b++)+1;
    cout<<(c)<<endl;
    c = *(b)+2;
    cout<<(c)<<endl;
    c = *b-1;
    cout<<(c)<<endl;
}


