#pragma once
#include "libs.h"
#include "CPersona.h"

template<class T>
class CAdministrador : public CPersona
{
private:
	int password;

public:
	CAdministrador(CAdministrador<void>* a) : CPersona(a->getName(), a->getAge(), a->getDNI(), a->getTarjeta()->getMonto())
	{
		password = a->getPassword();
	}
	CAdministrador(string n, int a, long long d, double m) :CPersona(n, a, d , m)
	{
		password = 0;
	}
	void setPassword(int p)
	{
		password = p;
	}
	int getPassword()
	{
		return password;
	}
	void mostrar()
	{
		auto func = [](CAdministrador* a) {
			cout << "Nombre: " << a->getName() << endl;
			cout << "Edad: " << a->getAge() << endl;
			cout << "DNI: " << a->getDNI() << endl;
			cout << "Monto: " << a->getTarjeta()->getMonto() << endl;
			cout << "Password: " << a->getPassword() << endl;
		};
		func(this);
	}
};