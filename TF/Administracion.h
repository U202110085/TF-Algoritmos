#pragma once
#include "CAdminsitrador.h"
#include "CTecnico.h"
#include "File.h"

template<class T>
class Adminsitracion
{
public:
	Adminsitracion()
	{
		adminsitrador = NULL;
		tecnicos = new Lista<CTecnico<void>*>();
	}
	
	Adminsitracion(CAdministrador<void>* a)
	{
		adminsitrador = new CAdministrador<void>(a);
		tecnicos = new Lista<CTecnico<void>*>();
	}

	Adminsitracion(Lista<CTecnico<void>*>* a)
	{
		adminsitrador = NULL;
		tecnicos = new Lista<CTecnico<void>*>(a->obtenerNodo(), a->obtenerLongitud());
	}	

	Adminsitracion(CAdministrador<void>* a, Lista<CTecnico<void>*>* b)
	{
		adminsitrador = new CAdministrador<void>(a);
		tecnicos = new Lista<CTecnico<void>*>(b->obtenerNodo(), b->obtenerLongitud());
	}

	~Adminsitracion()
	{
	}

	//void actualizarRegistro(File& file)
	/*{
		
	}*/

	void addAdminstrador(CAdministrador<void>* a)
	{
		if (adminsitrador == NULL)
			adminsitrador = new CAdministrador<void>(a);
	}
	
	void addTecnico(CTecnico<void>* a)
	{
		tecnicos->push_back(a);
	}
	
	void mostrarAdministrador()
	{
		if (adminsitrador != NULL)
			adminsitrador->mostrar();
	}

	void mostrarTecnicos()
	{
		for (int i = 0; i < tecnicos->obtenerLongitud(); i++)
		{
			tecnicos->obtenerPos(i)->mostrar();
		}
	}

	bool esAdmin()
	{
		// aqui se hace verificacion en caso sea o no un admin
		// en caso lo sea entonces tendra la possiblidad de ingresar a
		// la clase manipulacion
		return true;
	}

private:
	CAdministrador<void>* adminsitrador;
	Lista<CTecnico<void>*>* tecnicos;
};
