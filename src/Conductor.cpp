#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}
bool Conductor::es_pasajero() { return false; }


void Conductor::addVehiculo(Vehiculo* v) {
    this->vehiculos.insert(v);
}

bool Conductor::puedeRegistrar(TipoVehiculo tipo) {
    
    return false;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    for (Vehiculo* v: vehiculos) {
        if (v->hayViajesFecha(fecha)) {
            return true;
        }
    }
    return false;
}

std::set<DTVehiculoConductor> Conductor::listarVehiculos() {
    std::set<DTVehiculoConductor> result;
    for (Vehiculo* v: vehiculos) {
        result.insert(v->getDTVehiculoConductor());
    }
    return result;
}

Conductor::~Conductor() {}
