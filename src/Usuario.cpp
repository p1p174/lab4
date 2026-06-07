#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}
Usuario::~Usuario() {}

std::string Usuario::getNickname() { return this->nickname; }
std::string Usuario::getNombre() { return this->nombre; }
std::string Usuario::getContrasena() { return this->contrasena; }
std::string Usuario::getEmail() { return this->email; }
std::list<Calificacion*> Usuario::getCalificaciones() { return calificaciones; }

float Usuario::getCalificacionPromedio() {
    std::list<Calificacion*> listaCal = getCalificaciones();
    std::list<Calificacion*>::iterator iter = listaCal.begin();
    int suma = 0;
    int cantCals = 0; //cantidad de calificaciones

    while (iter != listaCal.end()) {
        Calificacion* cal = *iter;
        
        int puntaje = cal->getPuntaje();
        suma = suma + puntaje;
        cantCals++;

        iter++;
    }
    if (cantCals == 0) return 0;
    else return suma/cantCals;
}

bool Usuario::es_pasajero() { return false; }