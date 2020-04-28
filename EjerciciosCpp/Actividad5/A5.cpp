#include <iostream>

using namespace std;

template <class T>
class Sort{
	public:
	virtual void sort(T *a, int size)=0;

	void intercambiar(T *a, int p1, int p2){
        T x= a[p1];
        a[p1] = a[p2];
        a[p2] = x;
    }

	void imprimirArreglo(T *a, int size){
		cout<<a[0];
		for(int i=1; i<size; i++){
			cout<<", "<<a[i];
		}
		cout<<endl;
	}
};

template <class T>
class LuckySort: public Sort<T>{
	public:
	void sort(T *a, int size){
		this->intercambiar(a, 0, size-1);
	}
};

template <class T>
class SelectionSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		for(int i=0; i<size-1; i++){
			int p=i;
			for(int j=i+1; j<size; j++){
				if(a[j]<a[p]){
					p=j;
				}
			}
			this->intercambiar(a, i, p);
		}
	}
};

template <class T>
class BubbleSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		int it=0;
		for(int i=0; i<size-1; i++){
			bool ordenado=true;
			for(int j=0; j<size-1-i; j++){
				it++;
				if(a[j]>a[j+1]){
					this->intercambiar(a, j+1, j);
					ordenado=false;
				}
			}
			if(ordenado==true){
				break;
			}
		}
	}
};


template <class T>
class InsertionSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		for(int i=1; i<size; i++){
			for(int j=i; j>0; j--){
				if(a[j]<a[j-1]){
					this->intercambiar(a, j, j-1);
				}else{
					break;
				}
			}
		}
	}
};

template <class T>
class MergeSort: public Sort<T>{
	public:
	int mer = 0, sor = 0;
	void sort(T *a, int size){
		sortAux(a, 0, size-1);
	}
	
	private:
	void sortAux(T *a, int inicio, int fin){
		sor++;
		cout<<"Count of Sort: "<<sor<<endl;
		cout<<"*a: "<<a<<", inicio: "<<inicio<<", fin: "<<fin<<endl;
		if(inicio>=fin){
			return;
		}
		int medio=(fin+inicio)/2;
		sortAux(a, inicio, medio);
		sortAux(a, medio+1, fin);
		merge(a, inicio, medio, fin);
	}
	
	
	
	void merge(T *a, int inicio, int medio, int fin){
		//Tam de la copia
		mer++;
		cout<<"Count of merge: "<<mer<<endl;
		cout<<"*a: "<<*a<<", inicio: "<<inicio<<", medio: "<<medio<<", fin: "<<fin<<endl;
		int tamIzq=medio-inicio+1;
		int tamDer=fin-medio;

		//Crear espacio para copia
		T *copiaIzq=new T[tamIzq]();
		T *copiaDer=new T[tamDer]();
		//Copiando los elementos
		for(int i=0; i<tamIzq; i++){
			copiaIzq[i]=a[inicio+i];
		}
		for(int i=0; i<tamDer; i++){
			copiaDer[i]=a[medio+1+i];
		}
		//Indices
		int I=0;
		int D=0;
		int x=inicio;
		//Comparaciones
		while(I<tamIzq&&D<tamDer){
			if(copiaIzq[I]<copiaDer[D]){
				a[x]=copiaIzq[I];
				I++;
			}else{
				a[x]=copiaDer[D];
				D++;
			}
			x++;
		}
		if(I==tamIzq){
			while(D<tamDer){
				a[x]=copiaDer[D];
				D++;
				x++;
			}
		}else{
			while(I<tamIzq){
				a[x]=copiaIzq[I];
				I++;
				x++;
			}
		}
	}
};

template <class T>
class QuickSort: public Sort<T>{
	public:
	int part = 0, sor = 0;
	void sort(T *a, int size){
		sortAux(a, 0, size-1);
	}
	
	private:
	void sortAux(T *a, int inicio, int fin){
		sor++;
		cout<<"SortAux "<<sor<<": (a, "<<inicio<<", "<<fin<<")"<<endl;
		if(fin<=inicio){
			return;
		}
		int v=partition(a, inicio, fin);
		sortAux(a, inicio, v-1);
		sortAux(a, v+1, fin);
	}
	
	int partition(T *a, int inicio, int fin){
		part++;
		cout<<"Partition "<<part<<": (a, "<<inicio<<", "<<fin<<")"<<endl;
		int v=inicio;
		int lo=v+1;
		int hi=fin;
		while(true){
			while(a[lo]<a[v] && lo<=fin){
				lo++;
			}
			while(a[hi]>a[v]&&hi>=inicio){
				hi--;
			}
			if(lo>=hi){
				break;
			}
			this->intercambiar(a, lo,hi);
		}
		this->intercambiar(a, v, hi);
		return hi;
	}
};


int main (){
    int size = 7;
    int a[size]={9,5,3,11,20,1,13};
    QuickSort <int> quickSort;
	quickSort.sort(a,7);

}