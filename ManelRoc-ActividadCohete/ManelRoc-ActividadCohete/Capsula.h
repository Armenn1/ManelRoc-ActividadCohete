#pragma once
class Capsula
{
private:
	int energiaActual; // KWh	
public:
	Capsula(int capacidad);
	int getEnergiaActual();
	void consumirEnergia(int cantidad);
	void recargarEnergia(int cantidad);
};

