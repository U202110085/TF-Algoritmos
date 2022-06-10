#pragma once
#include "libs.h"
#include "CController.h"

void miniMenu();
void printData(vector<CPersona*>);
void bubbleSort(vector<CPersona*>&, bool);
void insertionSort(vector<CPersona*>&, bool);
void selectionSort(vector<CPersona*>&);

class CBanco
{
public:
	CBanco();
	~CBanco();

	//Metodos
	void agregarDineroTarjeta(File&, CController*&);
	void imprimirDatosOrdenando(CController*&);

private:
};

CBanco::CBanco()
{
}

CBanco::~CBanco()
{
}

void CBanco::agregarDineroTarjeta(File& file, CController*& controller)
{
	int numP;
	double montoIngresar;
	long long auxDNI;
	bool existe = false;
	cout << "\n\tSe encuentra en la seccion para agregar dinero";
	if (controller->getPasajeros().size() != 0) {
		cout << "\n\nIngrese su DNI para iniciar: ";
		auxDNI = verifyData(100000000, 9999999);
		for (int i = 0; i < controller->getPasajeros().size(); i++)
		{
			if (controller->getPasajeros()[i]->getDNI() == auxDNI)
			{
				numP = i;
				existe = true;
			}
		}
		if (existe) {
			cout << "\nHola " << controller->getPasajeros()[numP]->getName();
			cout << "\nCual sera el monto que ingresara en su tarjeta?";
			cout << "\nRecuerde que solo puede ingresar S/1000 por transaccion";
			cout << "\nIngrese el monto: ";
			montoIngresar = verifyData(1000, 0);
			controller->getPasajeros()[numP]->getTarjeta()->agregarDinero(montoIngresar);
			file.actualizarDatos(controller->getPasajeros(), controller->getConductores());
			cout << "\nSe realizo correctamente la transaccion (^_^)";
		}
		else {
			cout << "\n\n\tLo sentimos, su DNI aun no existe en nuestra base de datos";
		}
	}
	else cout << "\nAun no hay pasajeros registradas\nen nuestra base de datos";
}

void CBanco::imprimirDatosOrdenando(CController*& controller)
{
	int opcion;
	bool sigue = true;

	if (controller->getPasajeros().size() != 0 && controller->getConductores().size() != 0) {
		vector<CPersona*> personas;
		for each (CPasajero * var in controller->getPasajeros()) { personas.push_back(var); }
		for each (CConductor * var in controller->getConductores()) { personas.push_back(var); }
		while (sigue)
		{
			do
			{
				system("CLS");
				miniMenu();
				cin >> opcion;
			} while (opcion < 1 || opcion > 8);
			system("CLS");
			switch (opcion)
			{
			case 1:
				printData(personas);
				break;
			case 2:
				bubbleSort(personas, true);
				break;
			case 3:
				bubbleSort(personas, false);
				break;
			case 4:
				insertionSort(personas, true);
				break;
			case 5:
				insertionSort(personas, false);
				break;
			case 6:
				selectionSort(personas);
				break;
			case 7:
				sigue = false;
				break;
			}
			if (opcion != 1 && opcion != 7)cout << "\n\n\tDatos ordenados con exito";
			_getch();
		}
	}
	else {
		cout << "Para hacer uso de esta funcion deben existir pasajeros y conductores";
	}
}

void miniMenu() {
	cout << "\n\t:::::BANCO:::::";
	cout << "\n\nAqui se encuentran todos aquellos regisstrados";
	cout << "\nSe podra imprimir esa informacion y tambien ordenar";
	cout << "\nde distintas formas";
	cout << "\n\n[1] Imprimir datos";
	cout << "\n[2] Ordenar las personas de mayor a menor por edad";
	cout << "\n[3] Ordenar las personas de menor a mayor por edad";
	cout << "\n[4] Ordenar las personas de mas rico o menos rico";
	cout << "\n[5] Ordenar las personas de menos rico o mas rico";
	cout << "\n[6] Ordenar las personas alfabeticamente";
	cout << "\n[7] Salir";
	cout << "\n\n\tIngrese su opcion: ";
}

void printData(vector<CPersona*> personas) {
	cout << "DATOS IMPRESOS\n";
	for each (CPersona * var in personas)
	{
		cout << "\nNombre: " << var->getName() << endl;
		cout << "Edad: " << var->getAge() << endl;
		cout << "DNI: " << var->getDNI() << endl;
		cout << "Monto En Tarjeta: " << var->getTarjeta()->getMonto() << endl;
	}
}

void bubbleSort(vector<CPersona*>& people, bool ascending) {
	CPersona* aux;
	if (ascending) {
		for (int i = 0; i < people.size(); i++) {
			for (int j = 0; j < people.size() - 1; j++) {
				if (people[j]->getAge() > people[j + 1]->getAge()) {
					aux = people[j];
					people[j] = people[j + 1];
					people[j + 1] = aux;
				}
			}
		}
	}
	else {
		for (int i = 0; i < people.size(); i++) {
			for (int j = 0; j < people.size() - 1; j++) {
				if (people[j]->getAge() < people[j + 1]->getAge()) {
					aux = people[j];
					people[j] = people[j + 1];
					people[j + 1] = aux;
				}
			}
		}
	}
}

void insertionSort(vector<CPersona*>& personas, bool ascending) {
	int pos;
	CPersona* aux;
	if (ascending) {
		for (int i = 0; i < personas.size(); i++) {
			pos = i;
			aux = personas[i];

			//evaluamos si es mayor a la primera posición, numero de la inzquierda es mayor al numero actual
			while ((pos > 0) && (personas[pos - 1]->getTarjeta()->getMonto() < aux->getTarjeta()->getMonto())) {
				personas[pos] = personas[pos - 1];
				pos--;
			}
			personas[pos] = aux;
		}
	}
	else {
		for (int i = 0; i < personas.size(); i++) {
			pos = i;
			aux = personas[i];

			//evaluamos si es mayor a la primera posición, numero de la inzquierda es mayor al numero actual
			while ((pos > 0) && (personas[pos - 1]->getTarjeta()->getMonto() > aux->getTarjeta()->getMonto())) {
				personas[pos] = personas[pos - 1];
				pos--;
			}
			personas[pos] = aux;
		}
	}
}

void selectionSort(vector<CPersona*>& personas) {
	int min;
	CPersona* aux;
	for (int i = 0; i < personas.size() - 1; i++) {
		//suponemos que le numero menor esta en la primera posición
		min = i;
		for (int j = i + 1; j < personas.size(); j++) {
			//buscando cual es el menor numero
			if (personas[j]->getName() < personas[min]->getName()) {
				min = j;
			}
		}
		aux = personas[i];
		personas[i] = personas[min];
		personas[min] = aux;
	}
}