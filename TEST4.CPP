//Archivo Texto Entrada

# include <fstream.h>
# include <conio.h>

main()
	{
	char linea[128];
	long contador_de_linea=0;
	ifstream entrada("salida.dat");
	if (entrada.fail())
		{ cerr << "errar al abrir el archivo " << endl;}

	else
		{while (!entrada.eof()){
		 entrada.getline(linea,sizeof(linea));
		cout << linea << endl;
		if ((++contador_de_linea %24)==0 ){
			cout << " Mas del archivo";
			cin.get();
			}}
			entrada.close();
			}
getch();
return(0);
}



