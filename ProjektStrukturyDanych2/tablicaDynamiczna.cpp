#include "tablicaDynamiczna.h"

void tablicaKolejka::resize(int nowaPojemnosc)
{
	Dane* kopie = new Dane[nowaPojemnosc];
	for (int i = 0; i < liczbaElementow; i++)
	{
		kopie[i] = tablica[i];
	}
	delete[] tablica;
	tablica = kopie;
	pojemnosc = nowaPojemnosc;
}


void tablicaKolejka::sortowanie()
{

	for (int i = 0; i < liczbaElementow; i++)
	{
		for (int j = 0; j < liczbaElementow; j++)
		{
			Dane temp;
			if (tablica[i].piorytet > tablica[j].piorytet)
			{
				temp = tablica[i];
				tablica[i] = tablica[j];
				tablica[j] = temp;
			}
		}
	}
}

void tablicaKolejka::insert(int element, int piorytet)
{
	liczbaElementow++;
	resize(liczbaElementow);
	tablica[liczbaElementow - 1].piorytet = piorytet;
	tablica[liczbaElementow - 1].element = element;
	sortowanie();
}

int tablicaKolejka::extractMax()
{
	int max = tablica[0].element;
	for (int i = 1; i < liczbaElementow; i++)
	{
		tablica[i - 1] = tablica[i];
	}
	liczbaElementow--;
	resize(liczbaElementow);
	return max;
}

int tablicaKolejka::findMax()
{
	return tablica[0].element;
}

void tablicaKolejka::modifyKey(int element, int piorytet)
{
	tablica[element - 1].piorytet = piorytet;
	sortowanie();
}

int tablicaKolejka::returnsize()
{
	return liczbaElementow;
}

void tablicaKolejka::pokaz()
{
	for (int i = 0; i < liczbaElementow; i++)
	{
		cout << tablica[i].element << endl;
	}
}
