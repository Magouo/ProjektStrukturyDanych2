#include <iostream>
#include "stosBinarny.h"
#include <chrono>
int main()
{
	double tablicaInsert = 0;
	double tablicaExtract = 0;
	double tablicaFindMax = 0;
	double tablicaModifyKey = 0;
	double tablicaReturnSize = 0;

	double stosInsert = 0;
	double stosExtract = 0;
	double stosFindMax = 0;
	double stosModifyKey = 0;
	double stosReturnSize = 0;
	chrono::duration<double, nano> czas;

	// 500 800 1000 1600 2000 3200
	int rozmiar = 10000;

	for (int i = 0; i < 10; i++)
	{
		tablicaKolejka tablica;
		stos stosBinarny;
		
		for (int j = 0; j < rozmiar; j++)
		{
			int a = rand() % 10000 + 1;
			int b = rand() % 10000 + 1;
			stosBinarny.insert(a, b);
			tablica.insert(a, b);
		}

		for (int k = 0; k < 5; k++)
		{
			int a = rand() % 10000 + 1;
			int b = rand() % 10000 + 1;
			auto start = chrono::high_resolution_clock::now();
			stosBinarny.insert(a, b);
			auto stop = chrono::high_resolution_clock::now();
			czas = stop - start;
			stosInsert += czas.count();

			auto start1 = chrono::high_resolution_clock::now();
			tablica.insert(a, b);
			auto stop1 = chrono::high_resolution_clock::now();
			czas = stop1 - start1;
			tablicaInsert += czas.count();

		}

		for (int l = 0; l <5; l++)
		{
			auto start = chrono::high_resolution_clock::now();
			stosBinarny.extractMax();
			auto stop = chrono::high_resolution_clock::now();
			czas = stop - start;
			stosExtract += czas.count();

			auto start1 = chrono::high_resolution_clock::now();
			tablica.extractMax();
			auto stop1 = chrono::high_resolution_clock::now();
			czas = stop1 - start1;
			tablicaExtract += czas.count();
		}
		for (int m = 0; m < 5; m++)
		{
			auto start = chrono::high_resolution_clock::now();
			stosBinarny.findMax();
			auto stop = chrono::high_resolution_clock::now();
			czas = stop - start;
			stosFindMax += czas.count();

			auto start1 = chrono::high_resolution_clock::now();
			tablica.findMax();
			auto stop1 = chrono::high_resolution_clock::now();
			czas = stop1 - start1;
			tablicaFindMax += czas.count();
		}
		for (int n = 0; n <5; n++)
		{	
			int a = rand() % (rozmiar-1) + 2;
			int b = rand() % 10000 + 1;

			auto start = chrono::high_resolution_clock::now();
			stosBinarny.modifyKey(a, b);
			auto stop = chrono::high_resolution_clock::now();
			czas = stop - start;
			stosModifyKey += czas.count();

			auto start1 = chrono::high_resolution_clock::now();
			tablica.modifyKey(a, b);
			auto stop1 = chrono::high_resolution_clock::now();
			czas = stop1 - start1;
			tablicaModifyKey += czas.count();
		}

		for (int o = 0; o < 5; o++)
		{
			auto start = chrono::high_resolution_clock::now();
			stosBinarny.returnsize();
			auto stop = chrono::high_resolution_clock::now();
			czas = stop - start;
			stosReturnSize += czas.count();

			auto start1 = chrono::high_resolution_clock::now();
			tablica.returnsize();
			auto stop1 = chrono::high_resolution_clock::now();
			czas = stop1 - start1;
			tablicaReturnSize += czas.count();
		}
	}

	cout << "Rozmiar: " << rozmiar << endl;
	cout << "Tablica" << endl;
	cout << "Insert: " << tablicaInsert/50 << endl;
	cout << "Extract: " << tablicaExtract/50 << endl;
	cout << "Find: " << tablicaFindMax/50  << endl;
	cout << "Modify: " << tablicaModifyKey/50 << endl;
	cout << "Return: " << tablicaReturnSize/50 << endl;

	cout << endl <<  "Stos" << endl;
	cout << "Insert: " << stosInsert/50 << endl;
	cout << "Extract: " << stosExtract/50 << endl;
	cout << "Find: " << stosFindMax/50 << endl;
	cout << "Modify: " << stosModifyKey/50 << endl;
	cout << "Return: " << stosReturnSize/50 << endl;
}
