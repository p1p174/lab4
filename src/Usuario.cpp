#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

std::string Usuario::getNickname() { return this->nickname; }
std::string Usuario::getNombre() { return this->nombre; }
std::string Usuario::getContrasena() { return this->contrasena; }
std::string Usuario::getEmail() { return this->email; }
std::list<Calificacion*> Usuario::getCalRecibidas() { return calRecibidas; }
std::list<Calificacion*> Usuario::getCalRealizadas() { return calRealizadas; }

void Usuario::agregarCalRealizada(Calificacion* cal) {
    calRealizadas.push_front(cal);
}
void Usuario::borrarCalRealizada(Calificacion* cal) {
    calRealizadas.remove(cal);
}
void Usuario::agregarCalRecibida(Calificacion* cal) {
    calRecibidas.push_front(cal);
}
void Usuario::borrarCalRecibida(Calificacion* cal) {
    calRecibidas.remove(cal);
}

float Usuario::getCalificacionPromedio() {
    std::list<Calificacion*> listaCal = getCalRecibidas();
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
    if (cantCals == 0) return 5;
    else return suma/cantCals;
}

Usuario::~Usuario() {
    // solo elimina las Calificaciones recibidas
    for (std::list<Calificacion*>::iterator it = calRecibidas.begin(); it != calRecibidas.end(); it++) {
        delete *it;
    }

    calRecibidas.clear();
    calRealizadas.clear();
}