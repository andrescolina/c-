#include "Salario.h"
#include <fstream>
char op,op2;
int acum = 0,x;
string Data[12];
void MenuActualizar(),LimpiarCampo(int,int,int),DatosActualizados(int);
int main()
{

	if(!ValidarArchivo())
	{
		CrearArchivo();	
	}

	string Nombre = "",Apellido = "",Datos,Reemplazar = "|";
	int Telefono = 0,Cedula=0,contador=0;
	float ValorHora = 0;
	int HorasTrabajadas = 0,OK;
	Salario _Salario(Cedula,Nombre,Apellido,Telefono,HorasTrabajadas,ValorHora);
	bool Numero = true;
    do 
   {				
       panta1 ();
	   gt(20,9);co  "MENU PRINCIPAL PARA PAGOS DE SUELDO";
	   gt(17,11);co "I. Insertar datos del empleado";
	   gt(17,12);co "C. Consultar datos del empleado";
	   gt(17,13);co "A. Actualizar datos del empleado";
	   gt(17,14);co "E. Eliminar datos del empleado";
	   gt(17,15);co "L. Listar datos del empleado";
	   gt(17,16);co "S. SALIR";
	   gt(17,18);co "OPCION [ ]";
	   gt(25,18);op=toupper(getche());
	   switch(op)
	   {
	   	case 'I':	   
			panta1 ();
			gt(20,9);co  "INSERTA LOS DATOS DEL EMPLEADO";
			gt(10,11);co "DIGITE CEDULA EMPLEADO";
			gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
			if(!Numero)
			{
				do
				{
					AccionNoNumero(33,11);
					gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
				}while(!Numero);
			}
			if(!BuscarArchivo(Cedula))
			{
				gt(10,12);co "DIGITE NOMBRE EMPLEADO";
		  	 	gt(33,12);getline(cin, Nombre);
		  	 	gt(10,13);co "DIGITE APELLIDO";
				gt(27,13);getline(cin, Apellido);
				gt(10,14);co "DIGITE TELEFONO DEL EMPLEADO";
				gt(43,14);Numero=scanf("%d",&Telefono);cin.ignore();
				if(!Numero)
				{
					do
					{
						AccionNoNumero(43,14);
						gt(43,14);Numero=scanf("%d",&Telefono);cin.ignore();
					}while(!Numero);
				}
			
				gt(10,15);co "DIGITE HORAS TRABAJADAS";
				gt(35,15);Numero=scanf("%d",&HorasTrabajadas);cin.ignore();
				if(!Numero)
				{
					do
					{
						AccionNoNumero(35,15);
						gt(35,15);Numero=scanf("%d",&HorasTrabajadas);cin.ignore();
					}while(!Numero);
				}
				
				gt(10,16);co "DIGITE EL VALOR DE LA HORA";
				gt(38,16);Numero=scanf("%f",&ValorHora);cin.ignore();
				if(!Numero)
				{
					do
					{
						AccionNoNumero(38,16);
						gt(38,16);Numero=scanf("%d",&ValorHora);cin.ignore();
					}while(!Numero);
				}
				_Salario.InsertarDatosEmpleado(Cedula,Nombre,Apellido,Telefono,HorasTrabajadas,ValorHora,true);
				gs;
			}else
			{
				t7;
				main();
			}
		break;
	   	case 'C':
	   		Datos = "";
	   		contador = 0;
		   panta1 ();
		   	gt(20,9);co  "BUSCAR LOS DATOS DEL EMPLEADO";
			gt(10,11);co "DIGITE CEDULA EMPLEADO";
			gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
			if(!Numero)
			{
				do
				{
					AccionNoNumero(33,11);
					gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
				}while(!Numero);
			}
			if(BuscarArchivo(Cedula))
			{
				Datos = ObtenerDatos(Cedula);	
				size_t pos = 0;
					while ((pos = Datos.find(Reemplazar)) != std::string::npos) {
					    Data[contador] = Datos.substr(0, pos);
					    Data[contador] = EliminarEspacios(Data[contador]);
						Datos.erase(0, pos + Reemplazar.length());
					    contador++;
					}
					panta1();
					_Salario.InsertarDatosEmpleado(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),convertStringaInt(Data[5]),convertStringaInt(Data[6]),false);
					_Salario.MostrarDatos();	
			}else
			{
				gt(10,13);co "No se Encontro la persona con la cedula: "<<Cedula;
				gs;
			}
		   break;
		   
		case 'A':
			Datos = "";
	   		contador = 0;
		   	panta1 ();
		   	gt(20,9);co  "ACTUALIZAR LOS DATOS DEL EMPLEADO";
			gt(10,11);co "DIGITE CEDULA EMPLEADO";
			gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
			if(!Numero)
			{
				do
				{
					AccionNoNumero(33,11);
					gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
				}while(!Numero);
			}
			if(BuscarArchivo(Cedula))
			{
				Datos = ObtenerDatos(Cedula);	
				size_t pos = 0;
					while ((pos = Datos.find(Reemplazar)) != std::string::npos) {
					    Data[contador] = Datos.substr(0, pos);
					    Data[contador] = EliminarEspacios(Data[contador]);
						Datos.erase(0, pos + Reemplazar.length());
					    contador++;
					}
					MenuActualizar();
					gt(27,11);co Data[1];gt(27,12);co Data[2];gt(29,13);co Data[3];gt(29,14);co Data[4];gt(37,15);co Data[5];gt(42,16);co Data[6];
					do
					{
						gt(25,18);op2=toupper(getche());
						switch(op2)
						{
							case 'N':
								LimpiarCampo(27,12,Data[2].length());
								gt(27,12);getline(cin, Nombre);
								_Salario.InsertarDatosEmpleado(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),convertStringaInt(Data[5]),convertStringaInt(Data[6]),false);
								ActualizarArchivo(convertStringaInt(Data[1]),Nombre,Data[3],convertStringaInt(Data[4]),convertStringaInt(Data[5]),convertStringaInt(Data[6]),_Salario.GetSueldo());
								DatosActualizados(convertStringaInt(Data[1]));
								gs;
							break;
							case 'A':
								LimpiarCampo(29,13,Data[3].length());
								gt(29,13);getline(cin, Apellido);
								_Salario.InsertarDatosEmpleado(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),convertStringaInt(Data[5]),convertStringaInt(Data[6]),false);
								ActualizarArchivo(convertStringaInt(Data[1]),Data[2],Apellido,convertStringaInt(Data[4]),convertStringaInt(Data[5]),convertStringaInt(Data[6]),_Salario.GetSueldo());
								DatosActualizados(convertStringaInt(Data[1]));
								gs;
							break;
							case 'T':
							 	LimpiarCampo(29,14,Data[4].length());
							 	gt(29,14);Numero=scanf("%d",&Telefono);cin.ignore();
								if(!Numero)
								{
									do
									{
										AccionNoNumero(29,14);
										gt(29,14);Numero=scanf("%d",&Telefono);cin.ignore();
									}while(!Numero);
								}
								_Salario.InsertarDatosEmpleado(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),convertStringaInt(Data[5]),convertStringaInt(Data[6]),false);
								ActualizarArchivo(convertStringaInt(Data[1]),Data[2],Data[3],Telefono,convertStringaInt(Data[5]),convertStringaInt(Data[6]),_Salario.GetSueldo());
								DatosActualizados(convertStringaInt(Data[1]));
							 	gs;
							break;
							case 'H':
								LimpiarCampo(37,15,Data[5].length());
								gt(37,15);Numero=scanf("%d",&HorasTrabajadas);cin.ignore();
								if(!Numero)
								{
									do
									{
										AccionNoNumero(37,15);
										gt(35,15);Numero=scanf("%d",&HorasTrabajadas);cin.ignore();
									}while(!Numero);
								}
								_Salario.InsertarDatosEmpleado(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),HorasTrabajadas,convertStringaInt(Data[6]),false);
								ActualizarArchivo(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),HorasTrabajadas,convertStringaInt(Data[6]),_Salario.GetSueldo());
								DatosActualizados(convertStringaInt(Data[1]));
								gs;
							break;
							case 'V':
								LimpiarCampo(42,16,Data[6].length());
								gt(42,16);Numero=scanf("%f",&ValorHora);cin.ignore();
								if(!Numero)
								{
									do
									{
										AccionNoNumero(42,16);
										gt(42,16);Numero=scanf("%d",&ValorHora);cin.ignore();
									}while(!Numero);
								}
								_Salario.InsertarDatosEmpleado(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),convertStringaInt(Data[5]),ValorHora,false);
								ActualizarArchivo(convertStringaInt(Data[1]),Data[2],Data[3],convertStringaInt(Data[4]),convertStringaInt(Data[5]),ValorHora,_Salario.GetSueldo());
								DatosActualizados(convertStringaInt(Data[1]));
								gs;
							break;
							case 'S':
								main();
							break;
							
							default: t5;	
						}	
					}while(op2 != 'S');
			}else
			{
				gt(10,13);co "No se Encontro la persona con la cedula: "<<Cedula;
			}
			gs;
		   	break;
		   	
		case 'E':
			char verificacion;
		   	panta1 ();
		   	gt(20,9);co  "ELIMINAR LOS DATOS DEL EMPLEADO";
			gt(10,11);co "DIGITE CEDULA EMPLEADO";
			gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
			if(!Numero)
			{
				do
				{
					AccionNoNumero(33,11);
					gt(33,11);Numero=scanf("%d",&Cedula);cin.ignore();
				}while(!Numero);
			}
			if(BuscarArchivo(Cedula))
			{
				gt(10,13);co "ESTA SEGURO /A QUE DESEA ELIMINAR LOS DATOS CON LA CEDULA: "<<Cedula;
				gt(10,14);co "S. SI";
				gt(10,15);co "N. NO";
				gt(17,17);co "OPCION [ ]";
				gt(25,17);verificacion=toupper(getche());
				if(verificacion == 'S')
					EliminarArchivo(Cedula);
			}else
			{
				gt(10,13);co "No se Encontro la persona con la cedula: "<<Cedula;
			}
			gs;
			main();
		   	break;
		   	
		case 'L':
		   	LeerArchivo();
		   	break;
		   	
		case 'S':exit(0);
		
		default: t5;	
	   }
	}
	while(op !='S');
}


