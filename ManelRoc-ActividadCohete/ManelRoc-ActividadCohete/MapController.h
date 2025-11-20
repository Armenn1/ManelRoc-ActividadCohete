#pragma once
#include "Cohete.h"

class MapController {
private:
    int tablero[10][10];
    int x1, y1;
    int x2, y2;
    Cohete* cohete1;
    Cohete* cohete2;

public:
    MapController();
    ~MapController();

    void menuPrincipal();
    void moverCohete(int idCohete, int nuevaX, int nuevaY);
    bool estanCerca();
    void dibujarMapa();
};