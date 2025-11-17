#include <iostream>
#include "Capsula.h"
using namespace std;
#pragma once

// Un cohete tiene un identificador, un destino, la distancia al destino y un compartimento que puede alojar hasta 10 cápsulas de energía.Cada 100.000 Km consumen 10.000KWh de energía.
// Representa el compartimento de las cápsulas como un array de 10 apuntadores a objetos cápsula.
// En caso de que un compartimento no tenga ninguna cápsula su apuntador tiene que tomar como valor nullptr.
// Incluye al conjunto de miembros de datos de la clase cohete un número que indique la cantidad de cápsulas que aloja en un momento determinado.

class Cohete
{
protected:  
	int id;
	int destino[10][10];
	int distancia;
	Capsula* compartimento[10];
	int cantidadCapsulas;

public:
	Cohete();
	Cohete(int _id, int _destino[10][10], int _distancia);
	void AgregarCap(int posC);
	void EliminarCap(int posC);
	// TransferirCap
	// ValidarViaje
	// Viajar
	// Cargar
};

