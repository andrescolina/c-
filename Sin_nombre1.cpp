#include <iostream>
#include <stdlib.h>
#include "panta.h"
#include <math.h>
using namespace std;
int main (){
	char opc;
	int a,b,c,d;
	do{
	
panta1 () ; gt(20,9);co  "Bienvenido a su calculadora virtual";
	   gt(17,11);co "Digite la accion que sea realizar:";
	   gt(17,12);co "A.sumar";
	   gt(17,13);co "B.restar";
	   gt(17,14);co "C.Multiplicar";
	   gt(17,15);co "D.Dividir";
	   
	   gt (17,16); co "S.Salir";
	  
	   gt (17,18);co "opcion[ ]";
	   gt(24,18)cin>>opc;
	   
	    
	   switch  (opc){
	   	case 'A': 
		   panta1 ();
		   gt (15,12); co "Digite el primer numero a sumar ";
		   gt(15,13); co"numero: ";
		   gt (22,13);cin>>a;
		   gt (15,15); co "Digite el segundo numero a sumar ";
		    gt(15,16); co" numero: ";
		   gt(22,16);cin>>b; 
		   c=a+b;
		   gt(15,18); co a<<"+"<<b<<"="<<c;
		   system("pause");
		   
	   	break;
	   	case 'B':
	    panta1 ();
		   gt (15,12); co "Digite el primer numero a restar ";
		   gt(15,13); co"numero: ";
		   gt (22,13);cin>>a;
		   gt (15,15); co "Digite el segundo numero a restar ";
		    gt(15,16); co"numero: ";
		   gt(22,16);cin>>b; 
		   c=a-b;
		   gt(15,18); co a<<"-"<<b<<"="<<c;
		   system("pause");
		   
		break;
		case 'C':
			panta1 ();
		   gt (15,12); co "Digite el primer numero a multiplicar ";
		   gt(15,13); co"numero: ";
		   gt (22,13);cin>>a;
		   gt (15,15); co "Digite el segundo numero a multiplicar ";
		    gt(15,16); co" numero: ";
		   gt(22,16);cin>>b; 
		   c=a*b;
		   gt(15,18); co a<<"*"<<b<<"="<<c;
		  system("pause");
		    
		   break;
	   	case 'D':
	   		panta1 ();
		   gt (15,12); co "Digite el primer numero a dividir ";
		   gt(15,13); co"numero: ";
		   gt (22,13);cin>>a;
		   gt (15,15); co "Digite el segundo numero a dividir ";
		    gt(15,16); co" numero: ";
		   gt(22,16);cin>>b; 
		   if (b==0){
		   	gt (15,18);co "El denominador no puede ser 0";
		   	gt (15,19); co "Digite nuevamente el numero";
		   	gt (45,19); cin>>b;
		   	d=a/b;
		   gt(15,20); co a<<"/"<<b<<"="<<d;
		   system("pause");
		   
	
			   }
		   	else{
			   
		   d=a/b;
		   gt(15,18); co a<<"/"<<b<<"="<<d;	
		   system("pause");
		   
		
		   }
		   break;

		
			
		
		   
		
	   	
	   }
	
	   }while(opc!='S');

}
