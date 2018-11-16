//Archivo de texto salida
#include <fstream.h>
#include <conio.h>
#include <time.h>

main()
	{
	ofstream archivosalida("salida.dat", ios::app); //app de append define que es un arch de texto
	char hora[9];
	char fecha[9];
	archivosalida << _strdate(fecha) << "" << _strtime(hora) << endl; //archivo salida es un objeto similar a cout de console out, donde voy a guardar los datos.
	archivosalida.close();
	getch();
	return(0);
	}