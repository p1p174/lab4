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
    std::list<Calificacion*> calificaciones;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();
    std::string getNickname();
    std::string getNombre();
    std::string getContrasena();
    std::string getEmail();
    std::list<Calificacion*> getCalificaciones();
    virtual float getCalificacionPromedio();
    virtual bool es_pasajero();
};

#endif