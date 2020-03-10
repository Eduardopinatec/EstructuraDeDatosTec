#include <iostream>

using namespace std;

int main (){
    int a[]={10, 20, 30, 40, 50};
    int *b = a;
    int c = *b;
    cout<<(c)<<endl;
    c = (*b+2);
    cout<<(c)<<endl;
    c = (*b+1);
    cout<<(c)<<endl;
    c = (*b)+3;
    cout<<(c)<<endl;
    b++;
    c = *(b-1);
    cout<<(c)<<endl;
    c = (*b);
    cout<<(c)<<endl;
    c = (*b--);
    cout<<(c)<<endl;
    c = (*b);
    cout<<(c)<<endl;
    c = (*++b);
    cout<<(c)<<endl;
    c = (*b);
    cout<<(c)<<endl;
    c = (*b+1)+1;
    cout<<(c)<<endl;
    c = *(b+1)-1;
    cout<<(c)<<endl;
}


