#include "Cohete.h"

Cohete::Cohete(string id) {
    identificador = id;
    destino = "Sin destino";
    distanciaDestino = 0;
    numCapsulas = 0;
    for (int i = 0; i < 10; i++) {
        compartimento[i] = nullptr;
    }
}

Cohete::~Cohete() {
    for (int i = 0; i < 10; i++) {
        if (compartimento[i] != nullptr) {
            delete compartimento[i];
            compartimento[i] = nullptr;
        }
    }
}

void Cohete::objetivo(string nuevoDestino, int distancia) {
    destino = nuevoDestino;
    distanciaDestino = distancia;
}

void Cohete::agregarCap(Capsula* nuevaCapsula) {
    if (numCapsulas < 10) {
        for (int i = 0; i < 10; i++) {
            if (compartimento[i] == nullptr) {
                compartimento[i] = nuevaCapsula;
                numCapsulas++;
                break;
            }
        }
    }
}

void Cohete::eliminarCap(int posicion) {
    if (posicion >= 0 && posicion < 10 && compartimento[posicion] != nullptr) {
        int energiaADistribuir = compartimento[posicion]->getEnergiaActual();

        delete compartimento[posicion];
        compartimento[posicion] = nullptr;
        numCapsulas--;

        for (int i = 0; i < 10; i++) {
            if (compartimento[i] != nullptr && energiaADistribuir > 0) {
                energiaADistribuir = compartimento[i]->inyectarEnergia(energiaADistribuir);
            }
        }
    }
}

void Cohete::transferirCap(int posicion, Cohete* coheteDestino) {
    if (posicion >= 0 && posicion < 10 && compartimento[posicion] != nullptr) {
        coheteDestino->agregarCap(compartimento[posicion]);
        compartimento[posicion] = nullptr;
        numCapsulas--;
    }
}

bool Cohete::validarViaje(int distancia) {
    int energiaTotal = 0;
    for (int i = 0; i < 10; i++) {
        if (compartimento[i] != nullptr) {
            energiaTotal = energiaTotal + compartimento[i]->getEnergiaActual();
        }
    }
    int consumo = distancia / 10;
    return energiaTotal >= consumo;
}

bool Cohete::viajar() {
    if (destino != "" && validarViaje(distanciaDestino)) {
        int consumoRestante = distanciaDestino / 10;

        for (int i = 0; i < 10; i++) {
            if (compartimento[i] != nullptr && consumoRestante > 0) {
                int energiaActual = compartimento[i]->getEnergiaActual();
                if (energiaActual >= consumoRestante) {
                    compartimento[i]->setEnergiaActual(energiaActual - consumoRestante);
                    consumoRestante = 0;
                }
                else {
                    consumoRestante = consumoRestante - energiaActual;
                    compartimento[i]->setEnergiaActual(0);
                }
            }
        }
        return true;
    }
    return false;
}

void Cohete::cargar(int cantidadEnergia) {
    int energiaRestante = cantidadEnergia;
    for (int i = 0; i < 10; i++) {
        if (compartimento[i] != nullptr && energiaRestante > 0) {
            energiaRestante = compartimento[i]->inyectarEnergia(energiaRestante);
        }
    }
}

string Cohete::getIdentificador() { return identificador; }
string Cohete::getDestino() { return destino; }
int Cohete::getDistanciaDestino() { return distanciaDestino; }
int Cohete::getNumCapsulas() { return numCapsulas; }
Capsula* Cohete::getCapsula(int posicion) {
    if (posicion >= 0 && posicion < 10) return compartimento[posicion];
    return nullptr;
}