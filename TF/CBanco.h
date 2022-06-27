#pragma once
#include "libs.h"
#include "CController.h"

void miniMenu();
void printData(vector<CPersona*>);
template<class T>
void quicksort(vector<T>&, int, int, function<bool(T, T)>);
template <class T>
void heapify(vector<T>&, int, int, function<bool(T, T)>);
template <class T>
void heapSort(vector<T>&, int, function<bool(T, T)>);
template<class T>
void merge(vector<T>&, int, int, int, function<bool(T, T)>);
template<class T>
void mergeSort(vector<T>&, int, int, function<bool(T, T)>);

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
	cout << "\n\tIngrese 0 si desea regresar al menu";
	if (controller->getPasajeros().size() != 0) {
		cout << "\n\nIngrese su DNI para iniciar: ";
		cin >> auxDNI;
		while (auxDNI < 9999999 || auxDNI > 100000000)
		{
			if (auxDNI == 0)
			{
				cout << "\n\nEsta regresando al menu principal\nPulse cualquier tecla para salir.";
				_getch();
				return;
			}
			cout << "Ingrese un DNI valido o 0 para regresar al Menu: ";
			cin >> auxDNI;
		}
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
			cout << "\nRecuerde que el monto que ingrese no puede superar los S/1000 por transaccion";
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
	_getch();
}

void CBanco::imprimirDatosOrdenando(CController*& controller)
{
	int opcion;
	bool sigue = true;

	auto mayorA = [](CPersona* p1, CPersona* p2)
	{
		return p1->getAge() < p2->getAge();
	};
	auto menorA = [](CPersona* p1, CPersona* p2) -> bool
	{
		return p1->getAge() > p2->getAge();
	};
	auto mayorD = [](CPersona* p1, CPersona* p2) -> bool
	{
		return p1->getTarjeta()->getMonto() < p2->getTarjeta()->getMonto();
	};
	auto menorD = [](CPersona* p1, CPersona* p2) -> bool
	{
		return p1->getTarjeta()->getMonto() > p2->getTarjeta()->getMonto();
	};
	auto nameSort = [](CPersona* m1, CPersona* m2)
	{
		return m1->getName() <= m2->getName();
	};

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
				quicksort<CPersona*>(personas, 0, personas.size() - 1, mayorA);
				break;
			case 3:
				quicksort<CPersona*>(personas, 0, personas.size() - 1, menorA);
				break;
			case 4:
				heapSort<CPersona*>(personas, personas.size(), mayorD);
				break;
			case 5:
				heapSort<CPersona*>(personas, personas.size(), menorD);
				break;
			case 6:
				mergeSort<CPersona*>(personas, 0, personas.size() - 1, nameSort);
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
	cout << "\n[2] Ordenar las personas de menor a mayor por edad";
	cout << "\n[3] Ordenar las personas de mayor a menor por edad";
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

template<class T>
void quicksort(vector<T>& people, int inicio, int tamano, function<bool(T, T)> func) {
	int i = inicio;
	int j = tamano;
	T pivot = people[(i + j) / 2];
	do
	{
		while (func(people[i], pivot) && (j <= tamano))
		{
			i++;
		}
		while (func(pivot, people[j]) && (j > inicio))
		{
			j--;
		}
		if (i <= j) {
			swap(people[i], people[j]);
			i++; j--;
		}
	} while (i <= j);
	if (inicio < j) {
		quicksort(people, inicio, j, func);
	}
	if (i < tamano) {
		quicksort(people, i, tamano, func);
	}
}

template <class T>
void heapify(vector<T>& arr, int n, int i, function<bool(T, T)> func)
{

	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && func(arr[l], arr[largest]))
		largest = l;
	if (r < n && func(arr[r], arr[largest]))
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest, func);
	}
}

template <class T>
void heapSort(vector<T>& arr, int n, function<bool(T, T)> func)
{

	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heapify(arr, arr.size(), i, func);
	for (int i = arr.size() - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, func);
	}
}

template<class T>
void merge(vector<T>& people, int inicio, int mitad, int final, function<bool(T, T)> func) {
	int i, j, k;
	int elementosIzq = mitad - inicio + 1;
	int elementosDer = final - mitad;

	vector<T>izquierda(elementosIzq);
	vector<T>derecha(elementosDer);

	for (int i = 0; i < elementosIzq; i++) {
		izquierda[i] = people[inicio + i];
	}
	for (int j = 0; j < elementosDer; j++) {
		derecha[j] = people[mitad + 1 + j];
	}

	i = 0;
	j = 0;
	k = inicio;

	while (i < elementosIzq && j < elementosDer) {
		if (func(izquierda[i], derecha[j])) {
			people[k] = izquierda[i];
			i++;
		}
		else {
			people[k] = derecha[j];
			j++;
		}
		k++;
	}

	while (j < elementosDer) {
		people[k] = derecha[j];
		j++;
		k++;
	}

	while (i < elementosIzq) {
		people[k] = izquierda[i];
		i++;
		k++;
	}

}

template<class T>
void mergeSort(vector<T>& arreglo, int inicio, int final, function<bool(T, T)> func) {
	if (inicio < final) {
		int mitad = inicio + (final - inicio) / 2;
		mergeSort(arreglo, inicio, mitad, func);
		mergeSort(arreglo, mitad + 1, final, func);
		merge(arreglo, inicio, mitad, final, func);
	}
}