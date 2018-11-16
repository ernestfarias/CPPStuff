#include <iostream.h>
#include <string.h>
#include <conio.h>
/*ATRIBUTOS ESTATICOS DE UNA CLASE*/
class nuclear{
	public:
		nuclear(char* nombre,int limite);
		void mostrar_estado(void);
		void establecer_fusion(void);
	private:
		static int fusion;
		char nombre[64];
		int limite;/*miembro estatico de la clase*/
};
int nuclear::fusion = 0;/*solo es posible porque es una variable estatica, sino fuera asi necesitaria una funcion constructor y destructor*/

nuclear::nuclear(char* nombre, int limite){
	strcpy(nuclear::nombre,nombre);
	nuclear::limite = limite;
};

void nuclear::mostrar_estado(void){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Limite: "<<limite<<endl;
	cout<<"Fusion: "<<fusion<<endl<<endl;
};

void nuclear::establecer_fusion(void){
	fusion = 1;
};

main(){
clrscr();
nuclear robinete("Verficar Robinete",1001);
nuclear fancor("Verificar Fancor",2002);
robinete.mostrar_estado();
fancor.mostrar_estado();
robinete.establecer_fusion();
robinete.mostrar_estado();
fancor.mostrar_estado();
getch();
return(0);
};