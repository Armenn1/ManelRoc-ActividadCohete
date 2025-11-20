#pragma once
#include <string>
#include "Capsula.h"

using namespace std;

class Cohete {
private:
    string identificador;
    string destino;
    int distanciaDestino;
    Capsula* compartimento[10];
    int numCapsulas;

public:
    Cohete(string id);
    ~Cohete();

    void objetivo(string nuevoDestino, int distancia);
    void agregarCap(Capsula* nuevaCapsula);
    void eliminarCap(int posicion);
    void transferirCap(int posicion, Cohete* coheteDestino);
    bool validarViaje(int distancia);
    bool viajar();
    void cargar(int cantidadEnergia);

    string getIdentificador();
    string getDestino();
    int getDistanciaDestino();
    int getNumCapsulas();
    Capsula* getCapsula(int posicion);
};