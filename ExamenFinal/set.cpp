#include <iostream>
#include <set>

using namespace std;

int main(){
    set<string> list;
    list.insert("lalo");
    list.insert("lorenzo");
    list.insert("lalo");
    list.insert("lorenzso");
    for (const auto& i: list){
        cout<<i<<endl;
    }
}