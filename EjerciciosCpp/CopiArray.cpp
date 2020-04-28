#include <iostream>

template <class T>
class Vector{
	private:
		T *a;
        T *b;
	public:
		int size;
		int count;
		Vector(){
			a=new T[1024]();
            size = 1024;
			count=0;
		}
		
		Vector(int s){
			size=s;
			a=new T[s]();
			count=0;
		}
		
		void append(T elemento){
            if (count < size){
                a[count]= elemento;
                count++;
            }
            else{
                b = new T[size*2]();
			    for (int i = 0; i<size; i++){
                    b[i]=a[i];
                }
                size = size*2;
                delete[]a;
                a = temp;
                a[count] = elemento;
                count++;
            }

		}
		
		void insert(T elemento, int posicion){
		}
		
		
};

int main(){
	Vector<int> v(20);
}