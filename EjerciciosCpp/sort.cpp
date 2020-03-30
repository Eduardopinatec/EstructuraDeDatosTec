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
    void sort (T *a, int size){
		int it = 0;
        for (int i = 0; i< size; i++) {
            for (int j = 0; j<size-1-i; j++){
				if (a[j]>a[j+1]){
					this->intercambiar
				}
			}
        }
		cout<<"Vueltas: "<<it<<endl;
    }
};

template <class T>
class BubbleSort: public Sort<T>{
	public:
    void sort (T *a, int size){
        for (int i = 0; i< size; i++) {
            for (int j = 0; j<size-1-i; j++){
				if (a[j]>a[j+1]){
					this->intercambiar
				}
			}
        }
		cout<<"Vueltas: "<<it<<endl;
    }
};

int main(){
	int size=5;
	int a[size]={5,4,3,2,1};
	SelectionSort<int> s;
	s.imprimirArreglo(a, size);
	s.sort(a, size);
	s.imprimirArreglo(a,size);
	return 0;
}