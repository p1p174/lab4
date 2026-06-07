#include "../include/Pasajero.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena,
    std::string email, std::string documento) : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}
std::string Pasajero::getCi() { return this->ci; }
std::list<Reserva*> Pasajero::getReservas() { return this->reservas; }

Pasajero::~Pasajero() {}

bool Pasajero::es_pasajero() { return true; };
