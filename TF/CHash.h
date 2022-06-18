#pragma once
#include <cmath>
#include <set>
#include "libs.h"
#include "CTrieTree.h"
		
class Hash
{
public:
	Hash()
	{
		tree = new TrieTree();
	}
	void readHash()
	{
		fileRead.open("passwordsHASH.txt", ios::out);

		if (fileRead.fail())
		{
			fileRead.close();

			fileWrite.open("passwordsHASH.txt", ios::out);
			fileWrite.close();

			fileRead.open("passwordsHASH.txt", ios::in);
		}

		string s;
		while (getline(fileRead, s))
		{
			tree->insert(s);
			hash.insert(stoi(s));
		}
	}
	void writeHash()
	{
		fileWrite.open("passwordsHASH.txt", ios::out);
		
		for (auto i : hash)
		{
			fileWrite << i << endl;
		}
		
		fileWrite.close();
	}
	void actualizarTree()
	{
		tree->clear();
		for (auto i : hash)
		{
			tree->insert(to_string(i));
		}
	}
	void addHash(int message)
	{
		int code = funcionHash(message);
		hash.insert(code);
		tree->insert(to_string(code));
		writeHash();
	}
	void printHash()
	{
		for (auto i : hash)
		{
			cout << i << endl;
		}
	}
	bool findHash(int message)
	{
		int code = funcionHash(message);
		return tree->search(code);
	}
	int getHashCode(int message)
	{
		//funcion HASH
		if (message < 1000 || message > 9999)
			return -1;
		return funcionHash(message);
	}
private:
	TrieTree* tree;
	set<int> hash;
	ofstream fileWrite;
	ifstream fileRead;
	int funcionHash(int message)
	{
		int sum1(0), sum2(0);
		int a, b, c, d;
		int ha, hb, hc, hd;
		a = message / 1000;
		b = message % 1000 / 100;
		c = message % 100 / 10;
		d = message % 10;
		// suma de primer y ultimo elemento
		ha = a + b;
		while (ha >= 10)
		{
			ha = round(ha / 10);
		}
		// multiplicacion de la suma de pares e impares
		if (a % 2 == 0)sum1 += a;
		else sum2 += a;
		if (b % 2 == 0)sum1 += b;
		else sum2 += b;
		if (c % 2 == 0)sum1 += c;
		else sum2 += c;
		if (d % 2 == 0)sum1 += d;
		else sum2 += d;
		hb = sum1 * sum2;
		while (hb >= 10)
		{
			hb = round(hb / 10);
		}
		// elevar al cuadrado las posiciones y sumarlos
		hc = (a * a) + (b * b) + (c * c) + (d * d);
		while (hc >= 10)
		{
			hc = round(hc / 10);
		}
		//suma de (a + b)/d
		if (d != 0)
			hd = (a + b) / d;
		else
			hd = (a + b) / 1;

		while (hd >= 10)
		{
			hd = round(hd / 10);
		}
		return (ha * 1000) + (hb * 100) + (hc * 10) + hd;
	}
};
		