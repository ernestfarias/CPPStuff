#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<fstream.h>//para manejo de archivos
#include<time.h>//para tomar la hora
struct Nodo
{
int ID;
char nombre[64];
int cantidad;
float precio;

Nodo* anterior;   // sin estos dos punteros no seria un NODO
Nodo* siguiente;
};

class lista_enlazada
{
  Nodo* principio;
  Nodo* fin;
   public:
  ~lista_enlazada(void);
  lista_enlazada(void);
  void mostrar(void);
  Nodo* agregar(int, char*, int, float);
  Nodo* modificar(int ,char*, int, float);
  Nodo* borrar(int);
  void guardar(char*);
   };

lista_enlazada::lista_enlazada(void){//contructor pongo en null el 1er y untimo reg
 principio=NULL;
 fin=NULL;
};


void lista_enlazada::~lista_enlazada(void){
cout<<"les ASEGURO que aqui pueden poner"<<endl<<"CODIGO MALICIOSO"<<endl;
cout<<"gracias nico por el newline!"<<endl<<endl<<endl<<"By Ernesto A. Farias...";
getch();
 };
//agregar va a devolver un dato del tipo Nodo, un puntero a un Nodo, para posible futura utilidad, pero puede ser void o int o nada en este caso
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

  while(fila)//mientras fila no sea NULL, es decir EOF
  {
  //muestro fila
  cout<<fila->ID<<" "<<fila->nombre<<" "<<fila->cantidad<<" "<<fila->precio<<" "<<endl;
  fila=fila->siguiente;//avanzo una fila
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

  return(fila);
}
;

Nodo* lista_enlazada::borrar(int IDToDel){

Nodo* fila;
Nodo* filaant;
Nodo* filasig;

fila = principio;


while(fila)
  { //hasta que no sea EOF
    if(fila->ID == IDToDel)  //comparo con el valor que le paso a la func
    {
      if(fila == NULL) //supongo que si es NULL no hay nada (?)
      {
      cout<<"ACA NO HAY NADA PARA BORRAR, CARGA 1ERO!!"<<endl;
      }
      else
      {
      filaant->siguiente = fila->siguiente;   //muevo la fila de adelate atras, supongo que pisoteo el pedazo de memoria con la que tenia en siguiente
      filasig->anterior = fila->anterior;
      }

    }//fin del if si encuento el id a borrar
 fila=fila->siguiente;
 filaant=fila->anterior;
 filasig=fila->siguiente;


  } //fin del while not EOF
return(fila);//le devuelvo el puntero de Nodo a la funcion, al pedo...
};

void lista_enlazada::guardar(char* ruta){ //guardar en un archivo de texto

ofstream archivo(ruta, ios::app); //app es append


Nodo* fila;
fila = principio;

while(fila){

archivo<<" "<<fila->ID<<" "<<fila->nombre<<" "<<fila->cantidad<<" "<<fila->precio<<endl;

fila=fila->siguiente;
}
archivo.close();

}


main(){
clrscr();
lista_enlazada tabla;
int opcion;
int ingID;
char INGN[64];
int ingcantidad;
float ingprecio;
char newline;

//   cout<<"Ingrese nombre:"<<endl;
  // cin.get(INGN,sizeof(INGN));

  while(opcion != 0){
cout<<"Opciones: 1)Agregar,2)Modifica,3)Borra,4)Mostrar,5)cargar en archivo, 0)SALIR! -->";
cin>>opcion;

  if (opcion == 1) { //agrego item
   cout<<"Ingrese ID:";
   cin>>ingID;
   cin.get(newline);//para que me deje meter caracteres pq esta en un while y no me deja meter chars
   cout<<"Ingrese nombre:";
   cin.get(INGN,64);
   cout<<"Ingrese cantidad:";
   cin>>ingcantidad;
   cout<<"Ingrese precio:";
   cin>>ingprecio;
       tabla.agregar(ingID,INGN,ingcantidad,ingprecio);
       };

  if (opcion == 2){//modifico
   cout<<"Ingrese ID que quiere modificar:";
   cin>>ingID;
   cin.get(newline);//para que me deje meter caracteres pq esta en un while y no me deja meter chars
   cout<<"Ingrese nuevo nombre:";
   cin.get(INGN,64);
   cout<<"Ingrese nueva cantidad:";
   cin>>ingcantidad;
   cout<<"Ingrese nuevo precio:";
   cin>>ingprecio;
       tabla.modificar(ingID,INGN,ingcantidad,ingprecio);

  };

  if (opcion == 3){
   cout<<"ingrese el ID a borrar"<<endl;
   cin>>ingID;
	tabla.borrar(ingID);
   };


   if(opcion == 4){
   tabla.mostrar();//muestro lo que tengo cargado
   };
   if(opcion == 5){
   cout<<"ingrese la ruta"<<endl<<"por ej: C:\\pepe.txt"<<endl;
   cin.get(newline);
   cin.get(INGN,64);
      tabla.guardar(INGN);
   };

	     };//fin del while

return(0);

}