#include "../include/Conductor.h"
#include "../include/TipoVehiculo.h"
#include "../include/TipoLibreta.h"
#include "../include/Usuario.h"
#include "../include/DTVehiculosConductor.h"
#include "../include/Viaje.h"

#include <set>

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

//agrego getter -pia-
std::set<Vehiculo*> getVehiculos(){
    return this->vehiculos;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    std::set<Vehiculo*> vehiculos = getVehiculos();
    for (Vehiculo* v: vehiculos) {
        if (v->hayViajesFecha(fecha)) {
            return true;
        }
    }
    return false;
}

std::set<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::set<DTVehiculosConductor> result;
    std::set<Vehiculo*> vehiculos = getVehiculos();
    for (Vehiculo* v: vehiculos) {
        result.insert(v->getDTVehiculosConductor());
    }
    return result;
}

Conductor::~Conductor() {}
