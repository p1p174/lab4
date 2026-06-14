#include "../include/Viaje.h"
#include "../include/Reserva.h"
#include "../include/Vehiculo.h"

//variable estatica para generar coidgos unicos
static int ultimoViaje = 0;

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* v) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->v = v;
}

Viaje::~Viaje() {}

bool Viaje::hayLugar(){
    return tieneCupo(1);
}

bool Viaje::cumpleCondiciones(DTFecha fecha, std::string origen, std::string destino){
    return (this->fecha == fecha && this->origen == origen && this->destino == destino);
}

bool Viaje::tieneCupo(int asientos){
    int totalReservados = 0;
    for(Reserva* r : reservas){ //range-based loops -para cada reserva r en reservas-
        totalReservados += r->getAsientosReservados();  
    }
    return (totalReservados + asientos) <= asientosPublicados;
}

Viaje* Viaje::create(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    ultimoViaje++;
    return new Viaje(ultimoViaje, fecha, origen, destino, asientos, precio,v);
}

void Viaje::addReserva(Reserva* r){
    reservas.insert(r);
}

void Viaje::eliminarReservas(){
    for(Reserva* r : reservas){ //range-based loops -para cada reserva r en reservas-
        delete r;
    }
    reservas.clear();
}

int Viaje::getCodigo(){
    return this->codigo;
}

DTFecha Viaje::getFecha(){
    return this->fecha;
}

std::string Viaje::getOrigen(){
    return this->origen;
}

std::string Viaje::getDestino(){
    return this->destino;
}

int Viaje::getAsientosPublicados(){
    return this->asientosPublicados;
}

float Viaje::getPrecio(){
    return this->precio;
}

std::set<Reserva*> Viaje::getReservas(){
    return this->reservas;
}

Vehiculo* Viaje::getVehiculo(){
    return this->v;
}