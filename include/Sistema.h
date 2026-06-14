#ifndef SISTEMA_H
#define SISTEMA_H

#include "Fabrica.h"

class Sistema {
private:
    static Sistema* instancia;

    Sistema();

public:
    static Sistema* getInstance();

    Fabrica* getFabrica();

};

#endif
