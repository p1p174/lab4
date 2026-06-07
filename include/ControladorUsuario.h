#ifndef CTRL_USUARIO_H
#define CTRL_USUARIO_H

#include "IUsuario.h"
#include "ManejadorUsuario.h"
#include "ManejadorVehiculo.h"
#include "Pasajero.h"
#include "Vehiculo.h"
#include "Viaje.h"

#include "DTVehiculosConductor.h"
#include "DTUsuario.h"
#include "TipoVehiculo.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include <string>
#include <set>
class Pasajero;
class CtrlUsuario : public IUsuario {
private:
    static CtrlUsuario* instancia; //es Singleton
    std::string nicknameMemoria;
    int codigoMemoria;

    CtrlUsuario();
public:
    static CtrlUsuario* getInstance();

    // métodos heredados de IUsuario
    bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena,
        std::string email, std::string ci) override;

    bool altaConductor(std::string nickname, std::string nombre, std::string contrasena,
        std::string email, std::set<TipoLibreta>libretas) override;

    int registrarVehiculo(std::string nickname, std::string matricula, int capacidad,
        std::string marca, std::string modelo, TipoVehiculo tipo) override;

    std::set<DTVehiculosConductor*> listarVehiculosConductor(std::string nickname) override;
    std::set<DTUsuario*> listarUsuarios() override;
    std::set<DTListarViaje*> listarViajes(std::string nickname) override;
    std::set<DTUsuarioViaje*> listarUsuariosViaje(int codigo) override;

    bool calificarUsuario(std::string nicknameCalificado, std::string calificacion, int puntos) override;

    virtual ~CtrlUsuario();
};

#endif