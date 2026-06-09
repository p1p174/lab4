#include "../include/Pasajero.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena,
    std::string email, std::string documento) : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}
std::string Pasajero::getCi() { return this->ci; }
std::list<Reserva*> Pasajero::getReservas() { return this->reservas; }

void Pasajero::addReserva(Reserva* r) {
    this->reservas.push_front(r);
}
void Pasajero::eliminarReserva(Reserva* r) {
    this->reservas.remove(r);
}

bool Pasajero::tieneReservaEnViaje(Viaje* viaje) {
    if (viaje == NULL){ return false; }
    std::list<Reserva*>& reservas = viaje->getReservas();
    
    // se recorre el conj. de las reservas hechas sobre el viaje
    for (std::list<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
            Pasajero* pa = (*it)->getPasajero(); // pasajero que hizo la reserva
            if (pa->getNickname() == this->getNickname()) {
                return true;
            }
    }
    return false;
}

Pasajero::~Pasajero() {}

bool Pasajero::es_pasajero() { return true; };