void MenuActualizar()
{
	panta1();
	gt(20,9);co  "ACTUALIZAR LOS DATOS DEL EMPLEADO";
	gt(10,11);co "CEDULA EMPLEADO: ";
	gt(10,12);co "NOMBRE EMPLEADO: ";
	gt(10,13);co "APELLIDO EMPLEADO: ";
	gt(10,14);co "TELEFONO EMPLEADO: ";
	gt(10,15);co "HORAS TRABAJADAS EMPLEADO: ";
	gt(10,16);co "VALOR HORA TRABAJADAS EMPLEADO: ";
	gt(17,18);co "OPCION [ ]";
	gt(7,21);co "N.NOMBRES A.APELLIDOS T.TELEFONO H.HORAS V.VALOR HORA S.SALIR";
}
void DatosActualizados(int _Cedula)
{
	int contador = 0;
	string Datos,Reemplazar = "|";
	Datos = ObtenerDatos(_Cedula);	
	size_t pos = 0;
		while ((pos = Datos.find(Reemplazar)) != std::string::npos) {
		    Data[contador] = Datos.substr(0, pos);
		    Data[contador] = EliminarEspacios(Data[contador]);
			Datos.erase(0, pos + Reemplazar.length());
		    contador++;
		}
		contador = 0;
		MenuActualizar();
		gt(27,11);co Data[1];gt(27,12);co Data[2];gt(29,13);co Data[3];gt(29,14);co Data[4];gt(37,15);co Data[5];gt(42,16);co Data[6];
}
void LimpiarCampo(int x,int y, int NumeroCampos)
{
	int i;
	gt(x,y);
	for(i=0;i<NumeroCampos;i++)
	{
		co " ";
	}
}

