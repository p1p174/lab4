#ifndef USUARIO_H
#define USUARIO_H

#include "Calificacion.h"
#include <string>
#include <list>

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::list<Calificacion*> calRecibidas;
    std::list<Calificacion*> calRealizadas;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();
    std::string getNickname();
    std::string getNombre();
    std::string getContrasena();
    std::string getEmail();
    std::list<Calificacion*> getCalRecibidas();
    std::list<Calificacion*> getCalRealizadas();
    void agregarCalRecibida(Calificacion* cal);
    void borrarCalRecibida(Calificacion* cal);
    void agregarCalRealizada(Calificacion* cal);
    void borrarCalRealizada(Calificacion* cal);
    virtual float getCalificacionPromedio();
    virtual bool es_pasajero() = 0;
};

#endif