#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <set>
#include "DTUsuario.h"
#include "DTVehiculosConductor.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"

class IUsuario {
public:
    virtual bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena,
        std::string email, std::string ci) = 0;
    
    virtual bool altaConductor(std::string nickname, std::string nombre, std::string contrasena,
        std::string email, std::set<TipoLibreta> libretas) = 0;
    
    virtual void registrarVehiculo(std::string nickname, std::string matricula, int capacidad,
        std::string marca, std::string modelo, TipoVehiculo tipo) = 0;

    virtual std::set<DTVehiculosConductor*> listarVehiculosConductor(std::string nickname) = 0;
    virtual std::set<DTUsuario*> listarUsuarios() = 0;
    virtual std::set<DTListarViaje*> listarViajes(std::string nickname) = 0;
    virtual std::set<DTUsuarioViaje*> listarUsuariosViaje(int codigo) = 0;

    virtual bool calificarUsuario(std::string nicknameCalificado, std::string calificacion, int puntos) = 0;

    virtual ~IUsuario() {}
};

#endif