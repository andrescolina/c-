#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;


#define gt(x,y) {COORD a;a.X = x; a.Y = y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);}

#define gs gt(22,22);system ("pause");
#define co cout<<
#define cs system("cls");
#define sy system
#define t5 gt(22,20);co "DIGITE UNA OPCION VALIDA .....";gs
#define t6 gt(22,20);co "NO CORRESPONDE A UN NUMERO .....";gs
#define t7 gt(22,20);co "YA EXISTE UNA CEDULA CON ESE NUMERO .....";gs
#define ci cin>>

void panta1 ()
{
	int n;
	cs
    sy("color C1");
    gt(1,1) ; co char(201);
    gt(80,1) ; co char(187);
    
    gt(1,24) ; co char(200);
    gt(80,24) ; co char(188);
    
    for (n=2;n<80;n++)
    {
        gt(n,1); co char(205); Sleep(2);
        gt(n,7); co char(205);
        gt(n,24);co char(205);
    }
    for (n=2;n<24;n++)
	{
 		gt(1,n);co char(186); Sleep (2);
 		gt(80,n);co char(186);
	}
	
	gt(1,7); co char(204);
	gt(80,7); co char(185);
	gt(22,3); co "Colegio Miguel de Cervantes saveedra";
	gt(3,3); co __DATE__;
	gt(60,3); co __TIME__;
	gt(20,5); co "Leiner Jackson Suarez Colina";
	
  }
  
void AccionNoNumero(int x, int y)
{
	gt(x,y);co "                 ";
	gt(22,20);co"                                 ";
	gt(22,22);co"                                        ";
}

