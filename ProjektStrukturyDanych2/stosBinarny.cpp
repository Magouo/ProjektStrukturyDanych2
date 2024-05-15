#include "stosBinarny.h"
int stos::rodzic(int element)
{
	int rodzic = (element - 1) / 2;
	return rodzic;
}
int stos::leweDziecko(int element)
{
	int dziecko = element * 2 + 1;
	return dziecko;
}
int stos::praweDziecko(int element)
{
	int dziecko = element * 2 + 2;
	return dziecko;
}
void stos::resize(int nowaPojemnosc)
{
	Dane* kopie = new Dane[nowaPojemnosc];
	for (int i = 0; i < rozmiar; i++)
	{
		kopie[i] = stosBinarny[i];
	}
	delete[] stosBinarny;
	stosBinarny = kopie;
	wielkosc = nowaPojemnosc;
}
void stos::insert(int element, int piorytet)
{
	rozmiar++;
	resize(rozmiar);
	stosBinarny[rozmiar - 1].element = element;
	stosBinarny[rozmiar - 1].piorytet = piorytet;
	int pomocnicza = rozmiar - 1;
	while (stosBinarny[pomocnicza].piorytet > stosBinarny[rodzic(pomocnicza)].piorytet)
	{
		Dane temp;
		temp = stosBinarny[pomocnicza];
		stosBinarny[pomocnicza] = stosBinarny[rodzic(pomocnicza)];
		stosBinarny[rodzic(pomocnicza)] = temp;
		pomocnicza = rodzic(pomocnicza);
	}
}
int stos::extractMax()
{
	int max = stosBinarny[0].element;
	rozmiar--;
	stosBinarny[0] = stosBinarny[rozmiar];
	int najwiekszy = 0;
	int index = 0;
	while (true)
	{
		int lewy = leweDziecko(najwiekszy);
		int prawy = praweDziecko(najwiekszy);
		if (prawy < rozmiar && stosBinarny[prawy].piorytet > stosBinarny[najwiekszy].piorytet)
		{
			najwiekszy = prawy;
		}
		if (lewy < rozmiar && stosBinarny[lewy].piorytet > stosBinarny[najwiekszy].piorytet)
		{
			najwiekszy = lewy;
		}

		if (najwiekszy == index)
		{
			break;
		}
		else {
			Dane temp;
			temp = stosBinarny[index];
			stosBinarny[index] = stosBinarny[najwiekszy];
			stosBinarny[najwiekszy] = temp;
			index = najwiekszy;
		}
	}
	resize(rozmiar);
	return max;
}
int stos::findMax()
{
	return stosBinarny[0].element;
}
void stos::modifyKey(int element, int piorytet)
{
	int staryPiorytet = stosBinarny[element].piorytet;
	stosBinarny[element].piorytet = piorytet;

	if (staryPiorytet < piorytet)
	{
		int pomocnicza = rozmiar - 1;

		while (stosBinarny[pomocnicza].piorytet > stosBinarny[rodzic(pomocnicza)].piorytet)
		{
			Dane temp;
			temp = stosBinarny[pomocnicza];
			stosBinarny[pomocnicza] = stosBinarny[rodzic(pomocnicza)];
			stosBinarny[rodzic(pomocnicza)] = temp;
			pomocnicza = rodzic(pomocnicza);
		}
	}
	else {
		if (element == 0) {
			while (element < rozmiar - 1)
			{
				int lewy = leweDziecko(element);
				int prawy = praweDziecko(element);
				int najwiekszy = element;
				if (stosBinarny[prawy].piorytet > stosBinarny[najwiekszy].piorytet)
				{
					najwiekszy = prawy;
				}
				if (stosBinarny[lewy].piorytet > stosBinarny[najwiekszy].piorytet)
				{
					najwiekszy = lewy;
				}

				if (najwiekszy == element)
				{
					break;
				}
				else {
					Dane temp;
					temp = stosBinarny[element];
					stosBinarny[element] = stosBinarny[najwiekszy];
					stosBinarny[najwiekszy] = temp;
					element = najwiekszy;
				}
			}
		}
		else {
			while (element < rozmiar)
			{
				int lewy = leweDziecko(element);
				int prawy = praweDziecko(element);
				int najwiekszy = element;
				if (stosBinarny[prawy].piorytet > stosBinarny[najwiekszy].piorytet)
				{
					najwiekszy = prawy;
				}
				if (stosBinarny[lewy].piorytet > stosBinarny[najwiekszy].piorytet)
				{
					najwiekszy = lewy;
				}

				if (najwiekszy == element)
				{
					break;
				}
				else {
					Dane temp;
					temp = stosBinarny[element];
					stosBinarny[element] = stosBinarny[najwiekszy];
					stosBinarny[najwiekszy] = temp;
					element = najwiekszy;
				}
			}
		}

	}

}
int stos::returnsize()
{
	return rozmiar;
}
void stos::pokaz()
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << "                rodzic: " << stosBinarny[i].element << endl << "prawe dziecko: ";
		if (i * 2 + 2 >= rozmiar) {
			cout << "brak" << " lewe dziecko: ";
		}
		else {
			cout << stosBinarny[i * 2 + 2].element << " lewe dziecko: ";
		}
		if (i * 2 + 1 >= rozmiar) {
			cout << "brak" << endl;;
		}
		else {
			cout << stosBinarny[i * 2 + 1].element << endl;;
		}
	}
}