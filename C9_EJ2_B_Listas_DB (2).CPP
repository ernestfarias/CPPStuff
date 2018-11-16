#include<string.h>
#include<iostream.h>
#include<conio.h>
//listas doblemente enlazadas
//
//
//definimos el nodo que guarda un unico "valor"
struct Nodo{
	int valor;
	Nodo* anterior;
	Nodo* siguiente;
};
//
//
//
class lista_enlazada{
public:
	lista_enlazada(void);
	void mostrar_lista(void);
	Nodo* anexar_valor(int);
private:
	Nodo* principio;
	Nodo* fin;
};
//
//
//definimos las funciones del consructor
lista_enlazada::lista_enlazada(void){
	principio=NULL;
	fin=NULL;
}

//primero el nombre devuelto por la funcion en este caso es "void"
//nodo es un puntero del tipo Nodo porque refencia a una estructura del tipo
//Nodo
void lista_enlazada::mostrar_lista(void){
	Nodo*nodo;
	nodo=principio;
	while(nodo != NULL){
		cout<<nodo->valor<<endl;
		nodo=nodo->siguiente;
	}
}
//new reserva espacio en memoria para el tipo de dato que viene a su derecha
//
Nodo* lista_enlazada::anexar_valor(int valor){
	Nodo*ptr=fin;
	fin=new Nodo;
	if(principio == NULL)
		principio=fin;
	else
		ptr->siguiente=fin;
	if(fin){
		fin->siguiente = NULL;
		fin->anterior = ptr;
		fin->valor = valor;
		}
		return(fin);
}

int main(void){
clrscr();
lista_enlazada lista;
for (int i=0; i<10; i++)
	lista.anexar_valor(i);
lista.mostrar_lista();
for(i=10; i<20; i++)
	lista.anexar_valor(i);
lista.mostrar_lista();
getch();
return(0);
};



 // nombre, apellido y edad en campos separados
 //latas, listados, modificaciones, bajas(eliminar entradas)