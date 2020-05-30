#include <iostream>
#include <vector>
using namespace std;

template <class K, class V>
class KeyPair{
	public:
	K key;
	V value;
	
	KeyPair(){
		key=NULL;
		value=NULL;
	}
	
	KeyPair(K key, V val){
		this->key=key;
		this->value=val;
	}
};

template <class K, class V>
class Dictionary{
	public:
	vector<KeyPair<K,V>> *dict;
	int positions;
	
	Dictionary(){
		positions=10;
		dict=new vector<KeyPair<K,V>>[positions];
	}
	
	Dictionary(int pos){
		positions=pos;
		dict=new vector<KeyPair<K,V>>[positions];
	}
	
	void insert(K key, V value){
		KeyPair<K,V> kp(key, value);
		int hash=key%positions;
		for(int i=0; i<dict[hash].size(); i++){
			if(dict[hash][i].key==key){
				cout<<"llave ya existente"<<endl;
				return;
			}
		}
		dict[hash].push_back(kp);
		//dict//arreglo de vectores keypair
		//dict[hash]//vector de keypair

	}
	
	V checkAtKey(K key){
		int hash=key%positions;
		for(int i=0; i<dict[hash].size(); i++){
			if(dict[hash][i].key==key){
				return dict[hash][i].value;
			}
		}
		return NULL;
	}
	
	void printDictionary(){
		for (int i = 0; i < positions; i++){
			cout<<"["<<i<<"]:";
			for (int j = 0; j<dict[i].size(); j++){
				cout<<"("<<dict[i][j].key<<", "<<dict[i][j].value<<")";
			}
			cout<<endl;
		}
	}
};

template<class T>
class Hash{
    public:
    vector<T> *table;
    int tamano;
    Hash(){
        tamano = 10;
        table = new vector<T>[tamano];
    }
    Hash(int tam){
        tamano = tam;
        table = new vector<T>[tamano];
    }
    void insert (T llave){
        int pos = llave%tamano;
        for (int i = 0; i<table[pos].size(); i++){
            if(table[pos][i] == llave){
                cout<<"La llave ya existe"<<endl;
                return;
            }
        }
        table[pos].push_back(llave);
    }
    	
	void printHash(){
		for (int i = 0; i < tamano; i++){
			cout<<"["<<i<<"]:";
			for (int j = 0; j<table[i].size(); j++){
				cout<<table[i][j]<<",";
			}
			cout<<endl;
		}
	}
    T buscar(T num){
        int pos = num%tamano;
        for (int i = 0; i<table[pos].size(); i++){
            if (table[pos][i] == num){
                return cout<<"Ya existe el numero: "<<num<<" esta en la posicion: "<<pos<<endl;
            }
        }
        return cout<<"No existe el numero: "<<num<<endl;
    }
};

int main(){
	/*Dictionary<int, string> a;
	a.insert(15, "Hola");
	a.insert(23, "perro");
	a.insert(9, "gato");
	a.insert(1501, "adios");
	a.insert(301, "nuevo");
	//cout<<a.checkAtKey(15)<<endl;
	a.printDictionary();
    */
    Hash <int> h;
    h.insert(5);
    h.insert(5);
    h.insert(15);
    h.printHash();
}