#include <iostream>
using namespace std;
class Empleados{
	private:
		int cedula,Telefono;
		string Nombre,Apellido;
    public:
    	Empleados(int,string,string,int);
    	void SetCedula(int);
    	void SetNombre(string);
    	void SetTelefono(int);
    	void SetApellido(string);
    	int GetCedula();
    	string GetNombre();
    	int GetTelefono();
    	string GetApellido();
};

Empleados::Empleados(int _Cedula,string _Nombre,string _Apellido,int _Telefono)
{
	this->cedula = _Cedula;
	this->Nombre = _Nombre;
	this->Apellido = _Apellido;
	this->Telefono = _Telefono;
}

void Empleados::SetCedula(int _cedula)
{
	this->cedula = _cedula;
}

void Empleados::SetNombre(string _Nombre)
{
	this->Nombre = _Nombre;
}

void Empleados::SetTelefono(int _Telefono)
{
	this->Telefono = _Telefono;
}

void Empleados::SetApellido(string _Apellido)
{
	this->Apellido = _Apellido;
}

int Empleados::GetCedula()
{
	return this->cedula;
}

string Empleados::GetNombre()
{
	return this->Nombre;
}

int Empleados::GetTelefono()
{
	return this->Telefono;
}

string Empleados::GetApellido()
{
	return this->Apellido;
}

