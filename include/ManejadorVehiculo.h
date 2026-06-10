#ifndef MANEJADOR_VEHICULO_H
#define MANEJADOR_VEHICULO_H
#include "Vehiculo.h"


class ManejadorVehiculo {
    private:
        static ManejadorVehiculo* instancia;
        std::map<std::string, Vehiculo*> vehiculos;

    public:
        bool existeVehiculo(std::string matricula);
        Vehiculo* getVehiculo(std::string matricula);
        void addVehiculo(Vehiculo* v);
        static ManejadorVehiculo* getInstance();
        Vehiculo* getVehiculo(std::string matricula);
};



#endif