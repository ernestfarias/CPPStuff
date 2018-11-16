/*Manejo de ARCHIVOS DE TEXTO DE SALIDA*/
#include<fstream.h>
#include<conio.h>
#include<time.h> /*para usar fechas*/
main(){
	ofstream archivosalida("Salida.dat",ios::app);
	char hora[9];
	char fecha[9];
	archivosalida<<_strdate(fecha)<<","<<_strtime(hora)<<endl;
	archivosalida.close();
	getch();
	return(0);
	}

