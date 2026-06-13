#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "Viaje.h"
#include "DTFecha.h"
#include <map>
#include <set>
#include <string>

class Vehiculo;

class ManejadorViaje {
private:
    static ManejadorViaje* instancia;
    ManejadorViaje();
    std::map<int, Viaje*> viajes;

public:
    static ManejadorViaje* getInstance();

    void add(Viaje* vi);
    Viaje* crearViaje(Vehiculo* v, DTFecha fecha, std::string origen,std::string destino, int asientos, float precio);
    Viaje* getViaje(int codigo);
    std::map<int, Viaje*> getViajes();
    std::set<Viaje*> filtrarViajes(DTFecha fecha, std::string origen,std::string destino, int asientos);
    void eliminarViaje(int codigo);

    ~ManejadorViaje();
};

#endif