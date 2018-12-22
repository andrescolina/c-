#include "panta.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;
const string NombreFichero = "Empleados.txt";
const string NombreAuxiliar = "Auxiliar.txt";
ofstream EmpleadosArchivo;
ofstream EmpleadosArchivoss;
ofstream Auxiliares;

string convertIntaString(int number)
{
   stringstream ss;
   ss << number;
   return ss.str();
}

int convertStringaInt(string number)
{
	return atoi(number.c_str());
}

void DibujarContorno()
{
	
		int n;
		EmpleadosArchivo<<endl<<"\t";
		for(n=0;n<=136;n++)
		{
			if(n==0)
			{
				EmpleadosArchivo<<"|";
			}else if (n==136)
			{
				EmpleadosArchivo<<"|";
			}else
			{
				EmpleadosArchivo<<"-";
			}
		}
}

void DibujarContorno2()
{
	
		int n;
		EmpleadosArchivoss<<endl<<"\t";
		for(n=0;n<=136;n++)
		{
			if(n==0)
			{
				EmpleadosArchivoss<<"|";
			}else if (n==136)
			{
				EmpleadosArchivoss<<"|";
			}else
			{
				EmpleadosArchivoss<<"-";
			}
		}
}

void DibujarContorno3()
{
	
		int n;
		for(n=0;n<=136;n++)
		{
			if(n==0)
			{
				Auxiliares<<"|";
			}else if (n==136)
			{
				Auxiliares<<"|";
			}else
			{
				Auxiliares<<"-";
			}
		}
}
void CrearArchivo()
{
	EmpleadosArchivo.open(NombreFichero.c_str(),ios::out);
	if(!EmpleadosArchivo.fail())
	{
		DibujarContorno();
		
		EmpleadosArchivo<<endl<<"\t| "<<"Fecha de Modificacion: "<< __DATE__ <<" "<<__TIME__ << "\t\tUniversidad Cooperativa\t\t"<<"Juan David Ossa Arevalo\t      Luis David Vargas |";
		DibujarContorno();
		
		EmpleadosArchivo<<endl<<"\t|\t\t\t\t\t\t\t"<<"DATOS DE LOS EMPLEADOS \t\t\t\t\t\t\t\t|";
		DibujarContorno();
		
		EmpleadosArchivo<<endl<<"\t| "<<"Cedula\t"<<"|"<<"Nombres\t\t"<<"|"<<"Apellidos\t\t"<<"|"<<"Telefono\t"<<"|"<<"Horas Trabajadas\t"<<"|"<<"Valor Hora\t"<<"|Sueldo\t\t|";
		DibujarContorno();
		EmpleadosArchivo.close();	
	}else
	{
		panta1();
		gt(20,9);co  "No se pudo crear el archivo Empleados.txt";
		exit(1);
	}
}

void LeerArchivo()
{
	ifstream EmpleadosArchivos;
	string texto;
	EmpleadosArchivos.open(NombreFichero.c_str(),ios::in);
	system("cls");
	if(!EmpleadosArchivos.fail())
	{
		while(!EmpleadosArchivos.eof())
		{
				getline(EmpleadosArchivos,texto);
				cout<<texto<<endl;
		}
		gs;
		EmpleadosArchivos.close();
	}else
	{
		panta1();
		gt(20,9);co  "No se pudo abrir el archivo Empleados.txt";
		exit(1);
	}
}
string EliminarEspacios(string &str)
{
    int size = str.length();
    for(int j = 0; j<=size; j++)
    {
        for(int i = 0; i <=j; i++)
        {
            if(str[i] == ' ' && str[i+1] == ' ')
            {
                str.erase(str.begin() + i);
            }
            else if(str[0]== ' ')
            {
                str.erase(str.begin());
            }
            else if(str[i] == '\0' && str[i-1]== ' ')
            {
                str.erase(str.end() - 1);
            }
        }
    }
    return str;
}



string ObtenerDatos(int Cedula)
{
	ifstream EmpleadosArchivos;
	int Linea = 0,contador=0;
	string texto,ced,nombre,apellido,Reemplazar = "|",s,Datos[12];
	
	EmpleadosArchivos.open(NombreFichero.c_str(),ios::in);
	if(!EmpleadosArchivos.fail())
	{
		while(!EmpleadosArchivos.eof())
		{
				Linea++;
				getline(EmpleadosArchivos,texto);
				std::size_t found = texto.find(convertIntaString(Cedula));
			 	if (found!=std::string::npos)
			 	{
				 	s = EliminarEspacios(texto);
			 		gs;
				}
		}
		EmpleadosArchivos.close();
	}else
	{
		panta1();
		gt(20,9);co  "No se pudo abrir el archivo Empleados.txt";
		exit(1);
	}
	return s;
}

