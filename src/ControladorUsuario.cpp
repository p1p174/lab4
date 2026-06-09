#include "../include/ControladorUsuario.h"

CtrlUsuario* CtrlUsuario::instancia = nullptr;
CtrlUsuario::CtrlUsuario() {}

CtrlUsuario* CtrlUsuario::getInstance() {
    if (instancia == nullptr) {
        instancia = new CtrlUsuario();
    }
    return instancia;
}
std::string CtrlUsuario::getNicknameMemoria() {
    return nicknameMemoria;
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
        Conductor* c = new Conductor(nickname, nombre, contrasena, email, libretas);
        manejadorU->addUsuario(c);
        return true;
    }
}
// Precond: Existe un conductor c con c.nickname = nickname
int CtrlUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    ManejadorVehiculo* manVehiculo = ManejadorVehiculo::getInstance();
    ManejadorUsuario* manUsuario = ManejadorUsuario::getInstance();
    Conductor* conduct = manUsuario->getConductor(nickname);

    std::set<TipoLibreta> libretas = conduct->getLibretas();
    if (manVehiculo->existeVehiculo(matricula)) {
        return -1;
    } else if (tipo==Auto && ( libretas.find(AutoAmateur) == libretas.end() && 
                libretas.find(AutoProfesional) == libretas.end() )) {
        return -2; //si el vehiculo es un auto y el conductor no tiene libreta para auto
    } else if (tipo==Moto && ( libretas.find(MotoAmateur) == libretas.end() && 
                libretas.find(MotoProfesional) == libretas.end() )) {
        return -2; //si el vehiculo es una moto y el conductor no tiene libreta para moto
    } else {
        Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
        manVehiculo->addVehiculo(v);
        conduct->addVehiculo(v); //agrega el vehículo al la lista de vehiculos del conductor
        return 0;
    }
}
// Precond: Existe una instancia de Conductor c con nickname = nickname
std::set<DTVehiculosConductor*> CtrlUsuario::listarVehiculosConductor(std::string nickname) {
    ManejadorUsuario* manUsuario = ManejadorUsuario::getInstance();
    Conductor* conduct = manUsuario->getConductor(nickname);
    std::set<Vehiculo*> setVehiculos = conduct->getVehiculos();
    std::set<DTVehiculosConductor*> listaVehi;

    for (std::set<Vehiculo*>::iterator it = setVehiculos.begin(); it != setVehiculos.end(); it++) {
        DTVehiculosConductor* dt = new DTVehiculosConductor((*it)->getMatricula(),
            (*it)->getModelo(), (*it)->getCapacidad());
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
    Usuario* user = manUsuario->getUsuario(nickname);
    std::set<DTListarViaje*> listaViajes;

    if (user->es_pasajero()) {
        //es pasajero
        std::list<Reserva*>& reservas = user->getReservas();
        for (std::list<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
            Viaje* vi = (*it)->getViaje();
            int codigoVi = vi->getCodigo();
            DTFecha fechaVi = vi->getFecha();
            std::string origenVi = vi->getOrigen();
            std::string destinoVi = vi->getDestino();
            std::string nicknameVi = vi->getVehiculo()->getConductor()->getNickname();
            DTListarViaje* dtV = new DTListarViaje(codigoVi, fechaVi, origenVi, destinoVi, nicknameVi);
            listaViajes.insert(dtV);
        }
    } else {
        std::list<Vehiculo*>& vehiculos = user->getVehiculos();
        for (std::list<Vehiculo*>::iterator it = vehiculos.begin(); it != vehiculos.end(); ++it) {
            std::list<Viaje*>& viajes = (*it)->getViajes();
            for (std::list<Viaje*>::iterator iter = viajes.begin(); iter != viajes.end(); ++iter) {
                int codigoVi = (*iter)->getCodigo();
                DTFecha fechaVi = (*iter)->getFecha();
                std::string origenVi = (*iter)->getOrigen();
                std::string destinoVi = (*iter)->getDestino();
                DTListarViaje* dtV = new DTListarViaje(codigoVi, fechaVi, origenVi, destinoVi, nickname);
                listaViajes.insert(dtV);
            }
        }
    }
    this->nicknameUsuario = nickname; //Se guarda en memoria el nickname pasado por parámetro
    return listaViajes;
}

// ||||||| Creo que listarUsuariosViaje va en CtrlViaje :: |||||||
// Precond:  Existe una instancia de Viaje vi con vi.codigo = codigo
//Devuelve la información de los nicknames y nombre de todos los usuarios relacionados al viaje
std::set<DTUsuarioViaje*> CtrlViaje::listarUsuariosViaje(int codigo) {
    ManejadorViaje* manViaje = ManejadorViaje::getInstance();
    Viaje* viaje = manViaje->getViaje(codigo); // viaje con el código pasado por parámetro
    std::list<Reserva*>& reservas = viaje->getReservas(); // reservas del viaje
    Vehiculo* vehiculo = viaje->getVehiculo(); // vehículo del viaje
    Conductor* conductor = vehiculo->getConductor(); // conductor del viaje
    std::string nicknameMem = getNicknameMemoria(); // nickname en memoria
    std::set<DTUsuarioViaje*> listaUsuariosDelViaje;

    for (std::list<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); it++) {
        Pasajero* pasajero = (*it)->getPasajero();
        std::string nickPasajero = pasajero->getNickname();
        if (nickPasajero != nicknameMem) { //si un usu tiene 2 rservas en 1 viaje aparece 2 veces
            DTUsuarioViaje* dtUV = new DTUsuarioViaje( nickPasajero, TipoUsuario::Pasajero_);
            listaUsuariosDelViaje.insert(dtUV);
        }
    }
    if (conductor->getNickname() != nicknameMem) {
        DTUsuarioViaje* dtUV = new DTUsuarioViaje(conductor->getNickname(), TipoUsuario::Conductor_);
        listaUsuariosDelViaje.insert(dtUV);
    }
    return listaUsuariosDelViaje;
}

