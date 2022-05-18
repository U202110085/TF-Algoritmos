#pragma once
#include "libs.h"
#include "CPasajero.h"
#include "CConductor.h"

class CViaje
{
public:
	//Constructores y destructores
	CViaje(double, double, CPasajero*, CConductor*);
	~CViaje();

	//Set y get
	double getDistancia() { return distancia; }
	double getCosto() { return costo; }
	CPasajero* getPasajero() { return pasajero; }
	CConductor* getConductor() { return conductor; }

	//Metodos
	void printViaje();

private:
	double distancia;
	double costo;
	CPasajero* pasajero;
	CConductor* conductor;
};

CViaje::CViaje(double d, double c, CPasajero* p, CConductor* co)
{
	distancia = d;
	costo = c;
	pasajero = p;
	conductor = co;
}

CViaje::~CViaje()
{
}

void CViaje::printViaje()
{
	cout << "Pasajero del viaje: " << pasajero->getName();
	cout << "\nConductor del viaje: " << conductor->getName();
	cout << "\nDistancia recorrida: " << distancia << "km";
	cout << "\nCosto del viaje: s/" << costo;
}