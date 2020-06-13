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
        for (auto i : interacciones){
            int existe = 0;
            if (i.inter==0){
                //It is a share type, so we add user1 into the followers list of user2
                map[i.user2];
                for (int j = 0; j < map[i.user2].size(); j++){
                    if (map[i.user2][j].compare(i.user1)==0){
                        existe = 1;
                        break;
                    }
                }
                if (existe == 0){
                    map[i.user2].push_back(i.user1);
                }
            }
            else{
                map[i.user1];
                map[i.user2];
                for (int j = 0; j < map[i.user1].size(); j++){
                    if (map[i.user1][j].compare(i.user2)==0){
                        existe = 1;
                        break;
                    }
                }
                if (existe == 0){
                    map[i.user1].push_back(i.user2);
                }
                existe = 0;
                for (int j = 0; j < map[i.user2].size(); j++){
                    if (map[i.user2][j].compare(i.user1)==0){
                        existe = 1;
                        break;
                    }
                }
                if (existe == 0){
                    map[i.user2].push_back(i.user1);
                }
            }
        }
        // for (auto i: interacciones){
        //     //Seeing what type of interaction
        //     if (i.inter==0){
        //         //It is a share type, so we add user1 into the followers list of user2
        //         map[i.user2];
        //         map[i.user2].push_back(i.user1);
        //     }
        //     else{
        //         //It is a comment type, so they follow each other
        //         map[i.user1];
        //         map[i.user1].push_back(i.user2);
        //         map[i.user2];
        //         map[i.user2].push_back(i.user1);
        //     }
        // }
        //Print the map with there followers
        // for (auto& x: map){
        //     cout<<x.first<<"\t\t";
        //     for (int i = 0; i < map[x.first].size(); i++){
        //         cout<<map[x.first][i]<<"\t";
        //     }
        //     cout<<endl;
        // }
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
    public:
    Set1 dataSet1;
    //Making the tree of followers, share and coments
    std::map <int, vector<string>> followers;
    std::map <int, vector<string>> compartir;
    std::map <int, vector<string>> comentar;
    //Constructor
    Set3(){
        //Constructor for the tree of followers
        //Looping into my list that has all the users id
        for (const auto& i: dataSet1.list){
            int count = 0;
            //Looping into all the map that has the user and the users that follow him.
            for (auto& x: dataSet1.map){
                //Lopping into the vector of the map.
                for (int j = 0; j < dataSet1.map[x.first].size(); j++){
                    //Searching into all the data the user name so it can see how many people he is following.
                    if (dataSet1.map[x.first][j].compare(i)==0){
                        count++;
                    }
                }
            }
            //Addind the user and the id (number of accounts that the user follows).
            //followers.insert(make_pair(i,count));
            followers[count];
            followers[count].push_back(i);
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
            compartir[count];
            compartir[count].push_back(i);
            //compartir.insert(make_pair(i, count));
        }
        //Constructor for the tree of coments
        //Lopping into the list of users
        for (const auto& i : dataSet1.list){
            int count = 0;
            //Lopping into the information that the .txt gave us to see what tyoe if interaction the user have. 
            for (auto j : interacciones){
                //Searching for the user id and for the coment interaction
                if (j.user1.compare(i)==0 && j.inter==1){
                    count++;
                }
            }
            //Adding the user and id (number of comments)
            comentar[count];
            comentar[count].push_back(i);
            //comentar.insert(make_pair(i, count));
        }
    }
    //Part 3.1
    //Method for printing all the information that the followers tree has.
    void printID(){
        for (auto& x: followers){
            cout<<x.first<<"\t";
            for (int i = 0; i < followers[x.first].size(); i++){
                cout<<followers[x.first][i]<<"\t";
            }
            cout<<endl;
        }
    }
    // void printID(){
    //     for (auto &i : followers){
    //         cout<<i.first<<" Follows:"<<i.second<<endl;
    //     }
    // }
    //Searching for the user that follows the must.
    void mayorSeguidor(){
        int bigger = 0;
        for (auto &i: followers){
            if (bigger<i.first){
                bigger = i.first;
            }
        }
        for (auto &i: followers){
            if (i.first == bigger){
                cout<<"The users that follows the must people are ";
                for (int j = 0; j < followers[i.first].size(); j++){
                    cout<<followers[i.first][j]<<",";
                }
            }
        }
        cout<<" and they follow the amount of "<<bigger<<endl;
    }
    // void mayorSeguidor(){
    //     int mayor = 0;
    //     for (auto &i : followers){
    //         if (mayor<i.second){
    //             mayor = i.second;
    //         }
    //     }
    //     for (auto &i : followers){
    //         if (i.second == mayor){
    //             cout<<i.first<<" sigue a:"<<i.second<<endl;
    //         }
    //     }
    // }
    //Part 3.2
    //Method for printing all the information that the share tree has.
    void printT (){
        for (auto& x: compartir){
            cout<<x.first<<"\t";
            for (int i = 0; i < compartir[x.first].size(); i++){
                cout<<compartir[x.first][i]<<"\t";
            }
            cout<<endl;
        }
    }
    // void printT (){
    //     for (auto &i : compartir){
    //         cout<<i.first<<" compartio: "<<i.second<<endl;
    //     }
    // }
    //Searching for the user that shares the must.
    void amplificador(){
        int bigger = 0;
        for (auto &i: compartir){
            if (bigger<i.first){
                bigger = i.first;
            }
        }
        for (auto &i: compartir){
            if (i.first == bigger){
                cout<<"The users that shares the must are ";
                for (int j = 0; j < compartir[i.first].size(); j++){
                    cout<<compartir[i.first][j]<<",";
                }
            }
        }
        cout<<" and they share the amount of "<<bigger<<endl;
    }
    // void amplificador (){
    //     int mayor = 0;
    //     for (auto &i : compartir){
    //         if (mayor<i.second){
    //             mayor = i.second;
    //         }
    //     }
    //     for (auto &i : compartir){
    //         if (i.second == mayor){
    //             cout<<i.first<<" Comparte: "<<i.second<<endl;
    //         }
    //     }
    // }
    //Part 3.3
    //Method for printing all the information that the coment tree has.
    void printC (){
        for (auto& x: comentar){
            cout<<x.first<<"\t";
            for (int i = 0; i < comentar[x.first].size(); i++){
                cout<<comentar[x.first][i]<<"\t";
            }
            cout<<endl;
        }
    }
    // void printC (){
    //     for (auto &i : comentar){
    //         cout<<i.first<<"comento: "<<i.second<<endl;
    //     }
    // }
    //Searching for the person that coments the least 
    void callado(){
        int smaller = 1000;
        for (auto &i: comentar){
            if(smaller>i.first){
                smaller = i.first;
            }
        }
        for (auto &i: comentar){
            if (smaller == i.first){
                cout<<"The must quiet users are: ";
                for (int j = 0; j < comentar[i.first].size(); j++){
                    cout<<comentar[i.first][j]<<",";
                }
                cout<<" he/she is the must quiet as he/she only coment "<<smaller<<" times"<<endl;
            }
        }
    }
    // void callado(){
    //     int menor = 1000;
    //     for (auto &i : comentar){
    //         if (menor>i.second){
    //             menor = i.second;
    //         }
    //     }
    //     for (auto &i: comentar){
    //         if (i.second == menor){
    //             cout<<i.first<<"Es el mas callado con la cantidad de: "<<i.second<<endl;
    //         }
    //     }
    // }
};//Agrega aqui los datos y metodos para resolver los problemas del set 3

