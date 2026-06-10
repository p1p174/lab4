#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "Viaje.h"

class ManejadorViaje{
private:
    static ManejadorViaje* instancia;
    ManejadorViaje();
    Map<int, Viaje> Viajes;
public:
    Viaje* getViaje();
    void addViaje(Viaje* vi);
    set<Viaje*> filtrarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
    ManejadorViaje* getInstance();
    Viaje* create(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0; //abs -definico en viaje- es de clase pq no necesito instnciar un objeto para crearlo




#endif