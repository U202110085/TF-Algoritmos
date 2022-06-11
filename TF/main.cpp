#include "libs.h"
#include "File.h"
#include "CController.h"
#include "Administracion.h"
#include "CBanco.h"
#include "Menu.h"

int main2()
{
	Lista<CTecnico<void>*>* listaTecnicos = new Lista<CTecnico<void>*>();
	listaTecnicos->push_back(new CTecnico<void>("Hug", 23, 12345678, 50));
	listaTecnicos->push_back(new CTecnico<void>("Pau", 43, 88888888, 20));
	listaTecnicos->push_back(new CTecnico<void>("Rox", 66, 77777744, 3));
	
	CAdministrador<void>* admin = new CAdministrador<void>("Lucas", 18, 78886182, 100);
	Adminsitracion<void> administracion = Adminsitracion<void>(listaTecnicos);
	administracion.mostrarAdministrador();
	administracion.mostrarTecnicos();
	
	_getch();
	return 0;
}

int main()
{
	Console::SetWindowSize(100, 18);
	Console::CursorVisible = false;
	
	File* file = new File();
	file->readData();

	CController* controller = new CController(file->getPasajero(), file->getConductores(), file->getViajes());
	CBanco* banco = new CBanco();

	bool flag = true;
	short key1 = 0, key2 = 0, paceSetter = 0;
	do
	{
		std::system("CLS");
		switch (paceSetter)
		{
		case 0:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD) key2 = getch();
			if (key2 == 72) paceSetter = 7;
			if (key2 == 80) paceSetter = 1;
		case 1:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 8;
				if (key2 == 80) paceSetter = 2;
			}
			else
			{
				std::system("CLS");
				controller->agregarUsuario(*file);
				paceSetter = 0;
			}
			break;
		case 2:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 1;
				if (key2 == 80) paceSetter = 3;
			}
			else
			{
				std::system("CLS");
				banco->agregarDineroTarjeta(*file, controller);
				paceSetter = 0;
			}
			break;
		case 3:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 2;
				if (key2 == 80) paceSetter = 4;
			}
			else
			{
				std::system("CLS");
				controller->imprimirDatos();
				paceSetter = 0;
			}
			break;
		case 4:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 3;
				if (key2 == 80) paceSetter = 5;
			}
			else
			{
				std::system("CLS");
				banco->imprimirDatosOrdenando(controller);
				paceSetter = 0;
			}
			break;
		case 5:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 4;
				if (key2 == 80) paceSetter = 6;
			}
			else
			{
				std::system("CLS");
				controller->realizarViaje(*file);
				paceSetter = 0;
			}
			break;
		case 6:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 5;
				if (key2 == 80) paceSetter = 7;
			}
			else
			{
				std::system("CLS");
				controller->imprimirViajes();
				paceSetter = 0;
			}
			break;
		case 7:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 6;
				if (key2 == 80) paceSetter = 8;
			}
			else
			{
				std::system("CLS");
				controller->calcularDatosGenerales();
				paceSetter = 0;
			}
			break;
		case 8:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 7;
				if (key2 == 80) paceSetter = 9;
			}
			else
			{
				std::system("CLS");
				// AQUI VAN LAS INSTRUCCIONES DE ADMINSTRACION
				// 
				// manipulacion->(bool, &file)
				// bool es adminstracion->esAdmin();
				// dentro del metodo manipulacion, se hace una verifiacion de q tipo de admin es
				// es caso sea administrador, tiene dos opciones, borrar toda la base de datos 
				// o borrar 1 solo cuenta
				// en caso sea solo 1 tecnico entonces solo podra borrar 1 cuenta
				// 
				//
				paceSetter = 0;
			}
			break;
		case 9:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 8;
				if (key2 == 80) paceSetter = 1;
			}
			else
			{
				flag = false;
			}
			break;
		}
		flushall();
	} while (flag);
	
	return 0;

}