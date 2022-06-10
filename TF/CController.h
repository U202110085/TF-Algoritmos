#pragma once
#include "libs.h"
#include "CPasajero.h"
#include "CConductor.h"
#include "CViaje.h"
#include "File.h"

void menuDG();

template<typename T>
T verifyData(T, T);


class CController
{
public:
	CController();
	CController(vector<CPasajero*>, vector<CConductor*>, vector<CViaje*>);
	~CController();

	//Metodos
	void agregarUsuario(File&);
	void imprimirDatos();
	void realizarViaje(File&);
	void imprimirViajes();
	void calcularDatosGenerales();
	vector<CPasajero*> getPasajeros();
	vector<CConductor*> getConductores();

private:
	vector<CPasajero*>pasajeros;
	vector<CConductor*>conductores;
	vector<CViaje*>viajes;
};

CController::CController()
{
}

CController::CController(vector<CPasajero*> vp, vector<CConductor*> vc, vector<CViaje*> vv)
{
	pasajeros = vp;
	conductores = vc;
	viajes = vv;
}

CController::~CController()
{
}

void CController::agregarUsuario(File& file)
{
	int opcion;
	string a1; int a2; long long a3; double a4;
	cout << "Se encuentra en la seccion para registrarse";
	cout << "\n\n\tDesea registrarse como:\n";
	cout << "[1] Pasajero\n";
	cout << "[2] Conductor\n";
	cout << "Ingrese su opcion: ";
	cin >> opcion;
	std::system("CLS");
	cout << "Ingrese su nombre: ";
	cin.ignore();
	getline(cin, a1);
	cout << "Ingrese su edad: ";
	a2 = verifyData(90, 15);
	bool idExiste;
	do
	{
		idExiste = false;
		cout << "Ingrese su DNI: ";
		a3 = verifyData(100000000, 9999999);
		for each (CPasajero * var in pasajeros)
			if (var->getDNI() == a3)
				idExiste = true;
		for each (CConductor * var in conductores)
			if (var->getDNI() == a3)
				idExiste = true;
	} while (idExiste);
	cout << "\n\nProcesando sus datos...\n\n";
	for (size_t i = 0; i < 30; i++)
	{
		_sleep(50);
		cout << char(219);
	}

	if (opcion == 1)
	{
		pasajeros.push_back(new CPasajero(a1, a2, a3));
		file.agregarPasajero(new CPasajero(a1, a2, a3));
	}
	else
	{
		conductores.push_back(new CConductor(a1, a2, a3));
		file.agregarConductores(new CConductor(a1, a2, a3));
	}

	cout << "\n\nSus datos se registraron con exito...\nPulse cualquier tecla para salir.";
	_getch();
}

void CController::imprimirDatos()
{
	cout << "\n_____Lista de Pasajeros_____";
	cout << "\n\n";
	for_each(pasajeros.begin(), pasajeros.end(), [](CPasajero* n) {n->printData(); cout << endl; });
	cout << "\n\n_____Lista de Conductores_____";
	cout << "\n\n";
	for_each(conductores.begin(), conductores.end(), [](CConductor* n) {n->printData(); cout << endl; });
	_getch();
}

void CController::realizarViaje(File& file)
{
	int numP, numC, confirmacion;
	int distancia;
	long long auxDNI;
	bool existe = false;
	cout << "Se encuentra en la seccion para realizar un viaje";
	if (conductores.size() != 0)
	{
		cout << "\n\nIngrese su DNI para iniciar: ";
		auxDNI = verifyData(100000000, 9999999);
		for (int i = 0; i < pasajeros.size(); i++)
		{
			if (pasajeros[i]->getDNI() == auxDNI)
			{
				numP = i;
				existe = true;
			}
		}
		if (existe)
		{
			cout << "Hola " << pasajeros[numP]->getName();
			cout << "\nCual sera la distancia del recorido de su viaje: ";
			distancia = verifyData(100, 0);
			cout << "Seleccione un conductor:\n";
			for (int i = 0; i < conductores.size(); i++)
			{
				cout << "\n[" << i + 1 << "] Conductor: " << conductores[i]->getName();
				cout << "\nCalificacion: ";
				if (conductores[i]->calculateCalificacion() == 0)cout << "Aun no tiene calificacion";
				else cout << conductores[i]->calculateCalificacion() << endl;
			}
			cout << "\n\nSu opcion: ";
			numC = verifyData<int>(conductores.size(), 1);
			numC--;
			cout << "El monto de su viaje saldra: s/." << double(distancia) * 1.5;
			cout << "\nDesea pedir el taxi? (1 = Si, 2 = No): ";
			confirmacion = verifyData(2, 1);
			if (confirmacion == 1)
			{
				pasajeros[numP]->getTarjeta()->sacarDinero(double(distancia) * 1.5);
				if (pasajeros[numP]->getTarjeta()->seRealizoUltimaTransaccion()) {
					viajes.push_back(new CViaje(distancia, double(distancia) * 1.5,
						pasajeros[numP], conductores[numC]));
					cout << "\n\nSu viaje esta en proceso\n\n";
					for (int i = 0; i < 30; i++)
					{
						_sleep(50);
						cout << char(219);
					}
					cout << "\n\nFinalizo el viaje. Gracias uwu\n";
					file.agregarViaje(new CViaje(distancia, double(distancia) * 1.5,
						pasajeros[numP], conductores[numC]));
					cout << "\nPorfavor califique su viaje del 1 al 5\n(1 siendo malo, 5 siendo muy bueno): ";
					int auxcalificacion = verifyData(5, 1);
					conductores[numC]->addCalificacion(auxcalificacion);
					conductores[numC]->getTarjeta()->agregarDinero(double(distancia) * 1.5);
					file.actualizarDatos(pasajeros, conductores);
					file.actualizarCalificaciones();
				}
				else cout << "\n\nNo cuenta con saldo suficiente en su tarjeta :'(";
			}
		}
		else
		{
			cout << "Lo sentimos, su DNI aun no existe en nuestra base de datos";
			cout << "\nPorfavor dirigase a la pnatalla principal para registrarse uwu";
		}
	}
	else cout << "\nAun no hay conductores";
	_getch();
}

