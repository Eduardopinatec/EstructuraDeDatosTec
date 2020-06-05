#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int main (){
    unordered_map<string, vector<string>> map;
    map["lalo"];
    map["lalo"].push_back("lorenzo");
    for (auto& x: map){
        cout<<x.first<<endl;
        for (int i = 0; i < map[x.first].size(); i++){
            cout<<map[x.first][i]<<endl;
        }
    }

}
