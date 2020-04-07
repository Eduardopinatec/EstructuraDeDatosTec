#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

int main(){
	int size=45000;
	int *a=new int[size]();
	for(int i=0; i<size; i++){
		a[i]=i;
	}
    cout<<"Arreglo tamaño 45000, numero buscado 45000."<<endl;
	auto inicial=high_resolution_clock::now();
	busquedaBinaria(a, 0, size-1, 45000);
	auto fin=high_resolution_clock::now();
	auto duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Busqueda Binaria \t\t"<<duracion<<endl;
	inicial=high_resolution_clock::now();
	busquedaOrdenada2(a, size-1, 45000, 9);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Busqueda Ordenada2 Paso 9\t"<<duracion<<endl;
    cout<<"Arreglo tamaño 45000, numero buscado 5000."<<endl;
    inicial=high_resolution_clock::now();
	busquedaBinaria(a, 0, size-1, 5000);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Busqueda Binaria \t\t"<<duracion<<endl;
    inicial=high_resolution_clock::now();
	busquedaOrdenada2(a, size-1, 5000, 9);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Busqueda Ordenada2 Paso 9\t"<<duracion<<endl;
	return 0;
}