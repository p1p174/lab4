#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "Pasajero.h"
#include <set>

class Viaje; 

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

    Pasajero* pasajero; //pasajero que realizó la reserva
    std::set<Calificacion*> calificaciones; // calificaciones hechas sobre la reserva
    Viaje* viaje; //el viaje al que la reserva está asociado

public:
    Reserva(int asientosReservados, DTFecha fecha);
    int getAsientosReservados();
    DTFecha getFecha();
    Viaje* getViaje();
    Pasajero* getPasajero();
    std::set<Calificacion*> getCalificaciones();
    void agregarCalificacion(Calificacion* cal);
    void eliminarCalificacion(Calificacion* cal);
    void eliminarCalificaciones();
    void setViaje(Viaje*);
    void setPasajero(Pasajero*);
    ~Reserva();
};

#endif
