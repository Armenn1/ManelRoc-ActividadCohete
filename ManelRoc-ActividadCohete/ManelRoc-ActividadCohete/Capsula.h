#pragma once

class Capsula {
private:
    int energiaActual;
    int capacidadMaxima;

public:
    Capsula(int capacidadMax = 100);
    ~Capsula();

    int getEnergiaActual();
    int getCapacidadMaxima();
    void setEnergiaActual(int energia);
    int inyectarEnergia(int cantidad);
};