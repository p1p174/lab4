#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::vector<DTDetalleVehiculo> vehiculos)
    {
    this->vehiculos = vehiculos;
}

std::vector<DTDetalleVehiculo> DTVehiculosConductor::getVehiculos() {
    return vehiculos;
}

// std::set ordena automaticamente los elementos, por eso necesitamos la funcion para que logre comparar y asi poner uno primero y otro despues
bool DTVehiculosConductor::operator<(const DTVehiculosConductor& otro) const {
    return matricula < otro.matricula;
}