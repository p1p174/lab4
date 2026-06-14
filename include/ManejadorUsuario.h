#ifndef MANEJADOR_USUARIO_H
#define MANEJADOR_USUARIO_H
//#include "Usuario.h"
//#include "Pasajero.h"
//#include "Conductor.h"

#include <string>
#include <map>

class Usuario;
class Pasajero;
class Conductor;

class ManejadorUsuario {
private:
    static ManejadorUsuario* instancia; //es Singleton
    ManejadorUsuario();
    std::map<std::string, Usuario*> usuarios;

public:
    static ManejadorUsuario* getInstance();
    std::map<std::string, Usuario*> getUsuarios();

    bool existeUsuario(std::string nickname);
    Usuario* getUsuario(std::string nickname);
    void addUsuario(Usuario* u);

    std::map<std::string, Pasajero*> getPasajeros();
    Conductor* getConductor(std::string nickname);
    Pasajero* getPasajero(std::string nickname);

    ~ManejadorUsuario();
};

#endif