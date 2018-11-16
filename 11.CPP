#include <iostream.h>
#include <string.h>
#include <conio.h>
/*ARREGLOS O VECTORES DE OBJETOS*/

class fecha{
	public:
		fecha(int dia,int mes, int agno);//primer constructor
		fecha(void);//segundo constructor
		~fecha(void);//un solo destructor
		void mostrar_fecha(void);
	private:
		int dia;
		int mes;
		int agno;
};

fecha::fecha(int dia, int mes, int agno){//primer constructor
	fecha::dia=dia;
	fecha::mes = mes;
	fecha::agno = agno;
	cout<<"Entra el constructor con fecha: ";
	mostrar_fecha();
};

fecha::fecha(void){//segundo constructor
	cout<<"Entra el constructor sin fecha: "<<endl;
};

fecha::~fecha(void){
	cout<<"Entra el destructor de fecha: ";
	mostrar_fecha();
};

void fecha::mostrar_fecha(void){
	cout<<dia<<'/'<<mes<<'/'<<agno<<endl;
};

main(){
clrscr();
fecha dia_festivo[5];
fecha navidad(25,12,2005);
fecha malvinas(2,4,2005);
fecha independencia(9,7,2005);
fecha agno_nuevo(31,12,2005);
fecha cumpleagnos(7,3,2005);
dia_festivo[0]= navidad;
dia_festivo[1]=malvinas;
dia_festivo[2]=independencia;
dia_festivo[3]=agno_nuevo;
dia_festivo[4]=cumpleagnos;
getch();
return(0);
};