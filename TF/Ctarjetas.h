#pragma once
#include "libs.h"

class CTarjetas
{
public:
	CTarjetas();
	CTarjetas(double);
	~CTarjetas();

	//Metodos
	double getMonto();
	void setMonto(double);
	void agregarDinero(double);
	void sacarDinero(double);
	bool seRealizoUltimaTransaccion();

private:
	// rUT = realizo ultima transaccion
	bool rUT;
	double monto;
};

CTarjetas::CTarjetas()
{
	monto = 0;
	rUT = false;
}

CTarjetas::CTarjetas(double m)
{
	monto = m;
	rUT = false;
}

CTarjetas::~CTarjetas()
{
}

double CTarjetas::getMonto()
{
	return monto;
}

void CTarjetas::setMonto(double m)
{
	monto = m;
}

void CTarjetas::agregarDinero(double nMonto)
{
	monto += nMonto;
	rUT = true;
}

void CTarjetas::sacarDinero(double nMonto)
{
	if (nMonto > monto) {
		rUT = false;
	}
	else {
		rUT = true;
		monto -= nMonto;
	}
}

bool CTarjetas::seRealizoUltimaTransaccion()
{
	return rUT;
}