// si Juan calificó a Pedro en la reserva r no puede volver a calificar la reserva r otra vez
bool CtrlUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    ManejadorUsuario* manUsuario = ManejadorUsuario::getInstance();
    Usuario* userCador = manUsuario->getUsuario(getNicknameMemoria());
    Usuario* usuCado = manUsuario->getUsuario(nicknameCalificado);
    ManejadorViaje* manViaje = ManejadorViaje::getInstance();
    Viaje* viaje = manViaje->getViaje(getCodigoMemoria());

    std::list<Reserva*>& reservas = viaje->getReservas();
    Reserva* reserv = NULL;
    Reserva* reservUserCador = NULL;
    
    // se recorre el conj. de las reservas hechas sobre el viaje
    for (std::list<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it) {
            Pasajero* pa = (*it)->getPasajero(); // pasajero que hizo la reserva
            if (pa->getNickname() == usuCado->getNickname()) {
                reserv = (*it); //reserva que hizo usuCado en el viaje en cuestión
            }
            if (pa->getNickname() == userCador->getNickname()) {
                reservUserCador = (*it); //reserva que hizo usuCador en el viaje en cuestión
            }
    }
    if (reserv==NULL && reservUserCador==NULL) { return false; }

    Reserva* reservaAVerificar = reserv;
    if (userCador->es_pasajero()) {
        reservaAVerificar = reservUserCador;
    }

    //obtengo las calificaciones hechas sobre la reserva
    std::list<Calificacion*>& calificacionesReserva = reservaAVerificar->getCalificaciones();
    for (std::list<Calificacion*>::iterator it = calificacionesReserva.begin(); it != calificacionesReserva.end(); ++it) {
            Usuario* usu = (*it)->getUsuario(); // usuario que hizo la calificación
            if (usu->getNickname() == userCador->getNickname()) {
                return false; 
                //si userCador ya hizo una calificación sobre la reserva hecha por usuCado
                // entonces no puede hacer otra
            }
    }
    DTFecha fechaActual = IControladorFechaActual::getFecha(); //sería algo así no sé
    Calificacion* cal = new Calificacion(fechaActual, calificacion);
    userCador->agregarCalRealizada(cal);
    usuCado->agregarCalRecibida(cal);

    //linkear la calificación hecha con la reserva
    reservaAVerificar->agregarCalificacion(cal);
    cal->linkearReserva(reservaAVerificar);

    setNicknameMemoria("");
    setCodigoMemoria("");
    return true;
}

CtrlUsuario::~CtrlUsuario() { }