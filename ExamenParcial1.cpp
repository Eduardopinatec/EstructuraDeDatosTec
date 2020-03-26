#include <iostream>

using namespace std;

int busqueda(int *a, int buscado, int size){

	for(int i=0; i<size; i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

class Tienda{
    public:
        int *cantidad;
        int *codigo;
        int lugar = -1;
        int contador = 0;
        Tienda (){
            int *cantidad = new int [10000]();
            int *codigo = new int [10000]();
            for (int i = 0; i < 10000; i++){
                codigo[i]=-1;
                cantidad[i]=-1;
            }
            contador = 0;
        }
        Tienda (const Tienda& t){
            cantidad = new int [10000]();
            codigo = new int [10000]();
            for (int i = 0; i < 10000; i++){
                codigo[i]=t.codigo[i];
                if (t.cantidad[i]>=0){
                    cantidad[i]=0;
                }
                else{
                    cantidad[i]=-1;
                }
            }
        }
        void vender (int id){
            lugar = busqueda(codigo, id, 10000);
            if (lugar != -1){
                if (cantidad[lugar]==0){
                    cout<<"Si existe el producto pero no hay inventario"<<endl;
                }
                else{
                    cantidad[lugar]-=1;
                    cout<<"Venta Exitosa"<<endl;
                }
            }
            else {
                cout<<"No existe el producto"<<endl;
            }
        }
        void agregarProducto(int id){
            int lugar = busqueda(codigo, id, 10000);
            if (lugar == -1){
                codigo[contador]=id;
                cantidad[contador]=0;
                cout<<"Producto Agregado Exitosamente"<<endl;
                contador++;
            }
            else{
                cout<<"El producto ya existe"<<endl;
            }
        }
        void stock(int id, int stock){
            lugar = busqueda(codigo, id,10000);
            if (lugar != 1){
                cantidad[lugar]+=stock;
            }
            else{
                cout<<"El producto no existe"<<endl;
            }
        }
};

int main(){
    Tienda t;
    t.agregarProducto(1001);
    t.agregarProducto(1002);
    t.agregarProducto(23);
    t.stock(1001, 15);
    t.stock(1002, 3);
    t.stock(1003, 1);//debe imprimir un mensaje de que el producto no existe
    t.stock(23, 1);
    t.vender(23);
    t.vender(1001);
    t.vender(1003);//debe indicar que ese producto no existe
    t.vender(23);//debe indicar que no hay existencias de ese producto
    t.stock(23, 1);
    t.vender(23);
    t.stock(23, 1);
    Tienda otra=t;
    otra.vender(23);//debe indicar que no hay existencias de ese producto;
    return 0;
}