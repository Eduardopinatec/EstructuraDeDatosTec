#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int busquedaSecuencial(int *a, int buscado, int size){
	for(int i=0; i<size; i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

int busquedaOrdenada1(int *a, int buscado, int size){
	if (buscado>a[size-1]){
		return -1;
	}
	for(int i=0; i<size; i++){
		if(a[i]>buscado){
			return -1;
		}
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
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

int main (){
    int sizeA1=10;
    int sizeA2=1000;
    int sizeA3=1000000;
    int array1 [sizeA1];
    int *array2 = new int [sizeA2];
    int array3 [sizeA3];
    for (int i = 0; i < sizeA1; i++){
        array1[i]=i;
    }
    for (int i = 0; i < sizeA2; i++){
        array2[i]=i;
    }
    for (int i = 0; i < sizeA3; i++){
        array3[i]=i;
    }
    cout<<"Busqueda Arreglo de 10:"<<endl;
    //Secuencial
    auto inicial=high_resolution_clock::now();
    busquedaSecuencial(array1, 1, sizeA1);
	auto fin=high_resolution_clock::now();
	auto duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Secuencial 1\t"<<duracion<<endl;

	inicial=high_resolution_clock::now();
    busquedaSecuencial(array1, 9, sizeA1);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Secuencial 9\t"<<duracion<<endl;
    //Ordenada1
    inicial=high_resolution_clock::now();
    busquedaOrdenada1(array1, 1, sizeA1);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada1 \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaOrdenada1(array1, 9, sizeA1);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada1 \t"<<duracion<<endl;

    //Ordednada2
    inicial=high_resolution_clock::now();
    busquedaOrdenada2(array1, sizeA1, 1, 2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada2 \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaOrdenada2(array1, sizeA1, 9, 2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada2 \t"<<duracion<<endl;

    //Binaria
    inicial=high_resolution_clock::now();
    busquedaBinaria(array1, 0, sizeA1-1, 1);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Binaria \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaBinaria(array1, 0, sizeA1-1, 9);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Binaria \t"<<duracion<<endl;
///////////////////////////////////////////////////////////////////////////////////////////
    cout<<"Busqueda Arreglo de 1000:"<<endl;
    //Secuencial
    inicial=high_resolution_clock::now();
    busquedaSecuencial(array2, 10, sizeA2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Secuencial \t"<<duracion<<endl;

	inicial=high_resolution_clock::now();
    busquedaSecuencial(array2, 999, sizeA2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Secuencial \t"<<duracion<<endl;
    //Ordenada1
    inicial=high_resolution_clock::now();
    busquedaOrdenada1(array2, 10, sizeA2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada1 \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaOrdenada1(array2, 999, sizeA2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada1 \t"<<duracion<<endl;

    //Ordednada2
    inicial=high_resolution_clock::now();
    busquedaOrdenada2(array2, sizeA2, 10, 2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada2 \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaOrdenada2(array2, sizeA2, 999, 2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada2 \t"<<duracion<<endl;

    //Binaria
    inicial=high_resolution_clock::now();
    busquedaBinaria(array2, 0, sizeA2-1, 10);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Binaria \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaBinaria(array2, 0, sizeA2-1, 999);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Binaria \t"<<duracion<<endl;
///////////////////////////////////////////////////////////////////////////////////////////
    cout<<"Busqueda Arreglo de 1000000:"<<endl;
    //Secuencial
    inicial=high_resolution_clock::now();
    busquedaSecuencial(array3, 100, sizeA3);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Secuencial \t"<<duracion<<endl;

	inicial=high_resolution_clock::now();
    busquedaSecuencial(array3, 800985, sizeA3);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Secuencial \t"<<duracion<<endl;
    //Ordenada1
    inicial=high_resolution_clock::now();
    busquedaOrdenada1(array3, 100, sizeA3);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada1 \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaOrdenada1(array3, 800985, sizeA3);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada1 \t"<<duracion<<endl;

    //Ordednada2
    inicial=high_resolution_clock::now();
    busquedaOrdenada2(array3, sizeA3, 100, 2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada2 \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaOrdenada2(array3, sizeA3, 800985, 2);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Ordenada2 \t"<<duracion<<endl;

    //Binaria
    inicial=high_resolution_clock::now();
    busquedaBinaria(array3, 0, sizeA3-1, 100);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Binaria \t"<<duracion<<endl;

    inicial=high_resolution_clock::now();
    busquedaBinaria(array3, 0, sizeA3-1, 800985);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Binaria \t"<<duracion<<endl;
}