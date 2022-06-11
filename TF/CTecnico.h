#pragma once
#include "libs.h"
#include "CPersona.h"

template<class T>
class CTecnico : public CPersona
{
private:
	int password;

public:
	CTecnico(string n, int a, long long d, double m) :CPersona(n, a, d, m)
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
		auto func = [](CTecnico* a) {
			cout << "Nombre: " << a->getName() << endl;
			cout << "Edad: " << a->getAge() << endl;
			cout << "DNI: " << a->getDNI() << endl;
			cout << "Monto: " << a->getTarjeta()->getMonto() << endl;
			cout << "Password: " << a->getPassword() << endl;
		};
		func(this);
	}
};