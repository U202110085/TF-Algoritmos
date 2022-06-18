#pragma once
#include "File.h"
#include "CHash.h"

template<class T>
class Adminsitracion
{
public:
	Adminsitracion()
	{
		adminsitrador = NULL;
		tecnicos = new Lista<CTecnico<void>*>();
	}
	
	Adminsitracion(CAdministrador<void>* a)
	{
		adminsitrador = new CAdministrador<void>(a);
		tecnicos = new Lista<CTecnico<void>*>();
	}

	Adminsitracion(Lista<CTecnico<void>*>* a)
	{
		adminsitrador = NULL;
		tecnicos = new Lista<CTecnico<void>*>(a->obtenerNodo(), a->obtenerLongitud());
	}	

	Adminsitracion(CAdministrador<void>* a, Lista<CTecnico<void>*>* b)
	{
		adminsitrador = new CAdministrador<void>(a);
		tecnicos = new Lista<CTecnico<void>*>(b->obtenerNodo(), b->obtenerLongitud());
	}

	~Adminsitracion()
	{
	}

	void actualizarRegistro(File& file)
	{
		file.actualizarAdmin(adminsitrador);
		file.actualizarTecnicos(tecnicos);
	}
	
	void addAdminstrador(CAdministrador<void>* a)
	{
		if (adminsitrador == NULL)
			adminsitrador = new CAdministrador<void>(a);
	}
	
	void addTecnico(CTecnico<void>* a)
	{
		tecnicos->push_back(a);
	}
	
	void mostrarAdministrador()
	{
		if (adminsitrador != NULL)
			adminsitrador->mostrar();
	}

	void mostrarTecnicos()
	{
		for (int i = 0; i < tecnicos->obtenerLongitud(); i++)
		{
			tecnicos->obtenerPos(i)->mostrar();
		}
	}

	int verifyPassword(int p)
	{
		if (adminsitrador != NULL && adminsitrador->getPassword() == p)
			return 1;
		for (int i = 0; i < tecnicos->obtenerLongitud(); i++)
		{
			if (tecnicos->obtenerPos(i)->getPassword() == p)
				return 2;
		}
		return 0;
	}

	bool verifyHashPassword(Hash& hashtable)
	{
		int password;
		cout << "\nSu contrasena: ";
		cin >> password;
		if (hashtable.findHash(password))
		{
			return true;
		}
		return false;
	}

	void add(File& file, Hash& hashtable)
	{
		int opcion = 2;
		system("CLS");
		if (adminsitrador == NULL)
		{
			cout << "Que tipo de administrador creara?\n";
			cout << "[1] Adminsitrador General (Acceso a todo tipo de cambio)\n";
			cout << "[2] Tecnico (Solo puede borrar cuentas)\n";
			opcion = verifyData<int>(2, 1);
		}	
		else
		{
			cout << "Ya existe un Adminsitrador General\n";
			cout << "Ingrese los datos de el tecnico nuevo\n\n";
		}
		cout << "Ingrese sus datos\n";
		cout << "Ingrese su nombre: ";
		string nombre;
		cin.ignore();
		getline(cin, nombre);
		cout << "Ingrese su Edad: ";
		int age = verifyData(90, 18);
		cout << "Ingrese su DNI: ";
		long long dni = verifyData<long long>(99999999, 10000000);
		cout << "Ingrese su contrasena (4 digitos, y no debe coincidir con\n\t\tlas contrasenas de los otros administradores): ";
		int password;
		cin >> password;
		while (verifyPassword(password))
		{
			cout << "Ingrese otra clave: ";
			password = verifyData(9999, 1000);
		}
		if (opcion == 1)
		{
			adminsitrador = new CAdministrador<void>(nombre, age, dni, 0, password);
		}
		else
		{
			tecnicos->push_back(new CTecnico<void>(nombre, age, dni, 0, password));
		}
		hashtable.addHash(password);
		cout << "Se registro con exito\nPulse cualquier tecla para salir.";
		actualizarRegistro(file);
	}

	bool existeAdmin()
	{
		if (adminsitrador == NULL && tecnicos->obtenerLongitud() == 0)
			return true;
		else
			return false;
	}

	bool mainAdmin()
	{
		long long auxDNI;
		cout << "Confirme su identidad (Solo puede ingresar el ADMIN, no los tecnicos)\n";
		cout << "Ingrese 0 si desea regresar al menu\n";
		if (adminsitrador==NULL)
		{
			cout << "\nNo existe ningun adminstrador, crea uno primero";
			_getch();
			return false;
		}
		cout << "\nIngrese su DNI: ";
		cin >> auxDNI;
		while (auxDNI < 9999999 || auxDNI > 100000000)
		{
			if (auxDNI == 0)
			{
				cout << "\n\nEsta regresando al menu principal\nPulse cualquier tecla para salir.";
				_getch();
				return false;
			}
			cout << "Ingrese un DNI valido o 0 para regresar al Menu: ";
			cin >> auxDNI;
		}
		if (auxDNI == adminsitrador->getDNI())
		{
			cout << "Identidad confirmada\nPulse cualquier tecla para continuar\n";
			_getch();
			return true;
		}
		cout << "DNI no es del admin\nPulse cualquier tecla para continuar\n";
		_getch();
		return false;
	}
	
	bool esAdmin(File& file, Hash& hashtable)
	{
		long long auxDNI;
		cout << "Confirme su identidad\n";
		cout << "Ingrese 0 si desea regresar al menu\n";
		if (existeAdmin())
		{
			cout << "\nNo existe ningun adminstrador, desea crear uno ahora? (1:SI, 0:NO): ";
			cin >> auxDNI;
			if (auxDNI == 1)
			{
				add(file, hashtable);
				cout << "Identidad confirmada\nPulse cualquier tecla para continuar\n";
				_getch();
				return true;
			}
			else
			{
				cout << "No se ha creado ningun administrador, ahora regresara al menu\nPulse cualquier tecla para salir.";
				_getch();
				return false;
			}
		}
		cout << "\nIngrese su DNI: ";
		cin >> auxDNI;
		while (auxDNI < 9999999 || auxDNI > 100000000)
		{
			if (auxDNI == 0)
			{
				cout << "\n\nEsta regresando al menu principal\nPulse cualquier tecla para salir.";
				_getch();
				return false;
			}
			cout << "Ingrese un DNI valido o 0 para regresar al Menu: ";
			cin >> auxDNI;
		}
		if (adminsitrador != NULL && adminsitrador->getDNI() == auxDNI)
		{
			cout << "Identidad confirmada\nPulse cualquier tecla para continuar\n";
			_getch();
			return true;
		}
		for (int i = 0; i < tecnicos->obtenerLongitud(); i++)
		{
			if (tecnicos->obtenerPos(i)->getDNI() == auxDNI)
			{
				cout << "Identidad confirmada\nPulse cualquier tecla para continuar\n";
				_getch();
				return true;
			}
		}
		cout << "Identidad no confirmada\nPulse cualquier tecla para continuar\n";
		_getch();
		return false;
	}
	
private:
	CAdministrador<void>* adminsitrador;
	Lista<CTecnico<void>*>* tecnicos;
};
