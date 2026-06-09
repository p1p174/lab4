#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include "Viaje.h"

class ManejadorViaje{
private:
    static ManejadorViaje* instancia;
    ManejadorViaje();
    Map<int, Viaje>::Viajes;
public:
    Viaje::getViaje();
    addViaje(Viaje);
    set<Viaje*>::filtrarViajes(fecha: DTFecha, origen: String, destino: String, asientos: int);
    set<Reserva*>::getReservas();
    generarCodigo();
    ManejadorViaje::getInstance();
    Viaje::crearViaje(viaje: Viaje, fecha: DTFecha, origen: String, destino: String, asientos: int, precio: float);
}

#endif