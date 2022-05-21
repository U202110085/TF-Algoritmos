#pragma once
#include "libs.h"

class CCalificaciones
{
public:
	//Constructores y destructores
	CCalificaciones(Nodo<int>*);
	~CCalificaciones();

	//Metodos
	int getCalificacion();
	int getSizeCalificaciones();
	Nodo<int>* getLista();
	void calcularCalificacion();
	void agregarCaificacion(int);
	void actualizarLista(Nodo<int>*);
private:
	Nodo<int>* lista;
	int calificacion;
};

CCalificaciones::CCalificaciones(Nodo<int>* pila)
{
	int aux;
	lista = new Nodo<int>(NULL);
	while (pila != NULL)
	{
		sacarPila<int>(pila, aux);
		agregarLista<int>(lista, aux);
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
	Nodo<int>* aux = lista;
	int num = 0;
	while (aux != NULL)
	{
		num++;
		aux = aux->siguiente;
	}
	return num;
}

Nodo<int>* CCalificaciones::getLista()
{
	return lista;
}

void CCalificaciones::calcularCalificacion()
{
	Nodo<int>* aux = lista;
	double suma = 0, num = 0;
	while (aux != NULL)
	{
		if (aux->valor != 0) {
			num++;
			suma += aux->valor;
		}
		aux = aux->siguiente;
	}
	calificacion = round(suma / num);
}

void CCalificaciones::agregarCaificacion(int newC)
{
	if (lista->valor == 0) {
		lista->valor = newC;
	}
	else agregarLista(lista, newC);
}

void CCalificaciones::actualizarLista(Nodo<int>* pila)
{
	int aux;
	while (pila != NULL)
	{
		sacarPila<int>(pila, aux);
		agregarLista<int>(lista, aux);
	}
	lista = lista->siguiente;
	calcularCalificacion();
}