class Set4{
    public:
    Set1 data;
    Set4(){

    }
    void sonAmigos(string user1, string user2){
        auto res = data.map.find(user1);
        auto res2 = data.map.find(user2);
        int res3 = 0;
        bool friends = false;
        if (res!=data.map.end()){
            for (int i = 0; i < data.map[user1].size(); i++){
                if (data.map[user1][i].compare(user2)==0){
                    res3++;
                }
            }
        }
        if (res2!=data.map.end()){
            for (int i = 0; i < data.map[user2].size(); i++){
                if (data.map[user2][i].compare(user1)==0){
                    res3++;
                }
            }
        }
        if (res3>1){
            friends = true;
            cout<<"SON AMIGOS"<<endl;
        }
        else{
            cout<<"NO SON AMIGOS"<<endl;
        }
    }
    void listarAmigos (string userName){
        set<string>amigos;
        for (int i = 0; i < data.map[userName].size(); i++){
            amigos.insert(data.map[userName][i]);
        }
        // for (const auto &i : amigos){
        //     cout<<i<<", ";
        // }
        // cout<<endl;
        cout<<"List of friends of the user "<<userName<<": ";
        for (const auto& x : amigos){
            for (int i = 0; i < data.map[x].size(); i++){
                if (data.map[x][i].compare(userName)==0){
                    cout<<x<<", ";
                    break;
                }
            }
        }
        cout<<endl;
    }
    void conexion(string a, string b) {
        int conection = 0;
        for (int i = 0; i < data.map[a].size(); i++){
            if (data.map[a][i].compare(b)==0){
                cout<<"They have a conection"<<endl;
                conection++;
                break;
            }
        }
        if (conection==0){
            for (int i = 0; i < data.map[b].size(); i++){
                if (data.map[b][i].compare(a)== 0){
                    cout<<"They have a conection"<<endl;
                    break;
                }
            }
        }
        if (conection == 0){
            cout<<"They don't have any conection"<<endl;
        }
    }
    void FFR (string userName){
        if (data.list.find(userName)!=data.list.end()){
            set<string>followers;
            set<string>follow;
            cout<<data.map[userName].size()<<endl;
            for (int i = 0; i < data.map[userName].size(); i++){
                followers.insert(data.map[userName][i]);
            }
            for (const auto &i : followers){
                for (int j = 0; j < data.map[i].size(); j++){
                    if (data.map[i][j].compare(userName)==0){
                        follow.insert(i);
                        break;
                    }
                }
            }
            for (auto &i : followers){
                cout<<i<<", ";
            }
            cout<<endl;
            double size1 = (double)follow.size();//checar si, si va el -1
            double size2 = (double)followers.size();
            // cout<<followers.size()<<endl;
            // cout<<follow.size()<<endl;

            double radio = size2/size1;
            cout<<"Radio: "<<radio<<endl;
        }
        else{
            cout<<"El usuario no existe"<<endl;
        }
        
    }
    void SCR(){

    }
};//Agrega aqui los datos y metodos para resolver los problemas del set 4

int main(){
    //Cambia la ruta a donde se encuentra el archivo
    //Ejemplo windows en WSL: /mnt/c/Users/Jorge/Desktop/file.txt
    //Ejemplo Mac: /Users/Jorge/Desktop/file.txt
    //En la misma carpeta: file.txt
    string path="file.txt";
    leerData(path);
    // for(auto i: interacciones){
    //     cout<<i.user1<<":"<<i.inter<<":"<<i.user2<<endl;
    // }
    Set1 set1;
    Set3 set3;
    Set4 set4;
    // set1.print();
    // set1.usuarioExistente("Adultin12");
    set1.usuarioExistente("Usuario");
    set1.esSeguidor("lalo", "lorenzo");
    set3.mayorSeguidor();
    set3.amplificador();
    set3.callado();
    set4.sonAmigos("Jobie10", "Lanna14");
    set4.sonAmigos("Viv7", "Corella3");
    set4.listarAmigos("Viv7");
    set4.conexion("Adultin12", "lalo");
    set4.conexion("Viv7", "Corella3");
    set4.FFR("Marylynne9");
    set4.FFR("Adultin12");
    // set3.printID();
    return 0;
}