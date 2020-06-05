#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>


using namespace std;


struct Data{
    string user1;
    int inter;
    string user2;

    Data(string u1, int i, string u2){
        user1=u1;
        inter=i;
        user2=u2;
    }
};

vector<Data> interacciones;

void leerData(string path){
    ifstream fIn;
    fIn.open(path);
    string temp, line, parts;
    vector<string> valores;
    while(fIn.good()){
        getline(fIn, line); 
        istringstream s(line); 
        while (getline(s, parts, ',')) { 
                valores.push_back(parts);
         }
         if(valores[2].find('\r')!=valores[2].npos){
            interacciones.push_back(Data(valores[0], stoi(valores[1]), valores[2].substr(0, valores[2].size()-1)));
        }
        else{
            interacciones.push_back(Data(valores[0], stoi(valores[1]), valores[2]));
        }
        valores.clear(); 
    }
    fIn.close();
}
class Set1{
    public:
    //Creating the set
    set<string> list;
    //Creating the unorderedMap with a vector inside
    unordered_map<string, vector<string>> map;
    Set1(){
        for(auto i: interacciones){
            list.insert(i.user1);
            list.insert(i.user2);
        }
        for (auto i: interacciones){
            //Seeing what type of interaction
            if (i.inter==0){
                //It is a share type, so we add user1 into the followers list of user2
                map[i.user2];
                map[i.user2].push_back(i.user1);
            }
            else{
                //It is a comment type, so they follow each other
                map[i.user1];
                map[i.user1].push_back(i.user2);
                map[i.user2];
                map[i.user2].push_back(i.user1);
            }
        }
        //Print the map with there followers
        for (auto& x: map){
            cout<<x.first<<"\t\t";
            for (int i = 0; i < map[x.first].size(); i++){
                cout<<map[x.first][i]<<"\t";
            }
            cout<<endl;
        }
    }
    void print(){
        int count = 0;
        for (const auto& i: list){
            count++;
            cout<<i<<endl;
        }
        cout<<count<<endl;
    }
    void usuarioExistente(string userName){
        if (list.find(userName)==list.end()){
            cout<<"No existe"<<endl;
        }
        else{
            cout<<"Ya existe"<<endl;
        }
    }
    void esSeguidor (string a, string b){
        //Searching if the user exists
        auto res = map.find(b);
        if (res!=map.end()){
            //Looping into the Vector to see if he have the follower
            for(int i = 0; i < map[b].size(); i++){
                //Searching for the user into the followers list
                if (map[b][i].compare(a)==0){
                    cout<<"Si lo sigue"<<endl;
                    return;
                }
            }
            //If it didn't found the follower
            cout<<"No lo sigue"<<endl;
        }
        //If it dosen't found the user
        else{
            cout<<"No existe esa cuenta"<<endl;
        }
    }
};//Agrega aqui los datos y metodos para resolver los problemas del set 1

class Set2{

};//Agrega aqui los datos y metodos para resolver los problemas del set 2
class Set3 {
    Set1 dataSet1;
    //Making the tree of followers, share and coments
    std::map <string, int> followers;
    std::map <string, int> compartir;
    std::map <string, int> comentar;
    //Constructor
    Set3(){
        //Constructor for the tree of followers
        //Looping into my list that has all the users id
        for (const auto& i: dataSet1.list){
            int count = 0;
            //Looping into all the map that has the user and the users that follow him.
            for (auto& x: dataSet1.map){
                //Lopping into the vector of the map.+
                for (int j = 0; j < dataSet1.map[x.first].size(); j++){
                    //Searching into all the data the user name so it can see how many people he is following.
                    if (dataSet1.map[x.first][j].compare(i)==0){
                        count++;
                    }
                }
            }
            cout<<"count: "<<count<<endl;
            //Addind the user and the id (number of accounts that the user follows).
            followers.insert(make_pair(i,count));
        }
        //Constructor for the tree of shares
        //Looping into list that has all the users ids.
        for (const auto& i: dataSet1.list){
            int count = 0;
            //Lopping into the information that the .txt gave us to see what tyoe if interaction the user have. 
            for (auto j: interacciones){
                //Searching for the user id and searching for the share interaction.
                if(j.user1.compare(i)==0 && j.inter==0){
                    count++;
                }
            }
            //Adding the user and the id (number of shares that the user made).
            compartir.insert(make_pair(i, count));
        }
        //Constructor for the tree of coments
        //Lopping into the 
        for (const auto& i : dataSet1.list){
            int count = 0;
            for (auto j : interacciones){
                if (j.user1.compare(i)==0 && j.inter==1){
                    count++;
                }
            }
            comentar.insert(make_pair(i, count));
        }
    }
    void printID(){
        for (auto &i : followers){
            cout<<i.first<<" Follows:"<<i.second<<endl;
        }
    }
    void mayorSeguidor(){
        int mayor = 0;
        for (auto &i : followers){
            if (mayor<i.second){
                mayor = i.second;
            }
        }
        for (auto &i : followers){
            if (i.second == mayor){
                cout<<i.first<<" sigue a:"<<i.second<<endl;
            }
        }
    }
    //////////////////////////////////////////////////////////////////
    
    void addComp(){

    }
    void printT (){
        for (auto &i : compartir){
            cout<<i.first<<" compartio: "<<i.second<<endl;
        }
    }
    void amplificador (){
        int mayor = 0;
        for (auto &i : compartir){
            if (mayor<i.second){
                mayor = i.second;
            }
        }
        for (auto &i : compartir){
            if (i.second == mayor){
                cout<<i.first<<" Comparte: "<<i.second<<endl;
            }
        }
    }
    /////////////////////////////////////////////////////////
    void printC (){
        for (auto &i : comentar){
            cout<<i.first<<"comento: "<<i.second<<endl;
        }
    }
    void callado(){
        int menor = 1000;
        for (auto &i : comentar){
            if (menor>i.second){
                menor = i.second;
            }
        }
        for (auto &i: comentar){
            if (i.second == menor){
                cout<<i.first<<"Es el mas callado con la cantidad de: "<<i.second<<endl;
            }
        }
    }
};//Agrega aqui los datos y metodos para resolver los problemas del set 3

class Set4{

};//Agrega aqui los datos y metodos para resolver los problemas del set 4

int main(){
    //Cambia la ruta a donde se encuentra el archivo
    //Ejemplo windows en WSL: /mnt/c/Users/Jorge/Desktop/file.txt
    //Ejemplo Mac: /Users/Jorge/Desktop/file.txt
    //En la misma carpeta: file.txt
    string path="file.txt";
    leerData(path);
    for(auto i: interacciones){
        cout<<i.user1<<":"<<i.inter<<":"<<i.user2<<endl;
    }
    Set1 set1;
    Set3 <int> set3;
    // set1.print();
    // set1.usuarioExistente("Adultin12");
    set1.insertingData();
    // set1.esSeguidor("Adultin12", "lorenzo");
    set1.addId();
    set1.printID();
    set1.mayorSeguidor();
    set1.addComp();
    set1.printT();
    set1.amplificador();
    set1.addComent();
    set1.printC();
    set1.callado();
    return 0;
}