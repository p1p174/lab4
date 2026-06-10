#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include <string>
#include <set>
class Reserva; //forward declaration (referencia circular)
class Vehiculo; //idem

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    std::set<Reserva*> reservas; //coleccion de reservas
    Vehiculo* v; //vehiculo q realiza el viaje

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* v);
    ~Viaje();

    bool hayLugar();
    bool cumpleCondiciones(DTFecha fecha, std::string origen, std::string destino);
    bool tieneCupo(int asientos);
    static Viaje* create(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio); // metodo de clase pues no neceito instanciar un objeto de la clase para hacerlo
    
    void addReserva(Reserva* r);
    void eliminarReservas();

    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    std::set<Reserva*> getReservas();
    Vehiculo* getVehiculo();

};

#endif