#include "../include/Viaje.h"


ManejadorViaje* ManejadorViaje::instancia = nullptr;

ManejadorViaje::ManejadorViaje();

Viaje* getViaje(codigo: int){
    /*funcion que busque el codigo en el map para devolver el viaje*/
    return 
}

void addViaje(Viaje){
    /*agregarlo al mapa*/
}

set<Viaje*> flitrarViajes(fecha: DTFecha, origen: String, destino: String, asientos: int){
    /*recorre el mapa preguntando si cumple con la fecha/origen/etc y si cumple lo agrega al set*/
}

set<Reserva*> getReservas(){

}

void generarCodigo(){

}

ManejadorViaje getInstance(){
    if (instancia == nullptr){
        instancia = new ManejadorViaje();
    } 
    return instancia;
}

Viaje crearViaje(viaje: Viaje, fecha: DTFecha, origen: String, destino: String, asientos: int, precio: float){

}
