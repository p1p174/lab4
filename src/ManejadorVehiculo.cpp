#include "../include/ManejadorVehiculo.h"

ManejadorVehiculo* ManejadorVehiculo::instancia = nullptr;


bool ManejadorVehiculo::existeVehiculo(std::string matricula) {
    return vehiculos.find(matricula) != vehiculos.end();
}

ManejadorVehiculo::Vehiculo getVehiculo() {
    auto it = vehiculos.find(matricula);
    if (it == vehiculos.end()) {
        return nullptr;
    }
    return it->second;
}

void ManejadorVehiculo::addVehiculo() {
    vehiculos[vehiculo->getMatricula()] = vehiculo;
}

ManejadorVehiculo* ManejadorVehiculo::getInstance() {
    if(instancia == nullptr) {
        instancia = new ManejadorVehiculo();
    }
    return instancia;
}

Vehiculo* ManejadorVehiculo::getVehiculo(std::string matricula) {
    auto it = vehiculos.find(matricula);
    if (it == vehiculos.end()) {
        return nullptr;
    }
    return it->second;
}