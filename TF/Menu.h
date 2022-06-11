#pragma once
#include <string>
#include <iostream>

using namespace std;
using namespace System;

#define printRed Console::ForegroundColor = ConsoleColor::DarkRed
#define printGray Console::ForegroundColor = ConsoleColor::Gray
#define printGreen Console::ForegroundColor = ConsoleColor::Green

const int numMenu = 9;

string menu[numMenu] = {
	"[1] Agregar un usuario (pasajero o conductor)",
	"[2] Agregar dinero a tarjeta (solo para pasajeros)",
	"[3] Imprimir todos los datos de ambos pasajeros y conductores",
	"[4] Imprimir todos los datos por parte del banco",
	"[5] Realizar un viaje(solo para pasajeros)",
	"[6] Imprimir los viajes realizados para ambos pasajeros y conductores",
	"[7] Busca los datos generales en nuestra base de datos",
	"[8] Administracion",
	"[9] Salir"
};

void printMenu(int paceSetter)
{
	for (int i = 0; i < numMenu; i++)
	{
		Console::SetCursorPosition(15, 5 + i);
		printGray;
		if (i == paceSetter - 1)
		{
			printRed;
			cout << menu[i];
		}
		else cout << menu[i];
	}
	printGray;
}