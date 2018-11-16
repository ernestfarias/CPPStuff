/*
Programaci¢n II - 20/10/05

Una farmacia vende 4 clases de medicamentos, uno es
1-Dipirona: $ 3.80 por unidad
2-Aspirina: $ 10 * caja de 50 unidades.
3-Amoxidal: $ 8 por unidad
4-Novalgina.: $ 14  por blister (1 blister = 10 unidades)

Se trata de determinar ante una combinaci¢n cualquiera de estas que pida el cliente, ¨Cual es el monto que factura la farmacia si al pasarse de $ 30 se hace un descuento del 25% ?
Hacer un listado(reporte) de todos los medicamentos que tiene la farmacia y sus respectivos precios.
Stock:
Dipirona: 100 unidaddes
Asprina:  100 Cajas
Amoxilina:  80 unidades
Novalgina:  3 blisters
Ademas hacer un listado del stock actualizado una  ves que se hizo una venta y si alguno de los medicamentos esta en cero se debe emitir mensaje para reponerlo urgente
*/

#include <iostream.h>
#include <string.h>
#include <conio.h>

struct Nodo{
int id;
char desc[64];
float precio;
int stock;
Nodo* anterior;
Nodo* siguiente;
};

class lista_enlazada{
	public:
		lista_enlazada(void);
		void mostrar_lista(void);
		Nodo* anexar_valor(int, char*, float, int);
		Nodo* modif_stock(int, int);

	private:
		Nodo* principio;
		Nodo* fin;

};

lista_enlazada::lista_enlazada(void){
	principio = NULL;
	fin = NULL;
	}

//Como se muestra la lista:
//Primero nombre de funcion de mostrar lista
void lista_enlazada::mostrar_lista(void){
	Nodo*  nodo;
	nodo = principio;
	while (nodo) {
	      cout << nodo ->id<<"-";
	      cout << nodo ->desc<<" : $";
	      cout << nodo ->precio<<" Stock=";
	      cout << nodo ->stock<<endl;
	      nodo = nodo->siguiente;
	      }
	      }
//Funcion Anexar valor devuelve un puntero a un struct de nodo
Nodo* lista_enlazada::anexar_valor(int id, char* desc, float precio, int stock){ //valor = Nombre de fantasia del parametro
Nodo* ptr = fin;
fin = new Nodo;
	if (principio == NULL){
		principio = fin;}
		else {
		ptr->siguiente  = fin;}

	if (fin){
	fin ->siguiente = NULL;
	fin->anterior = ptr;
	fin->id = id;
	strcpy(fin->desc, desc);
	fin->precio = precio;
	fin->stock = stock;
	}
	return(fin);
	}
//Modificar stock
Nodo* lista_enlazada::modif_stock(int id, int cant) {
clrscr();
	Nodo*  nodo;
	nodo = principio;
	while (nodo) {
	if (nodo->id ==id) {
		nodo->stock = nodo->stock - cant;}
	if (nodo->stock== 0){
	       clrscr();
	       cout << "Urgente Comprar:" << nodo->desc <<endl;
	       getch(); }
	 if (nodo->precio*cant> 30) {

		cout << "La factura recibe descuento de 25%" << ((nodo->precio*cant) -(((nodo->precio*cant)*25) /100));
				      }
		nodo = nodo->siguiente;
				     }

		     return(0);
}
//Fin Borrar Valor

//Finalizado servidor
/*Comenzamos cliente*/
main(){
int opcion;
int ingcantidad;
int preciovta;
clrscr();
lista_enlazada lista; //Inicializo lista

lista.anexar_valor(1, "dipirona",3.80, 100 );
lista.anexar_valor(2, "Aspirina",10.00, 100 );
lista.anexar_valor(3, "Amoxidal",8.00, 80 );
lista.anexar_valor(4, "Novalgina",14.00,30 );
lista.mostrar_lista();

while (opcion != 0) {
cout << "\n\nIngrese Opcion de  venta:"<< endl;
cout <<" 0 = Salir" << endl;
cin  >> opcion;
cout << "Ingrese Cantidad de  venta: " << endl;
cin  >> ingcantidad;

if (opcion == 1 ){
	lista.modif_stock(opcion, ingcantidad );
	lista.mostrar_lista();
	getch();                                }
if (opcion == 2 ){
	lista.modif_stock(opcion, ingcantidad );
	lista.mostrar_lista();
	getch();                                }

if (opcion == 3 ){
	lista.modif_stock(opcion, ingcantidad );
	lista.mostrar_lista();
	getch();                                }
if (opcion == 4 ){
	lista.modif_stock(opcion, ingcantidad );
	lista.mostrar_lista();
	getch();                                }
}
return(0);
}


