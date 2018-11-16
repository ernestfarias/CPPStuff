// Archivo Binario entrada

#include <fstream.h>
#include <conio.h>
#include <iomanip.h> //manipulador de entrada salida

main()
	{
	float precio;
	ifstream existencias ("Existencias.dat",ios::binary ); //IFstream es para input al archivo.

	while (!existencias.eof()){
	existencias.read ((char*) & precio, sizeof(float)); //Leo como vector de cadena pero con  saltos de 4 bytes
	cout << setprecision(2) << setiosflags(ios::showpoint | ios:: fixed)  << precio << endl;
	} //Formateo con iomanip.h de lo que se saca por pantalla

	existencias.close(); //Cuando cierro el archivo no lo descargo de memoria. Lo unico que hace clos ees eliminar el puntero a la direccion del archivo. La referencia al mismo.
	getch();
	return(0);
	}



