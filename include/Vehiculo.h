#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include "Viaje.h"

class Viaje;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

    std::set<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);

    void addViaje(Viaje* v);
    bool hayViajesFecha(DTFecha fecha);
    DTVehiculoConductor getDTVehiculoConductor();
    // bool hayViajesConductor(DTFecha fecha);

    std::string getMatricula();
    std::string getMarca();
    std::string getModelo();
    std::set<Viaje*> getViajes();


    ~Vehiculo();
};

#endif
