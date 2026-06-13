#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Reserva;
class Usuario;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Reserva* reserva;
    Usuario* usuario;

public:
    Calificacion(DTFecha fecha, int puntaje, Usuario* u);
    ~Calificacion();

    DTFecha getFecha();
    int getPuntaje();
    Reserva* getReserva();
    Usuario* getUsuario();
    void linkearReserva(Reserva* r);
};

#endif
