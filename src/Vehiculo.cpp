#include "../include/Vehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

void Vehiculo::addViaje(Viaje* v) {
    this->viajes.insert(v);
}

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
    for (Viaje* v: viajes) {
        if (v->getFecha() == fecha) {
            return true;
        }
    }
    return false;
}

DTVehiculosConductor Vehiculo::getDTVehiculosConductor() {
    // no estoy muy seguro de si va marca o modelo
    return DTVehiculosConductor(this->matricula, this->marca, this->capacidad);
}

std::string Vehiculo::getMatricula() {
    return this->matricula;
}

int Vehiculo::getCapacidad() {
    return this->capacidad;
}

std::string Vehiculo::getMarca() {
    return this->marca;
}

std::string Vehiculo::getModelo() {
    return this->modelo;
}
TipoVehiculo Vehiculo::getTipo() { return this->tipo; }

std::set<Viaje*> Vehiculo::getViajes() {
    return this->viajes;
}
void Vehiculo::agregarViaje(Viaje* v){ viajes.insert(v); }
void Vehiculo::borrarViaje(Viaje* v){ viajes.erase(v); }

Conductor* Vehiculo::getConductor() {
    return this->conductor;
}