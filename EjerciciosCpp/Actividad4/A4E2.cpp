#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int busquedaAux(int *a, int inicio, int fin, int buscado){
	for(int i=inicio; i<=fin; i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}


int busquedaOrdenada2(int *a, int size, int buscado, int paso){
	int i=0;
	for(i=0; i<size; i+=paso){
		int finBloque=i+paso-1;
		
		if(size-1<finBloque){
			finBloque=size-1;
		}
		if(a[finBloque]>=buscado){
				return busquedaAux(a, i, finBloque,buscado);
		}
	}
	return -1;
}

int main (){
    int sizeA1=100000;
    int array1 [sizeA1];
    for (int i = 0; i < sizeA1; i++){
        array1[i]=i;
    }
    int arrayNum [] = {5, 500, 45000, 7919, 9853};
    for (int i = 0; i < 5; i++){
        for (int j = 2; j < 10; j++){
            auto inicial=high_resolution_clock::now();
            busquedaOrdenada2(array1, sizeA1, arrayNum[i], j);
            auto fin=high_resolution_clock::now();
            auto duracion=duration_cast<nanoseconds>(fin-inicial).count();
            cout<<"Ordenada2 \t Paso: "<<j<<" \t Numero buscado "<<arrayNum[i]<<" \t Tiempo de busqueda: "<<duracion<<endl;
        }   
    }

}