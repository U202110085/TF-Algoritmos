#pragma once
#include "libs.h"
#include "CController.h"
#include "Administracion.h"

template<class T>
class CManipulacion
{
public:
	CManipulacion(){}
	~CManipulacion(){}
	void menu(Adminsitracion<void> administracion, File& file, Hash& hashtable, CController& controller)
	{
		int opcion;
		system("CLS");
		cout << "..::MENU DE ADMINSITRACION::..";
		cout << "\nAqui podra eliminar cuentas o cambiar el precio del viaje\n";
		cout << "1. Agregar Administrador" << endl;
		cout << "2. Eliminar Pasajero o Conductor" << endl;
		cout << "3. Cambiar precio del viaje" << endl;
		cout << "4. Borrar base de datos" << endl;
		cout << "5. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		system("CLS");
		switch (opcion)
		{
		case 1:
			agregarAdmin(administracion, file, hashtable);
			break;
		case 2:
			eliminarUsuario(administracion, file, hashtable, controller);
			break;
		case 3:
			cambiarPrecio(administracion, file, hashtable, controller);
			break;
		case 4:
			borrarArchivos(administracion, hashtable, controller);
			break;
		case 5:
			return;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
		menu(administracion, file, hashtable, controller);
	}
	bool esAdministrador(Adminsitracion<void> administracion, File& file, Hash& hashtable)
	{
		return administracion.esAdmin(file, hashtable);
	}
	void agregarAdmin(Adminsitracion<void> administracion, File& file, Hash& hashtable)
	{
		administracion.add(file, hashtable);
	}
	void eliminarUsuario(Adminsitracion<void> administracion, File& file, Hash& hashtable, CController& controller)
	{
		int n;
		if (administracion.esAdmin(file, hashtable))
		{
			cout << "\n\nA continuacion se imprimira la lista de pasajeros y conductores";
			cout << "\nPulse culaquier tecla para imprimir\n"; _getch();
			for (int i = 0; i < file.getPasajero().size(); i++)
			{
				cout << "[" << i << "] " << file.getPasajero()[i]->getName() << endl;
			}
			for (int i = file.getPasajero().size();
				i < file.getConductores().size() + file.getPasajero().size();
				i++)
			{
				cout << "[" << i << "] " << file.getConductores()[i]->getName() << endl;
			}
			cout << "\nIngrese el indice del Usuario que desea eliminar: "; cin >> n;
			system("CLS");
			//confirmacion de password
			
			cout<<"\nAntes de continuar ingrese su contrasena: ";
			if (!administracion.verifyHashPassword(hashtable))
			{
				cout << "La clave no existe en nuestra base de datos\n";
				cout << "Sera redireccionado al menu\n";
				cout << "Pule cualquier tecla para continuar\n"; _getch(); return;
			}
			
			//continuacion
			if (n < file.getPasajero().size())
			{
				file.eraseP(n);
				controller.eraseP(n);
			}
			else if (n < file.getPasajero().size() + file.getConductores().size())
			{
				file.eraseC(n - file.getPasajero().size());
				controller.eraseC(n - controller.getPasajeros().size());
			}
			else cout << "No existe usuario en ese indice";
			cout << "\nPulse cualquier tecla para continuar"; _getch();
		}
		else
		{
			cout << "\nNo tiene permisos para borrar usuarios o no existe un adminsitrador" << endl;
			cout << "Pulse cualquier tecla para continuar";
			_getch();
		}
	}
	void cambiarPrecio(Adminsitracion<void> administracion, File& file, Hash& hashtable, CController& controller)
	{
		double n;
		if (administracion.esAdmin(file, hashtable))
		{
			cout << "\nIngrese el nuevo precio: "; cin >> n;
			
			//confirmacion de password

			cout << "\nAntes de continuar ingrese su contrasena: ";
			if (!administracion.verifyHashPassword(hashtable))
			{
				cout << "La clave no existe en nuestra base de datos\n";
				cout << "Sera redireccionado al menu\n";
				cout << "Pule cualquier tecla para continuar\n"; _getch();
				return;
			}

			//continuacion
			controller.setprecioV(n);
			cout << "\nEl precio se registro exitosamente";
			cout << "\nPule cualquier tecla para continuar\n"; _getch();
		}
		else
		{
			cout << "\nNo tiene permisos para cambiar el precio o no existe un adminsitrador" << endl;
			cout << "Pulse cualquier tecla para continuar";
			_getch();
		}
	}
	void borrarArchivos(Adminsitracion<void> administracion, Hash& hashtable, CController& controller)
	{
		if (administracion.mainAdmin())
		{

			//confirmacion de password

			cout << "\nAntes de continuar ingrese su contrasena: ";
			if (!administracion.verifyHashPassword(hashtable))
			{
				cout << "La clave no existe en nuestra base de datos\n";
				cout << "Sera redireccionado al menu\n";
				cout << "Pulse cualquier tecla para continuar\n"; _getch();
				return;
			}

			//continuacion
			cout<<"\nSeguro que desea borrar todos los datos del sistema?\n";
			cout << "1: Si\n2: Cancelar\nOpcion: ";
			int n; cin >> n;
			if (n == 1)
			{
				ofstream fileWrite;
				fileWrite.open("pasajeros.txt", ios::out);
				fileWrite << "0";
				fileWrite.close();
				fileWrite.open("conductores.txt", ios::out);
				fileWrite << "0";
				fileWrite.close();
				fileWrite.open("viajes.txt", ios::out);
				fileWrite << "0";
				fileWrite.close();
				fileWrite.open("calificaciones.txt", ios::out);
				fileWrite << "0";
				fileWrite.close();
			}
			else
			{
				cout << "\nSe cancelo la operacion";
				cout << "\nPule cualquier tecla para continuar\n"; _getch();
			}
		}
		else
		{
			cout << "\nNo tiene permisos o no existe un adminsitrador\n" << endl;
			cout << "Pulse cualquier tecla para continuar";
			_getch();
		}
	}
};