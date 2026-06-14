#ifndef MANEJADOR_VEHICULO_H
#define MANEJADOR_VEHICULO_H
#include "Vehiculo.h"
#include <map>
#include <string>

class ManejadorVehiculo {
    private:
        static ManejadorVehiculo* instancia;
        std::map<std::string, Vehiculo*> vehiculos;

    public:
        bool existeVehiculo(std::string matricula);
        Vehiculo* getVehiculo(std::string matricula);
        void addVehiculo(Vehiculo* v);
        static ManejadorVehiculo* getInstance();
        ~ManejadorVehiculo();
};



#endif