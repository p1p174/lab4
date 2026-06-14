#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "Vehiculo.h"
#include "DTVehiculosConductor.h"
#include <set>

//class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::set<Vehiculo*> vehiculos;

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    void addVehiculo(Vehiculo* v);
    bool puedeRegistrar(TipoVehiculo tipo);
    bool hayViajesFechaConductor(DTFecha fecha);
    std::set<DTVehiculosConductor> listarVehiculos();
    bool es_pasajero() override;
    ~Conductor();

    //agrego getter -pia-
    std::set<Vehiculo*> getVehiculos();
    std::set<TipoLibreta> getLibretas();
};

#endif
