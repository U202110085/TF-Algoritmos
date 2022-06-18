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
	void menu()
	{
		int n;
		cout << "Antes de iniciar el programa, desea genear un dataset?" << endl;
		cout << "1. Conservar datos existentes" << endl;
		cout << "2. Generar uno con numeros aleatorios" << endl;
		cout << "3. Generar uno con cantidades iguales" << endl;
		cout << "4. Generar uno con cantidades distintas" << endl;
		cout << "Opcion: "; cin >> n;
		if (n == 2)
		{
			generateData();
		}
		else if (n == 3)
		{
			cout << "Cuantos pasajeros y conductores desea generar?" << endl;
			cout << "Cantidad: "; cin >> n;
			generateData(n);
		}
		else if (n == 4)
		{
			int p, c;
			cout << "Cuantos pasajeros desea generar?" << endl;
			cout << "Cantidad: "; cin >> p;
			cout << "Cuantos conductores desea generar?" << endl;
			cout << "Cantidad: "; cin >> c;
			generateData(p, c);
		}
	}
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
		file.open("pasajeros.txt", ios::out);
		file << numP << endl;
		for (int i = 0; i < numP; i++)
		{
			file << names[rand() % names.size()] << endl;
			file << randomNumber(15, 90) << endl;
			file << 100000000 + i << endl;
			file << randomNumber(10, 1000) << endl;
		}
		file.close();
		
		file.open("conductores.txt", ios::out);
		file << numC << endl;
		for (int i = 0; i < numP; i++)
		{
			file << names[rand() % names.size()] << endl;
			file << randomNumber(15, 90) << endl;
			file << 100000000 + i + numP << endl;
			file << randomNumber(10, 1000) << endl;
		}
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