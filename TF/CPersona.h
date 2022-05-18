#pragma once
#include "libs.h"
#include "CTarjetas.h"

class CPersona
{
public:
	//Constructores y destructores
	CPersona();
	CPersona(string, int, long long, double);
	~CPersona();

	//Set y get
	void setName(string);
	void setAge(int);
	void setDNI(long long);
	int getAge();
	long long getDNI();
	string getName();
	CTarjetas* getTarjeta();

protected:
	int age;
	long long dni;
	string name;
	CTarjetas* tarjeta;
};

CPersona::CPersona()
{
}

CPersona::CPersona(string n, int a, long long d, double m)
{
	name = n;
	age = a;
	dni = d;
	tarjeta = new CTarjetas(m);
}

CPersona::~CPersona()
{
}

void CPersona::setName(string n) 
{ 
	name = n;
}

void CPersona::setAge(int a) 
{ 
	age = a; 
}

void CPersona::setDNI(long long d)
{ 
	dni = d; 
}

string CPersona::getName() 
{ 
	return name; 
};

int CPersona::getAge() 
{ 
	return age;
};

long long CPersona::getDNI()
{ 
	return dni;
}

CTarjetas* CPersona::getTarjeta()
{
	return tarjeta;
}