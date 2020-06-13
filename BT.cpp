#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

template <class T>
class Nodo{
	public:
	T id;
	Nodo<T> *izquierdo;
	Nodo<T> *derecho;
	Nodo(){
		id=NULL;
		izquierdo=NULL;
		derecho=NULL;
	}
	
	Nodo(T id){
		this->id=id;
		izquierdo=NULL;
		derecho=NULL;
	}
};

template <class T>
class BST{
	public:
	Nodo<T> *root;
	
	BST(){
		root=NULL;
	}
	
	void insertar(T id){
		Nodo<T> *nuevo=new Nodo<T>(id);
		if(root==NULL){
			root=nuevo;
		}else{
			insertar(nuevo, root);
		}
	}
	
	void insertar(Nodo<T> *nuevo, Nodo<T> *temp){
		if(nuevo->id<temp->id){
			if(temp->izquierdo==NULL){
				temp->izquierdo=nuevo;
			}else{
				insertar(nuevo, temp->izquierdo);
			}
		}else if(nuevo->id>temp->id){
			if(temp->derecho==NULL){
				temp->derecho=nuevo;
			}else{
				insertar(nuevo, temp->derecho);
			}
		}
	}
	
	bool buscar(T id){
		return buscar(root, id);
	}
	
	bool buscar(Nodo<T> *temp, T id){
		if(temp==NULL){
			return false;
		}else if(temp->id==id){
			return true;
		}else if(id<temp->id){
			return buscar(temp->izquierdo, id);
		}else{
			return buscar(temp->derecho, id);
		}
	}
	
	
	
	//el mas grande siguiente es el nodo hasta la izquierda empezando desde el derecho
	void recorrido(){
		inorden(root);
		cout<<endl;
	}
	
	void inorden(Nodo<T> *temp){
		if(temp==NULL){
			return;
		}
		inorden(temp->izquierdo);
		cout<<temp->id<<", ";
		inorden(temp->derecho);
	}
    void recorrido2(){
        posorden(root);
        cout<<endl;
    }
	void posorden (Nodo<T> *temp){
        if(temp==NULL){
            return;
        }
        posorden(temp->izquierdo);
        posorden(temp->derecho);
        cout<<temp->id<<", ";
    }
    void preorden (Nodo<T> *temp){
        if (temp == NULL){
            return;
        }
        cout<<temp->id<<", ";
        preorden(temp->izquierdo);
        preorden(temp->derecho);
    }
    void recorrido3(){
        preorden(root);
        cout<<endl;
    }
	/*Nodo<T> a(5);
	Nodo<T> *b=new Nodo<T>(5);
	a.derecho;
	(*b).derecho
	b->derecho*/
};

int main(){
	BST<int> a;
	a.insertar(40);
	a.insertar(70);
	a.insertar(21);
	a.insertar(57);
    a.insertar(71);
    a.insertar(13);
    a.insertar(25);
    a.insertar(6);
    a.insertar(14);
    a.insertar(26);
    a.recorrido();
	a.recorrido2();
    a.recorrido3();
	return 0;
}