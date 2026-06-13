#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
//#include "Viaje.h"
//#include "Reserva.h"
#include <string>
#include <list>

class Reserva;
class Viaje;

class Pasajero : public Usuario {
private:
    std::string ci;
    std::list<Reserva*> reservas;

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();
    std::string getCi();
    std::list<Reserva*> getReservas();
    void addReserva(Reserva* r);
    void eliminarReserva(Reserva* r);
    bool tieneReservaEnViaje(Viaje* viaje); //devuelve true si el pasajero tiene reserva en el viaje
    bool es_pasajero() override;
};

#endif
