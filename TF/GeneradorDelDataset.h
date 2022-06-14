#pragma once
#include "libs.h"
#include "CConductor.h"
#include "Cpasajero.h"

class DataGenerator
{
private:
	ofstream file;
	vector<string> names;
public:
	DataGenerator()
	{
		ifstream fileRead;
		fileRead.open("nombres.txt", ios::out);
		string line;
		while (getline(fileRead, line))
		{
			names.push_back(line);
		}
		fileRead.close();
	}
	~DataGenerator() {}
	void generateData()
	{
		int numeroPasajeros = rand() % 50 + 50;
		int numeroConductores = rand() % 50 + 50;
		generate(numeroPasajeros, numeroConductores);
	}
	void generateData(int numero)
	{
		generate(numero, numero);
	}
	void generateData(int numeroPasajeros, int numeroConductores)
	{
		generate(numeroPasajeros, numeroConductores);
	}
	void generate(int numP, int numC)
	{
		//Formato de impresion de datos
		//1era linea es la cantidad de datos
		//las siguientes 4 lineas son datos del pasajero
		//  primera linea es nombre
		//  segunda linea es edad
		//	cuarta linea es monto q tiene en su cuenta
		file.open("pasajeros.txt", ios::out);
		file << numP << endl;
		for (int i = 0; i < numP; i++)
		{
			file << names[rand() % names.size()] << endl;
			file << randomNumber(15, 90) << endl;
			//file << generateDNI(i) << endl;
			file << randomNumber(10, 1000) << endl;
		}
		//generador para los pasajeros
		file.close();
		
		file.open("conductores.txt", ios::out);
		//generador para los conductores
		file.close();
	}
	string generateName()
	{
		string name;
		int length = rand() % 10 + 3;
		name += char(rand() % 26 + 'A');
		for (int i = 0; i < length; i++)
		{
			name += (char)(rand() % 26 + 'a');
		}
		return name;
	}
	int randomNumber(int min, int max)
	{
		return rand() % (max - min + 1) + min;
	}
	long long generateDNI(int foo)
	{
		long long dni;
		dni = rand() % 999999999 + 100000000;
		return dni;
	}
};