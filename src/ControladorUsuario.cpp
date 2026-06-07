#include "../include/ControladorUsuario.h"

CtrlUsuario* CtrlUsuario::instancia = nullptr;
CtrlUsuario::CtrlUsuario() {}

CtrlUsuario* CtrlUsuario::getInstance(){
    if (instancia == nullptr) {
        instancia = new CtrlUsuario();
    }
    return instancia;
}
// Precond: La contrasena tiene al menos 8 caracteres
bool CtrlUsuario::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    ManejadorUsuario* manejadorU = ManejadorUsuario::getInstance();
    if (manejadorU->existeUsuario(nickname)) {
        return false;
    } else {
        //CAMBIANDO EN TipoUsuario Pasajero por Pasajero_ se soluciona
        Pasajero* p = new Pasajero(nickname, nombre, contrasena, email, ci);
        manejadorU->addUsuario(p);
        return true;
    }
}
// Precond: La contrasena tiene al menos 8 caracteres
bool CtrlUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) {
    ManejadorUsuario* manejadorU = ManejadorUsuario::getInstance();
    if (manejadorU->existeUsuario(nickname)) {
        return false;
    } else {
        //CAMBIANDO EN TipoUsuario Pasajero por Pasajero_ se soluciona
        Conductor* p = new Conductor(nickname, nombre, contrasena, email, libretas);
        manejadorU->addUsuario(p);
        return true;
    }
}
// Precond: Existe un conductor c con c.nickname = nickname
int CtrlUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    ManejadorVehiculo* manVehiculo = ManejadorVehiculo::getInstance();
    ManejadorUsuario* manUsuario = ManejadorUsuario::getInstance();
    Conductor conduct = manUsuario->getConductor(nickname);

    std::set<TipoLibreta> libretas = conduct->getLibretas();
    if (manVehiculo->existeVehiculo(matricula)) {
        return -1;
    } else if (tipo=Auto and ( libretas.find(AutoAmateur) == libretas.end() OR 
                libretas.find(AutoProfesional) == libretas.end() )) {
        return -2; //si el vehiculo es un auto y el conductor no tiene libreta para auto
    } else if (tipo=Moto and ( libretas.find(MotoAmateur) == libretas.end() OR 
                libretas.find(MotoProfesional) == libretas.end() )) {
        return -2; //si el vehiculo es una moto y el conductor no tiene libreta para moto
    } else if () {
        Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
        manVehiculo->addVehiculo(v);
        conduct->addVehiculo(v); //agrega el vehículo al la lista de vehiculos del conductor
        return true;
    }
}
// Precond: Existe una instancia de Conductor c con nickname = nickname
std::set<DTVehiculosConductor*> CtrlUsuario::listarVehiculosConductor(std::string nickname) {
    ManejadorUsuario* manUsuario = ManejadorUsuario::getInstance();
    Conductor conduct = manUsuario->getConductor(nickname);
    std::set<Vehiculo*> setVehiculos = conduct->getVehiculos();
    std::set<DTVehiculosConductor*> listaVehi;

    for (std::set<Vehiculo*>::iterator it = setVehiculos.begin(); it != setVehiculos.end(); it++) {
        DTVehiculosConductor* dt = new DTVehiculosConductor(*it->getMatricula(),
            *it->getModelo(), *it->getCapacidad());
        listaVehi.insert(dt);
    }
    return listaVehi;
}
std::set<DTUsuario*> CtrlUsuario::listarUsuarios() {
    ManejadorUsuario* manUsuario = ManejadorUsuario::getInstance();
    std::map<std::string, Usuario*> usuarios = manUsuario->getUsuarios();
    std::set<DTUsuario*> listaUsu;

    for (std::map<std::string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end();
        it++) {
        DTUsuario* dtU = new DTUsuario(it->first, it->second->getNombre());
        listaUsu.insert(dtU);
    }
    return listaUsu;
}
// Precondiciones: Existe una instancia de Usuario u con u.nickname = nickname
// Devuelve la información de viajes relacionados al usuario pasado
std::set<DTListarViaje*> CtrlUsuario::listarViajes(std::string nickname) {
    ManejadorUsuario* manUsuario = ManejadorUsuario::getInstance();
    Usuario user = manUsuario->getUsuario(nickname);
    if (user->es_pasajero()) {
        //es pasajero
        std::list<Reserva*> reservas = user->getReservas;
        for (std::list<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
            Viaje vi = *it->getViaje();
            DTListarViaje* dt = new DTListarViaje(vi->getCodigo(), *it->getFecha(),
                vi->getOrigen(), vi->getDestino(), conductor);
        } /////////FALTA
    }

    return ;
}
std::set<DTUsuarioViaje*> CtrlUsuario::listarUsuariosViaje(int codigo) {
    return ;
}

bool CtrlUsuario::calificarUsuario(std::string nicknameCalificado, std::string calificacion, int puntos) {
    return false;
}

CtrlUsuario::~CtrlUsuario() { }