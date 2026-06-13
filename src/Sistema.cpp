#include "../include/Sistema.h"

Fabrica* Fabrica::instancia = nullptr;

Sistema::Sistema() {}

Sistema* Sistema::getInstance() {
    if (instancia == nullptr) {
        instancia = new Sistema();
    }
    return instancia;
}

Fabrica* Sistema::getFabrica(){
    return Fabrica::getInstance();
}