#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "Viaje.h"
#include <map>
#include <set>

class ManejadorViaje{
private:
    static ManejadorViaje* instancia;
    ManejadorViaje();
    std::map<int, Viaje*> Viajes;
public:
    Viaje* getViaje();
    void addViaje(Viaje* vi);
    std::set<Viaje*> filtrarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
    static ManejadorViaje* getInstance();
    virtual Viaje* create(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0; //abs -definico en viaje- es de clase pq no necesito instnciar un objeto para crearlo
};

#endif