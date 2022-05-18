#pragma once
#include "libs.h"
#include "CPersona.h"

class CPasajero : public CPersona
{
public:
	//Constructores y destructores
	CPasajero(string, int, long long);
	CPasajero(string, int, long long, double);
	~CPasajero();

	//Set y get
	double getMonto();

	//Metodos
	void printData();
private:
};

CPasajero::CPasajero(string n, int a, long long d) : CPersona(n, a, d, 0)
{
}

CPasajero::CPasajero(string n, int a, long long d, double m) : CPersona(n, a, d, m)
{
}

CPasajero::~CPasajero()
{
}

double CPasajero::getMonto() 
{ 
	return tarjeta->getMonto();
}

void CPasajero::printData()
{
	cout << "Nombre: " << this->name << endl;
	cout << "Edad: " << this->age << endl;
	cout << "DNI: " << this->dni << endl;
	cout << "Monto En Tarjeta: " << this->tarjeta->getMonto() << endl;
}