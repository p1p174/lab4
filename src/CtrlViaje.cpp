#include "../include/CtrlViaje.h"
#include "../include/ManejadorVehiculo.h"
#include "../include/Vehiculo.h"
#include "../include/ManejadorViaje.h"
#include "../include/Conductor.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Pasajero.h"
#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/DTListarViaje.h"
#include "../include/DTConsultaViaje.h"
#include "../include/DTDetalleViaje.h"
#include "../include/DTDetalleReserva.h"
#include "../include/DTDetalleVehiculo.h"

#include <string>
#include <set>
#include <map>
#include <vector>

CtrlViaje* CtrlViaje::instancia = nullptr; // inicializo la intancia

CtrlViaje::CtrlViaje(){
    this->codigoMemoria = -1;
}

CtrlViaje* CtrlViaje::getInstance(){
    if(instancia == nullptr){
        instancia = new CtrlViaje();
    }
    return instancia;
}

bool CtrlViaje::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    ManejadorVehiculo* mVehiculo = ManejadorVehiculo::getInstance();
    Vehiculo* v = mVehiculo->getVehiculo(matricula);

    if(asientos > v->getCapacidad()){
        return false;
    }

    Conductor* c = v->getConductor();
    if(c->hayViajesFechaConductor(fecha)){
        return false;
    }

    ManejadorViaje* mViaje = ManejadorViaje::getInstance();
    Viaje* vi = mViaje->crearViaje(v,fecha,origen,destino,asientos,precio);
    mViaje->add(vi);
    v->addViaje(vi);

    return true;
}

std::set<std::string> CtrlViaje::listarPasajeros(){
    ManejadorUsuario* mUsuario = ManejadorUsuario::getInstance();
    std::map<std::string, Pasajero*> pasajeros = mUsuario->getPasajeros();

    std::set<std::string> nicknames;
    for(auto& par : pasajeros){
        nicknames.insert(par.first); // par.first tiene el nickname -string-
    }
    return nicknames;
}

std::set<DTConsultaViaje*> CtrlViaje::consultarViajes(DTFecha fecha, std::string origen,std::string destino, int asientos) {
    ManejadorViaje* mViaje = ManejadorViaje::getInstance();
    std::set<Viaje*> viajesFiltrados = mViaje->filtrarViajes(fecha, origen, destino, asientos);
 
    std::set<DTConsultaViaje*> resultado;
    for (Viaje* vi : viajesFiltrados) {
        Vehiculo* v = vi->getVehiculo();
        Conductor* c = v->getConductor();
 
        int codigo = vi->getCodigo();
        std::string marca = v->getMarca();
        std::string modelo = v->getModelo();
        std::string nombre = c->getNombre();
        float calificacionPromedio = c->getCalificacionPromedio();
        float precio = vi->getPrecio() * asientos;

        DTConsultaViaje* dt = new DTConsultaViaje(codigo,marca,modelo,nombre,calificacionPromedio,precio);
        resultado.insert(dt);
    }
    return resultado;
}

bool CtrlViaje::generarReserva(std::string nickname, int codigo, int asientos){
    ManejadorViaje* mViaje = ManejadorViaje::getInstance();
    Viaje* vi = mViaje->getViaje(codigo);

    ManejadorUsuario* mUsuario = ManejadorUsuario::getInstance();
    Pasajero* p = mUsuario->getPasajero(nickname);

    if(vi == nullptr || p == nullptr|| !vi->tieneCupo(asientos) || p->tieneReservaEnViaje(vi)){
        return false;
    }

    DTFecha fechaActual = ControladorFechaActual::getInstance()->getFecha();
    Reserva* r = new Reserva(asientos, fechaActual);

    //asocio la reserva al pasajero y viaje
    vi->addReserva(r);
    p->addReserva(r);

    //asocio pasajero y viaje a la reserva
    r->setViaje(vi);
    r->setPasajero(p);

    return true;
}

std::set<DTListarViaje*> CtrlViaje::listarViajes(){
    ManejadorViaje* mViaje = ManejadorViaje::getInstance();
    std::map<int,Viaje*> viajes = mViaje->getViajes();

    std::set<DTListarViaje*> resultado;
    for(auto& par : viajes){
        Viaje* vi = par.second;
        Vehiculo* v = vi->getVehiculo();
        Conductor* c = v->getConductor();
        
        int codigo = vi->getCodigo();
        DTFecha fecha = vi->getFecha();
        std::string origen = vi->getOrigen();
        std::string destino = vi->getDestino();
        std::string conductor = c->getNickname();

        DTListarViaje* dt = new DTListarViaje(codigo,fecha,origen,destino,conductor);
        resultado.insert(dt);
    }
    
    return resultado;
}

DTDetalleViaje CtrlViaje::detalleViaje(int codigo){
    ManejadorViaje* mViaje = ManejadorViaje::getInstance();
    Viaje* vi = mViaje->getViaje(codigo);

    //int codigo_vi = vi->getCodigo();
    DTFecha fecha = vi->getFecha();
    std::string origen = vi->getOrigen();
    std::string destino = vi->getDestino();
    int asientosPublicados = vi->getAsientosPublicados();
    float precio = vi->getPrecio();

    //contruccion DTDetalleVehiculo
    Vehiculo* v = vi->getVehiculo();
    std::string matricula = v->getMatricula();
    int capacidad = v->getCapacidad();
    std::string marca = v->getMarca();
    std::string modelo = v->getModelo();
    TipoVehiculo tipo = v->getTipo();
    DTDetalleVehiculo dtv = DTDetalleVehiculo(matricula,capacidad,marca,modelo,tipo);

    //construccion DTDetalleReserva
    std::vector<DTDetalleReserva> reservasDT;
    for(Reserva* r : vi->getReservas()){
        int asientosReservados = r->getAsientosReservados();
        DTFecha fecha = r->getFecha();
        Pasajero* pasajero = r->getPasajero();
        std::string nickname_pasajero = pasajero->getNickname();

        DTDetalleReserva dtr = DTDetalleReserva(asientosReservados,fecha,nickname_pasajero);
        reservasDT.push_back(dtr);
    }

    DTDetalleViaje dtvi = DTDetalleViaje(codigo,fecha,origen,destino,asientosPublicados,precio,dtv,reservasDT);
    this->codigoMemoria = codigo; //recuerda el codigo
    return dtvi;
}

void CtrlViaje::eliminarViaje(){
    ManejadorViaje* mViaje = ManejadorViaje::getInstance();
    Viaje* vi = mViaje->getViaje(codigoMemoria);

    //eliminar reservas y sus calificaciones asociadas
    std::set<Reserva*> reservas = vi->getReservas();
    for(Reserva* r : reservas){
        //elimino calificaciones de la reserva
        r->eliminarCalificaciones();
        //desasociar reserva del pasajero
        Pasajero* p = r->getPasajero();
        if(p != nullptr){
            p->eliminarReserva(r);
        }
        delete r;
    }

    //desasociar viaje de vehiculo
    Vehiculo* v = vi->getVehiculo();
    v->borrarViaje(vi);

    //eliminar viaje del manejador
    mViaje->eliminarViaje(vi->getCodigo());

    //borro viaje
    delete vi;

    //limpio codigoMemoria 
    codigoMemoria = -1;
}

void CtrlViaje::cancelarEliminarViaje(){
    codigoMemoria = -1;
}