#include <iostream>
#include <stdlib.h>
using namespace std;
class DatosLaborados
{
	private:
	int Horas,HorasNormales,HorasAntes48h,HorasDespues48h;
	float ValorHora,ValorTotalHorasNormales,ValorTotalHorasAntes48h,ValorTotalHorasDespues48h;
	
	public:
		DatosLaborados(int,float);
		void SetHoras(int);
    	void SetValorHora(float);
    	int GetHoras();
    	int GetHorasNormales();
    	int GetHorasAntes48h();
    	int GetHorasDespues48h();
    	void SetValorTotalHorasNormales(float);
    	void SetValorTotalHorasAntes48h(float);
    	void SetValorTotalHorasDespues48h(float);
    	float GetValorTotalHorasNormales();
    	float GetValorTotalHorasAntes48h();
    	float GetValorTotalHorasDespues48h();
    	float GetValorHora();
    	void CalcularHorasTotales(float,int);
    	
};

DatosLaborados::DatosLaborados(int _Horas,float _ValorHora)
{
	this->Horas = _Horas;
	this->ValorHora = _ValorHora;
}
void DatosLaborados::SetHoras(int H){
	this->Horas = H;
}
void DatosLaborados::SetValorHora(float VHora){
	this->ValorHora = VHora;
}
int DatosLaborados::GetHoras()
{
	return this->Horas;
}
float DatosLaborados::GetValorHora(){
	return this->ValorHora;
}

int DatosLaborados::GetHorasNormales()
{
	return this->HorasNormales;	
}

int DatosLaborados::GetHorasAntes48h()
{
	return this->HorasAntes48h;	
}

int DatosLaborados::GetHorasDespues48h()
{
	return this->HorasDespues48h;	
}

float DatosLaborados::GetValorTotalHorasNormales()
{
	return this->ValorTotalHorasNormales;
}

float DatosLaborados::GetValorTotalHorasAntes48h()
{
	return this->ValorTotalHorasAntes48h;
}

float DatosLaborados::GetValorTotalHorasDespues48h()
{
	return this->ValorTotalHorasDespues48h;
}

void DatosLaborados::SetValorTotalHorasNormales(float _Valor)
{
	this->ValorTotalHorasNormales = _Valor;
}
void DatosLaborados::SetValorTotalHorasAntes48h(float _Valor)
{
	this->ValorTotalHorasAntes48h = _Valor;
}

void DatosLaborados::SetValorTotalHorasDespues48h(float _Valor)
{
	this->ValorTotalHorasDespues48h = _Valor;
}

void DatosLaborados::CalcularHorasTotales(float ValorHoraEmpleado, int HorasTrabajadasEmpleado){
	int resultado = HorasTrabajadasEmpleado - 40;
    if (resultado <= 0)
    {
    	this->HorasNormales = abs(HorasTrabajadasEmpleado);
	}else if(resultado == 0)
	{
		this->HorasNormales = 40;
	}
	else if(resultado > 0)
	{
		this->HorasNormales = 40;
		int resultado2 = resultado - 8;
		if (resultado2 <= 0)
		{
			this->HorasAntes48h = abs(resultado);
		}else if(resultado2 == 0)
		{
			this->HorasAntes48h = 8;
		}else
		{
			this->HorasAntes48h = 8;
			this->HorasDespues48h = resultado2;
		}
	}
	
		this->ValorTotalHorasNormales = this->HorasNormales * this->ValorHora;
		this->ValorTotalHorasAntes48h = this->HorasAntes48h * ((this->ValorHora * 0.2) + this->ValorHora);
		this->ValorTotalHorasDespues48h = this->HorasDespues48h * ((this->ValorHora * 0.4) + this->ValorHora);
}

