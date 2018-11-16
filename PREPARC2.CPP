#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
struct Nodo
{
int ID;
char nombre[64];
int cantidad;
float precio;

Nodo* anterior;
Nodo* siguiente;
};

class lista_enlazada
{
  Nodo* principio;
  Nodo* fin;
   public:
  lista_enlazada(void);
  void mostrar(void);
  Nodo* agregar(int, char*, int, float);
  Nodo* modificar(int ,char*, int, float);
  Nodo* borrar(int);
   };

lista_enlazada::lista_enlazada(void){//contructor pongo en null el 1er y untimo reg
 principio=NULL;
 fin=NULL;
};


//agregar va a devolver un dato del tipo Nodo, un puntero a un Nodo
Nodo* lista_enlazada::agregar(int ID, char* nombre, int cantidad, float precio){
 Nodo* ptfila = fin; //antes de empezar le pongo el fin que tenia antes a la penultima fila
 fin = new Nodo; // hago una nueva fila
   if (principio == NULL){//si es la 1er y unica fila
    principio = fin;
    }
    else{
    ptfila->siguiente = fin;
    }

    if (fin){
    fin->siguiente=NULL;
    fin->anterior=ptfila;
    fin->ID=ID;
    strcpy(fin->nombre,nombre);
    fin->cantidad=cantidad;
    fin->precio=precio;

    }
 return(fin);//devuelve el valor de fin a la funcion agregar ???

};




void lista_enlazada::mostrar(void){
  Nodo* fila;
  fila = principio;//lo mando a la 1er fila o registro

  while(fila)//mientras fila no sea NULL
  {
  //muestro fila
  cout<<fila->ID<<" "<<fila->nombre<<" "<<fila->cantidad<<" "<<fila->precio<<" "<<endl;
  fila=fila->siguiente;
  }

};

Nodo* lista_enlazada::modificar(int id,char* nom,int cant,float pre)
{
Nodo* fila;
fila = principio;
 while(fila){
  if (fila->ID == id){
  //fila->nombre = nom;
  strcpy(fila->nombre, nom);
  fila->cantidad = cant;
  fila->precio = pre;
    }
  fila= fila->siguiente;
  }

}
;

main(){
clrscr();
lista_enlazada tabla;
int opcion;
int ingID;
char INGN[64];
int ingcantidad;
float ingprecio;


//   cout<<"Ingrese nombre:"<<endl;
  // cin.get(INGN,sizeof(INGN));

  while(opcion != 0){
cout<<"Opciones: 1)Agregar,2)Modifica,3)Borra,4)Mostrar, 0)SALIR!"<<endl;
cin>>opcion;

  if (opcion == 1) { //agrego item
   cout<<"Ingrese ID:";
   cin>>ingID;
   cout<<"Ingrese nombre:"<<endl;
   cin.get(INGN,64);
    if (cin.eof())
       break;
   cout<<"Ingrese cantidad:";
   cin>>ingcantidad;
   cout<<"Ingrese precio:";
   cin>>ingprecio;
       tabla.agregar(ingID,INGN,ingcantidad,ingprecio);
       };

  if (opcion == 2){
  //hacer el borrar
  };
   if(opcion == 4){
   tabla.mostrar();
   };
//getch();
		     };//fin del while

return(0);

}