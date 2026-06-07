#include "../include/ManejadorUsuario.h"

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

ManejadorUsuario::~ManejadorUsuario() {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
}