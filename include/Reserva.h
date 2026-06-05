#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    getAsientosReservados() : int;
    getViaje() : Viaje;
    ~Reserva();
};

#endif
