#include <conio.h>
#include <stdio.h>
#include <iostream.h>

struct Nodo{
int valor;
Nodo* anterior;
Nodo* siguiente;
};

class lista_enlazada{
	public:
		lista_enlazada(void);
		void mostrar_lista(void);
		Nodo* anexar_valor(int); //Recibe un int y devuelve un puntero
	private:
		Nodo* principio;//referencia principio de lista.
		Nodo* fin;// referencia final de lista.

};

lista_enlazada::lista_enlazada(void){
	principio = NULL;//NULL es una constante no es = a 0 es un parametro.
	fin = NULL; //Idem
	}

//Como se muestra la lista:
//Primero nombre de funcion de mostrar lista
void lista_enlazada::mostrar_lista(void){
	Nodo*  nodo;   //Con minuscula para marcar a que nodo nos referimos  (Puntero a estructura de tipo nodo)
	nodo = principio; //Primer elemento de estructura nodo
	while (nodo) {//Mientras nodo distinto de Null y habiendo arrancado en nodo en Principio
	      cout << nodo ->valor << endl;
	      nodo = nodo->siguiente;
	      }
	      }
//Funcion Anexar valor devuelve un puntero a un struct de nodo
Nodo* lista_enlazada::anexar_valor(int valor){ //valor = Nombre de fantasia del parametro
//Definio variable comodin a nodo y le doy el valor de fin
Nodo* ptr = fin; //Porque asi tenemos un puntero al final de la lista y uno al penultimo lugar de la lista
fin = new Nodo; //New reserva espacio en memoria en forma dinamica Idem Malloc en C para el tipo de datos que viene a su derecha
// y devuelve un puntero a  donde empieza el nuevo nodo en creado.
 //podria ocurrir que principio sea = NUll o vacio entonces
	if (principio == NULL){
		principio = fin;}
		else {
		ptr->siguiente  = fin;}

	if (fin){
	fin ->siguiente = NULL; //Despues del ultimo elemento de la lista no hay nada
	fin->anterior = ptr;
	fin->valor = valor;  // No hay conflicto de resolucion de ambito pq  el compilador sabe que un valor es el del nodo y el otro es el param de la funcion
	}
	return(fin);
	}

 //Finalizado servidor

 /*Comenzamos cliente*/
main(){
clrscr();
lista_enlazada lista; //Inicializo lista
	for (int i= 0; i<10; i++)
		lista.anexar_valor(i);
		getch();
	    lista.mostrar_lista();
	    getch();

	for(i= 10; i<20;i++)
		lista.anexar_valor(i);
	    lista.mostrar_lista();
	    getch();
getch();
return(0);
}

