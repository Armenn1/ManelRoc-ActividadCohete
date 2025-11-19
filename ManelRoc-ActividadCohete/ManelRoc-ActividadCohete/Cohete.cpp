#include "Cohete.h"

Cohete::Cohete()
{
	id = 0;
	
	destino = 0;
	distancia = 0;
	cantidadCapsulas = 0;
	for (int i = 0; i < 10; i++)
	{
		 compartimento[i] = new Capsula(10000);
	}

}

Cohete::Cohete(int _id, int _destino, int _distancia, int _cantidadCapsulas)
{
	id = _id;
	destino = _destino;
	distancia = _distancia;
	cantidadCapsulas = _cantidadCapsulas;

	for (int i = 0; i < 10; i++)
	{
		compartimento[i] = 0;
	}
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
