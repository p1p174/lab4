#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje, Usuario* u) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->reserva = nullptr;
    this->usuario = u;
}

Calificacion::~Calificacion() {}

DTFecha Calificacion::getFecha() {
    return this->fecha;
}

int Calificacion::getPuntaje() {
    return this->puntaje;
}

Reserva* Calificacion::getReserva() {
    return this->reserva;
}

Usuario* Calificacion::getUsuario() {
    return this->usuario;
}

void Calificacion::linkearReserva(Reserva* r) {
    this->reserva = r;
}