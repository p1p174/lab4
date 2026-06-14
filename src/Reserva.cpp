#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}


int Reserva::getAsientosReservados(){
    return this->asientosReservados;
};
DTFecha Reserva::getFecha(){ return this->fecha; };

Pasajero* Reserva::getPasajero(){ return this->pasajero; };
Viaje* Reserva::getViaje(){ return this->viaje; };

std::set<Calificacion*> Reserva::getCalificaciones() {
    return this->calificaciones;
}

void Reserva::agregarCalificacion(Calificacion* cal) {
    calificaciones.insert(cal);
}

void Reserva::eliminarCalificacion(Calificacion* cal) {
    calificaciones.erase(cal);
}

void Reserva::eliminarCalificaciones(){ calificaciones.clear(); }

void Reserva::setPasajero(Pasajero* p) { this->pasajero = p; }
void Reserva::setViaje(Viaje* v) { this->viaje = v; }

Reserva::~Reserva() {}
