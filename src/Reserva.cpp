#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}


int getAsientosReservados(){
    getAsientosReservados = this->asientosReservados;
};

Reserva::~Reserva() {}
