#include "Cohete.h"

Cohete::Cohete()
{
	id = 0;
	int destino[10][10] = { 0,0 };
	distancia = 0;
	
	for (int i = 0; i < 10; i++)
	{
		 compartimento[i] = 0;
	}

}

Cohete::Cohete(int _id, int _destino[10][10], int _distancia)
{
	id = _id;
	destino[10][10] = _destino[10][10];
	distancia = _distancia;
}

void Cohete::AgregarCap(int posC)
{
	
	// Agregar capsula en la posición posC introducida por el usuario

	cout << "En que posición desea agregar la cápsula (0-9): " << endl;
	cin >> posC;
	compartimento[posC] = new Capsula(100000);

}

void Cohete::EliminarCap(int posC)
{
	cout << "En que posición desea eliminar la cápsula (0-9): " << endl;
	cin >> posC;
	compartimento[posC] = nullptr;
}
