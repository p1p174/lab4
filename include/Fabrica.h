#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IUsuario.h"
#include "IViaje.h"
#include "ControladorUsuario.h"
#include "CtrlViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;

    Fabrica();

public:
    static Fabrica* getInstance();

    IControladorFechaActual* getIControladorFechaActual();

    IUsuario* getIUsuario();

    IViaje* getIViaje();
};

#endif