bool BuscarArchivo(int Cedula)
{
	bool Resultado= false;
	int contador=0;
	ifstream EmpleadosArchivos;
	string texto,s,cedula,Datos[12],Reemplazar = "|";
	EmpleadosArchivos.open(NombreFichero.c_str(),ios::in);
	if(!EmpleadosArchivos.fail())
	{
		while(!EmpleadosArchivos.eof())
		{
				getline(EmpleadosArchivos,texto);
				std::size_t found = texto.find(convertIntaString(Cedula));
			 	if (found!=std::string::npos)
			 	{
			 		s = EliminarEspacios(texto);
			 		size_t pos = 0;
					
					while ((pos = s.find(Reemplazar)) != std::string::npos) {
					    Datos[contador] = s.substr(0, pos);
					    Datos[contador] = EliminarEspacios(Datos[contador]);
						s.erase(0, pos + Reemplazar.length());
					    contador++;
					}
					if(Datos[1] == convertIntaString(Cedula))
					{
						 Resultado = true;
					}
				}
		}
		EmpleadosArchivos.close();
	}else
	{
		panta1();
		gt(20,9);co  "No se pudo abrir el archivo Empleados.txt";
		exit(1);
	}

	return Resultado;
	
}


void InsertarEmpleado(int _Cedula,string _Nombre, string _Apellidos, int _Telefono, int _Horas, float _ValorHora, float _Sueldo)
{
	EmpleadosArchivoss.open(NombreFichero.c_str(),ios::app);
	if(!EmpleadosArchivoss.fail())
	{ 
		EmpleadosArchivoss<<endl<<"\t";
		string c,t,h,v,s;
		int n,C,N,A,T,H,V,S,Suma,Total;
		
		c = convertIntaString(_Cedula);
		t = convertIntaString(_Telefono);
		h = convertIntaString(_Horas);
		v = convertIntaString(_ValorHora);
		s = convertIntaString(_Sueldo);

		EmpleadosArchivoss<<"|";
		EmpleadosArchivoss<<_Cedula;
		C =  15 - c.length(); 
		for(n=0;n<C;n++)
		{
			EmpleadosArchivoss<<" ";
		}
		EmpleadosArchivoss<<"|";
		EmpleadosArchivoss<<_Nombre;
		N = 23 - _Nombre.length();
		for(n=0;n<N;n++)
		{
			EmpleadosArchivoss<<" ";
		}
		EmpleadosArchivoss<<"|";
		EmpleadosArchivoss<<_Apellidos;
		A = 23 - _Apellidos.length();
		for(n=0;n<A;n++)
		{
			EmpleadosArchivoss<<" ";
		}
		EmpleadosArchivoss<<"|";
		EmpleadosArchivoss<<_Telefono;
		T = 15 - t.length();
		for(n=0;n<T;n++)
		{
			EmpleadosArchivoss<<" ";
		}
		EmpleadosArchivoss<<"|";
		EmpleadosArchivoss<<_Horas;
		H = 23 - h.length();
		for(n=0;n<H;n++)
		{
			EmpleadosArchivoss<<" ";
		}

		EmpleadosArchivoss<<"|";
		EmpleadosArchivoss<<_ValorHora;
		V = 15 - v.length();
		for(n=0;n<V;n++)
		{
			EmpleadosArchivoss<<" ";
		}
		EmpleadosArchivoss<<"|";
		EmpleadosArchivoss<<_Sueldo;
		S = 15 - s.length();
		for(n=0;n<S;n++)
		{
			EmpleadosArchivoss<<" ";
		}
		EmpleadosArchivoss<<"|";
		DibujarContorno2();
		EmpleadosArchivoss.close();
	}else
	{
		panta1();
		gt(20,9);co "No se pudo abrir el archivo Empleados.txt";
		exit(1);	
	}
}

void InsertarEmpleadoAuxiliar(int _Cedula,string _Nombre, string _Apellidos, int _Telefono, int _Horas, float _ValorHora, float _Sueldo)
{
	Auxiliares.open(NombreAuxiliar.c_str(),ios::app);
	if(!Auxiliares.fail())
	{ 
		Auxiliares<<"\t";
		string c,t,h,v,s;
		int n,C,N,A,T,H,V,S,Suma,Total;
		
		c = convertIntaString(_Cedula);
		t = convertIntaString(_Telefono);
		h = convertIntaString(_Horas);
		v = convertIntaString(_ValorHora);
		s = convertIntaString(_Sueldo);

		Auxiliares<<"|";
		Auxiliares<<_Cedula;
		C =  15 - c.length(); 
		for(n=0;n<C;n++)
		{
			Auxiliares<<" ";
		}
		Auxiliares<<"|";
		Auxiliares<<_Nombre;
		N = 23 - _Nombre.length();
		for(n=0;n<N;n++)
		{
			Auxiliares<<" ";
		}
		Auxiliares<<"|";
		Auxiliares<<_Apellidos;
		A = 23 - _Apellidos.length();
		for(n=0;n<A;n++)
		{
			Auxiliares<<" ";
		}
		Auxiliares<<"|";
		Auxiliares<<_Telefono;
		T = 15 - t.length();
		for(n=0;n<T;n++)
		{
			Auxiliares<<" ";
		}
		Auxiliares<<"|";
		Auxiliares<<_Horas;
		H = 23 - h.length();
		for(n=0;n<H;n++)
		{
			Auxiliares<<" ";
		}

		Auxiliares<<"|";
		Auxiliares<<_ValorHora;
		V = 15 - v.length();
		for(n=0;n<V;n++)
		{
			Auxiliares<<" ";
		}
		Auxiliares<<"|";
		Auxiliares<<_Sueldo;
		S = 15 - s.length();
		for(n=0;n<S;n++)
		{
			Auxiliares<<" ";
		}
		Auxiliares<<"|";
		Auxiliares<<endl;
		Auxiliares.close();
	}else
	{
		panta1();
		gt(20,9);co "No se pudo abrir el archivo Empleados.txt";
		exit(1);	
	}
}
void ActualizarArchivo(int Cedula,string _Nombres,string _Apellidos, int _Telefono, int _Horas, float _ValorHora,float _Sueldo)
{
	int Linea = 0,contador=-1;
	string texto,ced,nombre,apellido,Reemplazar = "|",s,Data,Datos[12];
	ofstream Auxiliar;
	ifstream EmpleadosArchivos;
	Auxiliar.open(NombreAuxiliar.c_str(),ios::app);
	EmpleadosArchivos.open(NombreFichero.c_str(),ios::in);
	if(!Auxiliar.fail() && !EmpleadosArchivos.fail())
	{
		while(!EmpleadosArchivos.eof())
		{
				Linea++;
				getline(EmpleadosArchivos,texto);
				std::size_t found = texto.find(convertIntaString(Cedula));
			 	if (found!=std::string::npos)
			 	{	
					InsertarEmpleadoAuxiliar(Cedula,_Nombres,_Apellidos,_Telefono,_Horas,_ValorHora,_Sueldo);
				}else
				{
					Auxiliar<<texto<<endl;		
				}
		}
		Auxiliar.close();
		EmpleadosArchivos.close();
		remove(NombreFichero.c_str());
		rename(NombreAuxiliar.c_str(),NombreFichero.c_str());
	}else
	{
		panta1();
		gt(20,9);co "No se pudo abrir el archivo Empleados.txt";
		exit(1);	
	}
}
void EliminarArchivo(int Cedula)
{
	int Linea = 0,contador=-1;
	string texto;
	ofstream Auxiliar;
	ifstream EmpleadosArchivos;
	Auxiliar.open(NombreAuxiliar.c_str(),ios::app);
	EmpleadosArchivos.open(NombreFichero.c_str(),ios::in);
	if(!Auxiliar.fail() && !EmpleadosArchivos.fail())
	{
		while(!EmpleadosArchivos.eof())
		{
				Linea++;
				getline(EmpleadosArchivos,texto);
				std::size_t found = texto.find(convertIntaString(Cedula));
			 	if (found!=std::string::npos)
			 	{
					contador = Linea;
				}else
				{
					if(Linea == contador+1)
					{
						
					}else
					{
						Auxiliar<<texto<<endl;	
					}
				}
		}
		Auxiliar.close();
		EmpleadosArchivos.close();
		remove(NombreFichero.c_str());
		rename(NombreAuxiliar.c_str(),NombreFichero.c_str());
	}else
	{
		panta1();
		gt(20,9);co "No se pudo abrir el archivo Empleados.txt";
		exit(1);	
	}
}
bool ValidarArchivo()
{
	ifstream EmpleadosArchivo;
	EmpleadosArchivo.open(NombreFichero.c_str(),ios::in);
	bool Exito = false;
	if(!EmpleadosArchivo.fail())
	{
		Exito = true;
	}
	return Exito;
}
