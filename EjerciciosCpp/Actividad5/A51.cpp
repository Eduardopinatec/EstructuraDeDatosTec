#include <iostream>
#include <cstdlib>

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
class QuickSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		sortAux(a, 0, size-1);
	}
	
	private:
	void sortAux(T *a, int inicio, int fin){
		if(fin<=inicio){
			return;
		}
		int v=partition(a, inicio, fin);
		sortAux(a, inicio, v-1);
		sortAux(a, v+1, fin);
	}
	
	int partition(T *a, int inicio, int fin){
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

int busquedaBinaria(int *a, int inicio, int fin, int buscado){
	if(fin<inicio){
		return -1;
	}
	int medio=(fin+inicio)/2;
	if(buscado==a[medio]){
		return medio;
	}else if(buscado<a[medio]){
		return busquedaBinaria(a, inicio, medio-1, buscado);
	}else{
		return busquedaBinaria(a, medio+1, fin, buscado);
	}
}

template<class T>
class Tienda: public QuickSort<T> {
    public:
    QuickSort<int> sort;
    int a[1500], count = 1300;
    Tienda (){
        for (int i = 0; i<1500; i++){
            if (i<1300){
                a[i]= rand()%2000001;
            }
            else{
                a[i]=-1;
            }
        }
        sort.sort(a,count);
    }
    void verificar (int id){
        int b = 0;
        b = busquedaBinaria(a, 0, count-1, id);
        cout<<b<<endl;
        if (b == -1){
            cout<<"No existe el producto"<<endl;
        }
        else{
            cout<<"El producto existe y esta en la posición: "<<b<<endl;
        }
    }
    void agregar (int id){
        a[count]=id;
        count++;
        sort.sort(a,count);
    }
    void cantidad (int id1, int id2){
        int c = 0, d = 0;
        c = busquedaBinaria(a, 0, count-1, id1);
        d = busquedaBinaria(a, 0, count-1, id2);
        cout<<d-c<<endl;
    }
};

int main (){
    Tienda<int> tiendita;
    tiendita.verificar(tiendita.a[9]);
    tiendita.agregar(123214);
    tiendita.cantidad(tiendita.a[5], tiendita.a[10]);
}