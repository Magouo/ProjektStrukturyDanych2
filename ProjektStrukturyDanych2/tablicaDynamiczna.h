#include <iostream>
using namespace std;

struct Dane
{
	int element;
	int piorytet;
	Dane()
	{
		element = 0;
		piorytet = 0;
	}
};

class tablicaKolejka
{
private:
	Dane* tablica;
	int pojemnosc;
	int liczbaElementow;
	void resize(int nowaPojemnosc);
	void sortowanie();
public:
	tablicaKolejka()
	{
		pojemnosc = 2;
		liczbaElementow = 0;
		tablica = new Dane[pojemnosc];
	}
	~tablicaKolejka()
	{
		delete[] tablica;
	}
	void insert(int element, int piorytet);
	int extractMax();
	int findMax();
	void modifyKey(int element, int piorytet);
	int returnsize();
	void pokaz();
};