void CController::imprimirViajes() {
	int num;
	bool existe, tipo;
	long long auxDNI;
	cout << "Se encuentra en la seccion de impression de registro de viajes";
	if (viajes.size() != 0) {
		cout << "\n\nIngrese su DNI para iniciar: ";
		do
		{
			cin >> auxDNI;
		} while (auxDNI < 9999999 || auxDNI > 100000000);

		for (int i = 0; i < pasajeros.size(); i++)
		{
			if (pasajeros[i]->getDNI() == auxDNI)
			{
				num = i;
				existe = true;
				tipo = true;
			}
		}
		for (int i = 0; i < conductores.size(); i++)
		{
			if (conductores[i]->getDNI() == auxDNI)
			{
				num = i;
				existe = true;
				tipo = false;
			}
		}
		std::system("CLS");
		if (existe) {
			if (tipo) {
				for each (CViaje * viaje in viajes)
				{
					if (viaje->getPasajero()->getDNI() == pasajeros[num]->getDNI())
					{
						viaje->printViaje();
						cout << "\n\n";
					}
				}
			}
			else {
				for each (CViaje * viaje in viajes)
				{
					if (viaje->getConductor()->getDNI() == conductores[num]->getDNI())
					{
						viaje->printViaje();
						cout << "\n\n";
					}
				}
			}
			cout << "\n\nAqui concluyen los viajes de este usuario";
		}
		else cout << "\nSu DNI no se encuentra en la base de datos :v";
	}
	else cout << "\nAun no se han realizado viajes en este sistema :v";
	_getch();
}

void CController::calcularDatosGenerales()
{
	int opcion;
	bool sigue = true;

	if (pasajeros.size() != 0 && conductores.size() != 0) {
		vector<int>edades;
		vector<double>montoG;
		vector<double>montoR;

		for_each(pasajeros.begin(), pasajeros.end(), [&](CPasajero* n) {edades.push_back(n->getAge()); montoG.push_back(n->getMonto()); });
		for_each(conductores.begin(), conductores.end(), [&](CConductor* n) {edades.push_back(n->getAge()); montoR.push_back(n->getMonto()); });

		while (sigue)
		{
			do
			{
				std::system("CLS");
				menuDG();
				cin >> opcion;
			} while (opcion < 1 || opcion > 8);
			std::system("CLS");
			switch (opcion)
			{
			case 1:
				cout << "La mayor persona tiene " << getMax(edades) << " anios";
				break;
			case 2:
				cout << "La menor persona tiene " << getMin(edades) << " anios";
				break;
			case 3:
				cout << "El pasajero con mas dinero: s/" << getMax(montoG);
				break;
			case 4:
				cout << "El pasajero con menos dinero: s/" << getMin(montoG);
				break;
			case 5:
				cout << "El monto que ha ganado el conductor que mas usa la aplicacion: s/" << getMax(montoR);
				break;
			case 6:
				cout << "El monto que ha ganado el conductor que menos usa la aplicacion: s/" << getMin(montoR);
				break;
			case 7:
				sigue = false;
				break;
			}
			_getch();
		}
	}
	else {
		cout << "Para hacer uso de esta funcion deben existir pasajeros y conductores";
	}

}

vector<CPasajero*> CController::getPasajeros()
{
	return pasajeros;
}

vector<CConductor*> CController::getConductores()
{
	return conductores;
}

void menuDG()
{
	cout << "Se encuentra en la seccion de impresion de datos generales";
	cout << "\n\n[1] La mayor persona registrada en nuestra base de datos";
	cout << "\n[2] La menor persona registrada en nuestra base de datos";
	cout << "\n[3] El monto que ha gastado la persona que mas usa la aplicacion"; //La persona que mas usa nuestra applicacion
	cout << "\n[4] El monto que ha gastado la persona que menos usa la aplicacion";
	cout << "\n[5] El monto que ha ganado el conductor que mas usa la aplicacion";
	cout << "\n[6] El monto que ha ganado el conductor que menos usa la aplicacion";
	cout << "\n[7] Salir";
	cout << "\n\n\tIngrese su opcion: ";
}
