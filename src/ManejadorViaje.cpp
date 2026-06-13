#include "../include/ManejadorViaje.h"
#include "../include/Vehiculo.h"

ManejadorViaje* ManejadorViaje::instancia = nullptr;

ManejadorViaje::ManejadorViaje() {}

ManejadorViaje::~ManejadorViaje() {}

ManejadorViaje* ManejadorViaje::getInstance() {
    if (instancia == nullptr) {
        instancia = new ManejadorViaje();
    }
    return instancia;
}

// Agrega un viaje ya creado al map
void ManejadorViaje::add(Viaje* vi) {
    viajes[vi->getCodigo()] = vi;
}

// Crea un nuevo viaje usando el create  de Viaje y lo agrega al map
Viaje* ManejadorViaje::crearViaje(Vehiculo* v, DTFecha fecha, std::string origen,std::string destino, int asientos, float precio) {
    Viaje* vi = Viaje::create(v, fecha, origen, destino, asientos, precio);
    add(vi);
    return vi;
}

// Busca y retorna un viaje por codigo
Viaje* ManejadorViaje::getViaje(int codigo) {
    return viajes[codigo];
}

// Retorna todos los viajes
std::map<int, Viaje*> ManejadorViaje::getViajes() {
    return viajes;
}

// Retorna los viajes que cumplen con las condiciones
std::set<Viaje*> ManejadorViaje::filtrarViajes(DTFecha fecha, std::string origen,std::string destino, int asientos) {
    std::set<Viaje*> resultado;
    for (auto& par : viajes) {
        Viaje* vi = par.second;
        if (vi->cumpleCondiciones(fecha, origen, destino) && vi->tieneCupo(asientos)) {
            resultado.insert(vi);
        }
    }
    return resultado;
}

// Elimina un viaje del map por codigo
void ManejadorViaje::eliminarViaje(int codigo) {
    viajes.erase(codigo);
}