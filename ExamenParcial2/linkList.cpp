#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo<T> *next;
	
	Nodo(T value){
		this->value=value;
		next=NULL;
	}
	
	Nodo(){
		this->value=NULL;
		next=NULL;
	}
};

template <class T>
class LinkedList{
	public:
		Nodo<T> *root;
		LinkedList(){
			root=NULL;
		}
		
		void append(T value){
			Nodo<T> *agregar=new Nodo<T>(value);
			append(agregar);
		}
		
		void append(Nodo<T> *agregar){
			if(root==NULL){
				root=agregar;
			}else{
				Nodo<T> *temp=root;
				while(temp->next!=NULL){
					temp=temp->next;//avanza al siguiente nodo
				}//al final, temp esta en el ultimo nodo
				temp->next=agregar;
			}
		}
		
		void imprimir(){
			Nodo<T> *temp=root;
			while(temp!=NULL){
				cout<<temp->value<<",";
				temp=temp->next;
			}
			cout<<endl;
		}
		T imprimirTurno (){
			Nodo<T> *temp = root;
			return temp->value;
		}
		
		void insert(Nodo<T> *toAdd, int pos){
			if(root==NULL){
				root=toAdd;
				return;
			}
			if(pos==0){
				toAdd->next=root;
				root=toAdd;
				return;
			}
			Nodo<T> *temp=root;
			int count=0;
			while(count<pos-1&&temp->next!=NULL){
				temp=temp->next;
				count++;
			}
			toAdd->next=temp->next;
			temp->next=toAdd;
		}
		
		void insert(T value, int pos){
			Nodo<T> *toAdd= new Nodo<T>(value);
			insert(toAdd, pos);
		}
		
		Nodo<T> *removePos(int pos){
			if(root==NULL){
				return NULL;
			}
			Nodo<T> *temp=root;
			if(pos==0){
				root=root->next;
				//T copia=temp->value;
				//delete temp;
				return temp;
			}
			int count=0;
			while(count<pos-1&&temp->next!=NULL){
				temp=temp->next;
				count++;
			}
			if(count==pos-1){
				Nodo<T> *toDelete=temp->next;
				temp->next=toDelete->next;//temp->next=temp->next->next;
				//T copia=toDelete->value;
				//delete toDelete;
				return toDelete;
			}
			return NULL;
		}
		
		void remove(T value){
			if(root==NULL){
				return;
			}
			Nodo<T> *temp=root;
			if(value==root->value){
				root=root->next;
				delete temp;
				return;
			}
			while(temp->next!=NULL){
				if(temp->next->value==value){
					Nodo<T> *toDelete=temp->next;
					temp->next=toDelete->next;
					delete toDelete;
					return;
				}else{
					temp=temp->next;
				}
			}
			return;
		}		
};