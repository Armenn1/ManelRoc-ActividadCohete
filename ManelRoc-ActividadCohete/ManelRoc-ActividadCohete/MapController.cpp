#include "MapController.h"
#include <iostream>

using namespace std;

MapController::MapController() {
    x1 = 0; y1 = 0;
    x2 = 9; y2 = 9;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) tablero[i][j] = 0;
    }

    tablero[x1][y1] = 1;
    tablero[x2][y2] = 2;

    cohete1 = new Cohete("Nave 1");
    cohete2 = new Cohete("Nave 2");
}

MapController::~MapController() {
    delete cohete1;
    delete cohete2;
}

void MapController::moverCohete(int idCohete, int nuevaX, int nuevaY) {
    if (nuevaX >= 0 && nuevaX < 10 && nuevaY >= 0 && nuevaY < 10) {
        if (idCohete == 1) {
            tablero[x1][y1] = 0;
            x1 = nuevaX; y1 = nuevaY;
            tablero[x1][y1] = 1;
        }
        else if (idCohete == 2) {
            tablero[x2][y2] = 0;
            x2 = nuevaX; y2 = nuevaY;
            tablero[x2][y2] = 2;
        }
    }
    else {
        cout << "ERROR: Coordenadas fuera del espacio." << endl;
    }
}

bool MapController::estanCerca() {
    int difX = x1 - x2;
    int difY = y1 - y2;
    if (difX < 0) difX = difX * -1;
    if (difY < 0) difY = difY * -1;

    if (difX <= 1 && difY <= 1) return true;
    return false;
}

void MapController::dibujarMapa() {
    cout << "\n===== MAPA ESPACIAL =====" << endl;
    for (int i = 0; i < 10; i++) {
        cout << " " << i << " ";
        for (int j = 0; j < 10; j++) {
            if (tablero[j][i] == 0) cout << "[ ]";
            else if (tablero[j][i] == 1) cout << "[1]";
            else if (tablero[j][i] == 2) cout << "[2]";
        }
        cout << endl;
    }
    cout << "    0  1  2  3  4  5  6  7  8  9" << endl;
    cout << "=========================" << endl;
}

void MapController::menuPrincipal() {
    int seleccionNave = 0;

    do {
        dibujarMapa();
        cout << "SELECCIONA NAVE:" << endl;
        cout << "1. Nave 1 (Pos: " << x1 << "," << y1 << ")" << endl;
        cout << "2. Nave 2 (Pos: " << x2 << "," << y2 << ")" << endl;
        cout << "0. Salir" << endl;
        cout << "> ";
        cin >> seleccionNave;

        if (seleccionNave == 1 || seleccionNave == 2) {
            Cohete* naveActual = (seleccionNave == 1) ? cohete1 : cohete2;
            Cohete* naveOtra = (seleccionNave == 1) ? cohete2 : cohete1;

            int accion = 0;
            do {
                cout << "\n--- ORDENES NAVE " << naveActual->getIdentificador() << " ---" << endl;
                cout << "1. Mover (Coordenadas)" << endl;
                cout << "2. STATUS (Energia y Capsulas)" << endl;
                cout << "3. Instalar Capsula" << endl;
                cout << "4. Eliminar Capsula" << endl;
                cout << "5. Cargar Bateria" << endl;
                cout << "6. Fijar Objetivo" << endl;
                cout << "7. INICIAR VIAJE" << endl;

                bool contacto = estanCerca();
                if (contacto) {
                    cout << "8. [!] TRANSFERIR CAPSULA [!]" << endl;
                }

                cout << "0. Volver al Mapa" << endl;
                cout << "Elige accion: ";
                cin >> accion;

                if (accion == 1) {
                    int nx, ny;
                    cout << "Nueva X: "; cin >> nx;
                    cout << "Nueva Y: "; cin >> ny;
                    moverCohete(seleccionNave, nx, ny);
                    accion = 0;

                }
                else if (accion == 2) {
                    cout << "\n--- STATUS SISTEMA ---" << endl;
                    cout << "Destino: " << naveActual->getDestino() << " Dist: " << naveActual->getDistanciaDestino() << endl;
                    cout << "Capsulas: " << naveActual->getNumCapsulas() << "/10" << endl;
                    int energiaTotal = 0;
                    for (int i = 0; i < 10; i++) {
                        Capsula* c = naveActual->getCapsula(i);
                        if (c != nullptr) {
                            cout << "Slot " << i << ": " << c->getEnergiaActual() << "/" << c->getCapacidadMaxima() << endl;
                            energiaTotal += c->getEnergiaActual();
                        }
                        else {
                            cout << "Slot " << i << ": [VACIO]" << endl;
                        }
                    }
                    cout << "Energia Total: " << energiaTotal << endl;

                }
                else if (accion == 3) {
                    Capsula* c = new Capsula(100);
                    naveActual->agregarCap(c);
                    cout << "Instalada." << endl;

                }
                else if (accion == 4) {
                    int pos;
                    cout << "Slot (0-9): "; cin >> pos;
                    naveActual->eliminarCap(pos);
                    cout << "Eliminada." << endl;

                }
                else if (accion == 5) {
                    int carga;
                    cout << "Cantidad: "; cin >> carga;
                    naveActual->cargar(carga);
                    cout << "Cargado." << endl;

                }
                else if (accion == 6) {
                    string dest;
                    int dist;
                    cout << "Destino: "; cin >> dest;
                    cout << "Distancia: "; cin >> dist;
                    naveActual->objetivo(dest, dist);

                }
                else if (accion == 7) {
                    bool exito = naveActual->viajar();
                    if (exito) cout << "VIAJE EXITOSO!" << endl;
                    else cout << "FALLO: Energia/Destino." << endl;

                }
                else if (accion == 8 && contacto) {
                    int pos;
                    cout << "Slot a transferir (0-9): "; cin >> pos;
                    naveActual->transferirCap(pos, naveOtra);
                    cout << "Transferida." << endl;
                }

            } while (accion != 0);
        }
    } while (seleccionNave != 0);
}