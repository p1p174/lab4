#ifndef CTRLVIAJE_H
#define CTRLVIAJE_H

#include "IViaje.h"
#include <string>
#include <set>
#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"

#include <string>
#include <set>

class CtrlViaje : public IViaje {
private: 
    int codigoMemoria;
    CtrlViaje(); // constructor privado -sigleton-
    static CtrlViaje* instancia; 

public:
    static CtrlViaje* getInstance(); // si ya existe ctrlViaje lo devuelve, sino lo crea
    ~CtrlViaje() {};

    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
    std::set<std::string> listarPasajeros();
    std::set<DTConsultaViaje*> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
    bool generarReserva(std::string nickname, int codigo, int asientos);
    std::set<DTListarViaje*> listarViajes();
    DTDetalleViaje detalleViaje(int codigo);
    
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif
