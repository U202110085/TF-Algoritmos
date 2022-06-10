#pragma once
#include "libs.h"
#include "CPersona.h"
#include "CCalificaciones.h"

class CConductor : public CPersona
{
public:
	//Constructores y destructores
	CConductor(string, int, long long);
	CConductor(string, int, long long, double, Pila<int>*);
	~CConductor();

	//Set y get
	double getMonto();
	int getSizeCalificacion();
	Lista<int>* getCalificaciones();

	//Metodos
	void printData();
	void addCalificacion(int);
	void actualizarCalificacion(Pila<int>*);
	double calculateCalificacion();

private:
	CCalificaciones* calificacion;
};

CConductor::CConductor(string n, int a, long long d) : CPersona(n, a, d, 0)
{
	calificacion = new CCalificaciones(nullptr);
}

CConductor::CConductor(string n, int a, long long d, double m, Pila<int>* pila) : CPersona(n, a, d, m)
{
	calificacion = new CCalificaciones(pila);
}

CConductor::~CConductor()
{
}

double CConductor::getMonto() 
{ 
	return tarjeta->getMonto();
}

int CConductor::getSizeCalificacion()
{
	return calificacion->getSizeCalificaciones();
}

Lista<int>* CConductor::getCalificaciones()
{
	return calificacion->getLista();
}

void CConductor::printData()
{
	cout << "Nombre: " << this->name << endl;
	cout << "Edad: " << this->age << endl;
	cout << "DNI: " << this->dni << endl;
	cout << "Monto En Tarjeta: " << this->tarjeta->getMonto() << endl;
}

void CConductor::addCalificacion(int newC)
{
	calificacion->agregarCaificacion(newC);
}

void CConductor::actualizarCalificacion(Pila<int>* pila)
{
	calificacion->actualizarLista(pila);
}

double CConductor::calculateCalificacion()
{
	calificacion->calcularCalificacion();
	return calificacion->getCalificacion();
}