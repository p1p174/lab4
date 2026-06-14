#ifndef IVIAJE_H
#define IVIAJE_H

#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
#include <string>
#include <set>

class IViaje {
public:
    virtual ~IViaje() {}

    virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0;
    virtual std::set<std::string> listarPasajeros() = 0;
    virtual std::set<DTConsultaViaje*> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) = 0;
    virtual bool generarReserva(std::string nickname, int codigo, int asientos) = 0;
    virtual std::set<DTListarViaje*> listarViajes() = 0;
    virtual DTDetalleViaje detalleViaje(int codigo) = 0;
    
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
};

#endif