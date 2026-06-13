#include "../include/ManejadorUsuario.h"
#include "../include/Usuario.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"

ManejadorUsuario* ManejadorUsuario::instancia = nullptr;
ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario* ManejadorUsuario::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}
std::map<std::string, Usuario*> ManejadorUsuario::getUsuarios() {
    return usuarios;
}

bool ManejadorUsuario::existeUsuario(std::string nickname) {
    auto it = this->usuarios.find(nickname);
    return (it != this->usuarios.end());
}

Usuario* ManejadorUsuario::getUsuario(std::string nickname) {
    if (existeUsuario(nickname)) {
        return this->usuarios[nickname];
    } else {
        return nullptr;
    }
}

void ManejadorUsuario::addUsuario(Usuario* usua) {
    this->usuarios[usua->getNickname()] = usua;
}

std::map<std::string, Pasajero*> ManejadorUsuario::getPasajeros() {
    std::map<std::string, Pasajero*> pasajeros;

    for (std::map<std::string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->second->es_pasajero()) {
            pasajeros[it->first] = (Pasajero*)it->second;
        }
    }

    return pasajeros;
}

Conductor* ManejadorUsuario::getConductor(std::string nickname) {
    std::map<std::string, Usuario*>::iterator it = usuarios.find(nickname);
    
    if (!(it->second->es_pasajero())) {
        return (Conductor*)it->second;
    }
    return NULL;
}

ManejadorUsuario::~ManejadorUsuario() {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
}