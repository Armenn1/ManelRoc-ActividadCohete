#include "Capsula.h"

Capsula::Capsula(int capacidadMax) {
    this->capacidadMaxima = capacidadMax;
    this->energiaActual = 0;
}

Capsula::~Capsula() {
}

int Capsula::getEnergiaActual() {
    return energiaActual;
}

int Capsula::getCapacidadMaxima() {
    return capacidadMaxima;
}

void Capsula::setEnergiaActual(int energia) {
    if (energia > capacidadMaxima) {
        energiaActual = capacidadMaxima;
    }
    else if (energia < 0) {
        energiaActual = 0;
    }
    else {
        energiaActual = energia;
    }
}

int Capsula::inyectarEnergia(int cantidad) {
    int espacioLibre = capacidadMaxima - energiaActual;

    if (cantidad <= espacioLibre) {
        energiaActual = energiaActual + cantidad;
        return 0;
    }
    else {
        energiaActual = capacidadMaxima;
        return cantidad - espacioLibre;
    }
}