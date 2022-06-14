#pragma once
#include "libs.h"

class CCalificaciones
{
public:
	//Constructores y destructores
	CCalificaciones(Pila<int>*);
	~CCalificaciones();

	//Metodos
	int getCalificacion();
	int getSizeCalificaciones();
	Lista<int>* getLista();
	void calcularCalificacion();
	void agregarCaificacion(int);
	void actualizarLista(Pila<int>*);
private:
	Lista<int>* lista;
	int calificacion;
};

CCalificaciones::CCalificaciones(Pila<int>* pila)
{
	lista = new Lista<int>();
	while (pila != NULL)
	{
		lista->push_back(pila->pop());
	}
	calcularCalificacion();
}

CCalificaciones::~CCalificaciones()
{
}

int CCalificaciones::getCalificacion()
{
	if (calificacion < 1 || calificacion > 5) { return 0; }
	return calificacion;
}

int CCalificaciones::getSizeCalificaciones()
{
	return lista->obtenerLongitud();
}

Lista<int>* CCalificaciones::getLista()
{
	return lista;
}

void CCalificaciones::calcularCalificacion()
{
	double suma = 0, num = 0;
	for (int i = 0; i < lista->obtenerLongitud(); i++)
	{
		suma += lista->obtenerPos(i);
	}
	calificacion = round(suma / lista->obtenerLongitud());
}

void CCalificaciones::agregarCaificacion(int newC)
{
	lista->push_back(newC);
}

void CCalificaciones::actualizarLista(Pila<int>* pila)
{
	while (NULL != pila->getHead())
	{
		lista->push_back(pila->pop());
	}
	calcularCalificacion();
}
