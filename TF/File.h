#pragma once
#include "libs.h"
#include "CPasajero.h"
#include "CConductor.h"
#include "CViaje.h"

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text1;
	string text2;
	string text3;
	string text4;
	string text5;

	vector<CPasajero*> pasajeros;
	vector<CConductor*> conductores;
	vector<CViaje*>viajes;

	int numPasajeros;
	int numConductores;
	int numViajes;
	int numCalificaciones;
	vector<int> auxnumCalificaciones;

public:
	File() {}
	~File() {}

	void readData() 
	{
		string name;
		int age;
		long long dni;
		double monto;
		fileRead.open("pasajeros.txt", ios::out);

		if (fileRead.fail()) 
		{
			fileRead.close();

			fileWrite.open("pasajeros.txt", ios::out);
			fileWrite << "0";
			fileWrite.close();

			fileRead.open("pasajeros.txt", ios::in);
		}

		getline(fileRead, text1);
		numPasajeros = atoi(text1.c_str());

		for (int i = 0; i < numPasajeros; i++)
		{
			getline(fileRead, text1);
			name = text1;
			getline(fileRead, text2);
			age = stoi(text2);
			getline(fileRead, text3);
			dni = _atoi64(text3.c_str());
			getline(fileRead, text4);
			monto = atof(text4.c_str());
			pasajeros.push_back(new CPasajero(name, age, dni, monto));
		}
		fileRead.close();
		//////////////////////////////////////////////////////////////////////////
		fileRead.open("conductores.txt", ios::out);

		if (fileRead.fail()) 
		{
			fileRead.close();

			fileWrite.open("conductores.txt", ios::out);
			fileWrite << "0";
			fileWrite.close();

			fileRead.open("conductores.txt", ios::in);
		}

		getline(fileRead, text1);
		numConductores = atoi(text1.c_str());

		for (int i = 0; i < numConductores; i++)
		{
			getline(fileRead, text1);
			getline(fileRead, text2);
			getline(fileRead, text3);
			getline(fileRead, text4);
			conductores.push_back(new CConductor(text1.c_str(), atoi(text2.c_str()),
				_atoi64(text3.c_str()), atof(text4.c_str()), nullptr));
		}
		fileRead.close();
		//////////////////////////////////////////////////////////////////////////////
		fileRead.open("viajes.txt", ios::out);

		if (fileRead.fail())
		{
			fileRead.close();

			fileWrite.open("viajes.txt", ios::out);
			fileWrite << "0";
			fileWrite.close();

			fileRead.open("viajes.txt", ios::in);
		}

		getline(fileRead, text1);
		numViajes = atoi(text1.c_str());

		double dist, cost;
		long long auxD1, auxD2;
		CPasajero* auxP;
		CConductor* auxC;

		for (int i = 0; i < numViajes; i++)
		{
			getline(fileRead, text1);
			dist = atof(text1.c_str());
			getline(fileRead, text2);
			cost = atof(text2.c_str());
			getline(fileRead, text3);
			auxD1 = _atoi64(text3.c_str());
			getline(fileRead, text4);
			auxD2 = _atoi64(text4.c_str());

			for (int i = 0; i < pasajeros.size(); i++)
			{
				if (pasajeros[i]->getDNI() == auxD1) auxP = pasajeros[i];
			}
			for (int i = 0; i < conductores.size(); i++)
			{
				if (conductores[i]->getDNI() == auxD2) auxC = conductores[i];
			}

			viajes.push_back(new CViaje(dist, cost, auxP, auxC));
		}
		fileRead.close();
		//////////////////////////////////////////////////////////////////////////////
		fileRead.open("calificaciones.txt", ios::out);

		if (fileRead.fail())
		{
			fileRead.close();

			fileWrite.open("calificaciones.txt", ios::out);
			fileWrite << "0";
			fileWrite.close();

			fileRead.open("calificaciones.txt", ios::in);
		}

		getline(fileRead, text1);
		numCalificaciones = atoi(text1.c_str());

		Pila<int>* auxPila = NULL;

		for (int i = 0; i < numCalificaciones; i++)
		{
			getline(fileRead, text1);
			auxD1 = atof(text1.c_str());
			getline(fileRead, text1);
			auxnumCalificaciones.push_back(atof(text1.c_str()));
			for (int j = 0; j < auxnumCalificaciones[i]; j++)
			{
				getline(fileRead, text1);
				auxPila->push(atof(text1.c_str()));
			}

			for (int j = 0; j < conductores.size(); j++)
			{
				if (conductores[j]->getDNI() == auxD1) 
				{
					conductores[j]->actualizarCalificacion(auxPila);
					auxPila = NULL;
				}
			}
		}
		fileRead.close();
	}

	void agregarPasajero(CPasajero* nP)
	{

		fileWrite.open("pasajeros.txt", ios::out);

		fileWrite << numPasajeros + 1;

		for (int i = 0; i < pasajeros.size(); i++)
		{
			fileWrite << endl << pasajeros.at(i)->getName().c_str();
			fileWrite << endl << pasajeros.at(i)->getAge();
			fileWrite << endl << pasajeros.at(i)->getDNI();
			fileWrite << endl << pasajeros.at(i)->getMonto();
		}
		numPasajeros++;

		fileWrite << endl << nP->getName().c_str();
		fileWrite << endl << nP->getAge();
		fileWrite << endl << nP->getDNI();
		fileWrite << endl << nP->getMonto();

		pasajeros.push_back(nP);

		fileWrite.close();
	}

	void agregarConductores(CConductor* nC)
	{

		fileWrite.open("conductores.txt", ios::out);

		fileWrite << numConductores + 1;

		for (int i = 0; i < numConductores; i++)
		{
			fileWrite << endl << conductores.at(i)->getName();
			fileWrite << endl << conductores.at(i)->getAge();
			fileWrite << endl << conductores.at(i)->getDNI();
			fileWrite << endl << conductores.at(i)->getMonto();
		}
		numConductores++;

		fileWrite << endl << nC->getName();
		fileWrite << endl << nC->getAge();
		fileWrite << endl << nC->getDNI();
		fileWrite << endl << nC->getMonto();

		conductores.push_back(nC);

		fileWrite.close();
	}

	void agregarViaje(CViaje* nV) {

		fileWrite.open("viajes.txt", ios::out);

		fileWrite << numViajes + 1;

		for (int i = 0; i < viajes.size(); i++)
		{
			fileWrite << endl << viajes.at(i)->getDistancia();
			fileWrite << endl << viajes.at(i)->getCosto();
			fileWrite << endl << viajes.at(i)->getPasajero()->getDNI();
			fileWrite << endl << viajes.at(i)->getConductor()->getDNI();
		}
		numViajes++;

		fileWrite << endl << nV->getDistancia();
		fileWrite << endl << nV->getCosto();
		fileWrite << endl << nV->getPasajero()->getDNI();
		fileWrite << endl << nV->getConductor()->getDNI();

		viajes.push_back(nV);

		fileWrite.close();
	}

	void actualizarCalificaciones()
	{
		numCalificaciones = 0;
		for each (CConductor * conduc in conductores)
		{
			if (conduc->calculateCalificacion() != 0)numCalificaciones++;
		}
		int auxN = 0;
		fileWrite.open("calificaciones.txt", ios::out);
		fileWrite << numCalificaciones;
		for each (CConductor * var in conductores)
		{
			if (var->calculateCalificacion() != NULL) 
			{
				fileWrite << endl << var->getDNI();
				fileWrite << endl << var->getSizeCalificacion();
				Lista<int>* aux = var->getCalificaciones();
				for (int i = 0; i < aux->obtenerLongitud(); i++)
				{
					fileWrite << endl << aux->obtenerPos(i);
				}
			}
			auxN++;
		}
		fileWrite.close();
	}

	void actualizarDatos(vector<CPasajero*>vP, vector<CConductor*>vC)
	{
		pasajeros = vP;
		conductores = vC;

		fileWrite.open("pasajeros.txt", ios::out);
		fileWrite << numPasajeros;
		for (int i = 0; i < pasajeros.size(); i++)
		{
			fileWrite << endl << pasajeros.at(i)->getName().c_str();
			fileWrite << endl << pasajeros.at(i)->getAge();
			fileWrite << endl << pasajeros.at(i)->getDNI();
			fileWrite << endl << pasajeros.at(i)->getMonto();
		}
		fileWrite.close();

		fileWrite.open("conductores.txt", ios::out);
		fileWrite << numConductores;
		for (int i = 0; i < numConductores; i++)
		{
			fileWrite << endl << conductores.at(i)->getName();
			fileWrite << endl << conductores.at(i)->getAge();
			fileWrite << endl << conductores.at(i)->getDNI();
			fileWrite << endl << conductores.at(i)->getMonto();
		}
		fileWrite.close();
	}

	vector<CPasajero*> getPasajero() 
	{
		return pasajeros;
	}
	
	vector<CConductor*> getConductores() 
	{
		return conductores;
	}
	
	vector<CViaje*> getViajes() 
	{ 
		return viajes; 
	}

};