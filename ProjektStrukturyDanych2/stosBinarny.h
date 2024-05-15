#include <iostream>
#include "tablicaDynamiczna.h"
using namespace std;
class stos
{
private:
	Dane* stosBinarny;
	int wielkosc;
	int rozmiar;
	int rodzic(int element);
	int leweDziecko(int element);
	int praweDziecko(int element);
	void resize(int nowaPojemnosc);
public:
	stos()
	{
		wielkosc = 2;
		rozmiar = 0;
		stosBinarny = new Dane[wielkosc];
	}
	~stos()
	{
		delete[] stosBinarny;
	}
	void insert(int element, int piorytet);
	int extractMax();
	int findMax();
	void modifyKey(int element, int piorytet);
	int returnsize();
	void pokaz();
};