	//Archivo Binario de Salida
#include <fstream.h>
#include <conio.h>

main(){
float precio;
int cuenta;
ofstream existencias  ("Existencias.dat",ios::binary); //Clase ios input output. Ofstream lo abre para escribir en binario al archivo.
if (existencias.fail())                    //Funcion miembro Fail que podes decir que es publica de ofstream no de Fstream.
	{cerr <<  "Error al abrirel archivo Existencias.dat" << endl; // Escribo en el flujo de error. cerr= Console Error.
	}
	else
	{for (cuenta = 1;cuenta <= 30; cuenta ++){
		precio = cuenta *300.0;
		existencias.write((char*)& precio, sizeof(float)); //Referencio la direccion de precio como la direccion de un puntero a cadena. Casteo como una cadena con un puntero al primer elemento y de tama¤o float pq cuenta es float. (casteo precio a char)
	}
	existencias.close();

	}
return(0);
}
