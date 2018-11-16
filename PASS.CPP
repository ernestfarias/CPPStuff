#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
class pass{
public:
pass(void);
~pass(void);
void compar(void);
private:
char passING[64];
};

pass::pass(void)
{
cout<<"Ingrese clave"<<endl<<endl;
cin.get(passING,sizeof(passING));
}
void pass :: ~pass(void){
cout<<"aca se puede escribir cosas malas"<<endl<<endl;
getch();
}

void pass :: compar(void)
{
if (!strcmp("pp",passING))
{
cout<<"Clave Correcta"<<endl;
}
else
{
cout<<"Clave incorrecta"<<endl;
}
}

main()
{
	clrscr();
	 pass testpass;
	 //testpass.pass();
	 testpass.compar();
	 getch();
	 return(0);
	 }




