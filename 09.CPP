# include <iostream.h>
#include <conio.h>
#include <string.h>
/*CLASES ANIDADAS*/

/*no se declara un destructo porque el objeto se elimina,
ya que como no se genera codigo extra no se necesita destructor*/
class fecha{
	public:
		fecha(int dia, int mes, int agno);
		void mostrar(void);
	private:
		int dia;
		int mes;
		int agno;
};

class empleado{
	public:
		empleado (char* nombre, int edad, int dia, int mes, int agno);
		~empleado(void);
		void mostrar_empleado(void);
	private:
		char nombre[64];
		int edad;
		fecha* fecha_contrato;/* en windows ser¡a como un descriptor de medios*/
};

fecha::fecha(int dia, int mes, int agno){
	fecha::dia=dia;
	fecha::mes=mes;
	fecha::agno=agno;
};

void fecha::mostrar(void){
	cout<<dia<<'/'<<mes<<'/'<<agno<<endl;
};

empleado::empleado(char* nombre, int edad, int dia, int mes, int agno){
	strcpy(empleado::nombre,nombre);
	empleado::edad=edad;
	fecha_contrato=new fecha(dia,mes,agno); /*new asigna un lugar dinamico en memoria y devuelve un puntero del tipo de dato despu‚s declarado*/
};

empleado::~empleado(void){/*aca se debe eliminar el puntero a la clase fecha porque sino no se elimina nunca*/
	delete fecha_contrato;/*elimino el puntero a la clase fecha*/
};

void empleado::mostrar_empleado(void){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
	cout<<"Fecha de contrato: ";
	fecha_contrato->mostrar();//dentro de cout no puedo hacer referencia al puntero de una funci¢n
};

main(){
clrscr();
empleado administrador("Jose",33,25,12,2004);
administrador.mostrar_empleado();
getch();
return	(0);
};