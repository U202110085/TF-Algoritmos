#include "GeneradorDelDataset.h"
#include "CController.h"
#include "CBanco.h"
#include "Menu.h"
#include "CManipulacion.h"

int main()
{


	DataGenerator* dataG = new DataGenerator();
	dataG->menu();
	
	Console::SetWindowSize(100, 18);
	Console::CursorVisible = false;
	
	File* file = new File();
	Hash* hashtable = new Hash();
	file->readData();
	hashtable->readHash();

	CManipulacion<void> manipulacion;
	Adminsitracion<void>* administrador;
	if (file->getAdmin() == NULL)
	{
		administrador = new Adminsitracion<void>(file->getTecnicos());
	}
	else administrador = new Adminsitracion<void>(file->getAdmin(), file->getTecnicos());
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
			if (key2 == 72) 
				paceSetter = 9;
			if (key2 == 80) 
				paceSetter = 1;
			break;
		case 1:
			printMenu(paceSetter);
			key1 = getch();
			if (key1 != 0xD)
			{
				key2 = getch();
				if (key2 == 72) paceSetter = 9;
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
				manipulacion.menu(*administrador, *file, *hashtable, *controller);
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