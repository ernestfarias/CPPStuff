#include <fstream.h>
#include <stdlib.h>

class error_de_apertura{};
class error_de_lectura{};
class error_de_escritura{};

void realizar_copia(char* archivo_fuente, char* archivo_destino)
{
	ifstream fuente(archivo_fuente, ios::binary);
}
char linea[1];
if(fuente.fail())
{
	throw error_de_apertura();  //fuente.fail esta indicando que es un evento
}
else
{
	ofstream destino(archivo_destino, ios::binary);
	if(destino.fail())
	{
		throw error_de_apertura();
	}
	else
	{
		while(!fuente.eof()&&!fuente.fail())
		{
			fuente.read(linea, sizeof(linea));
			if(fuente.good())
			{
				destino.write(linea, sizeof(linea));
				if(destino.fail())
				{
					throw error_de_escritura;
				}
			}
			else if (!fuente.eof())
			{
				throw error_de_lectura();
			}
		}
		fuente.close();
		destino.close();
	}
}

main(int argc,char** argv)
{
	try
	{
		realizar_copia(argv[1],argv[2]);
	}
	catch(error_de_apertura)
	{
		cerr<<"Error al abrir el archivo"<<endl;
		exit(1);
	}
	catch(error_de_lectura)
	{
		cerr<<"Error al leer el archivo"<<endl;
	}
	catch(error_de_escritura)
	{
		cerr<<"Error al escribir el archivo"<<endl;
	}
}