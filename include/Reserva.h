#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"

class Viaje; 

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    int getAsientosReservados();
    Viaje* getViaje();
    ~Reserva();
};

#endif
