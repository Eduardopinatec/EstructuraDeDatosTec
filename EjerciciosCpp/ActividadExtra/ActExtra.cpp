#include <iostream>

using namespace std;

int fibonacci (int index, int num, int antes){
    index--;
    int tot = 0;
    if (index == 0){
        return num;
    }
    else{
        if (antes == 0){
            return fibonacci(index, num, num);
        }
        else{
            tot = num+antes;
            return fibonacci(index, tot, num);
        }
    }
}

int main (){
    int index = 0;
    cout<<"Give me an index"<<endl;
    cin>>index;
    cout<<fibonacci(7,1,0)<<endl;
}