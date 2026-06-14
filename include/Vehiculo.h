#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include <set>
#include "Viaje.h"
//#include "Conductor.h"
#include "DTVehiculosConductor.h"

class Viaje;
class Conductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

    std::set<Viaje*> viajes;
    Conductor* conductor;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);

    void addViaje(Viaje* v);
    bool hayViajesFecha(DTFecha fecha);
    DTVehiculosConductor getDTVehiculosConductor();
    // bool hayViajesConductor(DTFecha fecha);

    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    std::set<Viaje*> getViajes();
    void agregarViaje(Viaje* v);
    void borrarViaje(Viaje* v);
    Conductor* getConductor();
    void setConductor(Conductor* c);

    ~Vehiculo();
};

#endif
