#include "Capsula.h"

Capsula::Capsula(int e)
{
	e = energiaActual;
}

int Capsula::getEnergiaActual()
{
	return energiaActual;
}

void Capsula::consumirEnergia(int cantidad)
{
	energiaActual -= cantidad;
}

void Capsula::recargarEnergia(int cantidad)
{
	energiaActual += cantidad;
}
