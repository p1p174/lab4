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
    return DTVehiculosConductor(this->matricula, this->capacidad, this->marca, this->modelo, this->tipo);
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

std::set<Viaje*> Vehiculo::getViajes() {
    return this->viajes;
}
