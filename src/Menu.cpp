#include "../include/Menu.h"
#include "../include/Sistema.h"
#include "../include/IControladorFechaActual.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include <iostream>
#include <limits>
#include <string>

void Menu::altaUsuario() {

    Fabrica* fabrica = Fabrica::getInstance();
    IUsuario* ctrlU = fabrica->getIUsuario();

    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);


    bool usuarioOk = false;

    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        usuarioOk = ctrlU->altaPasajero(nickname, nombre, contrasena, email, ci);
        //agrego esto. que les parece?
        if (usuarioOk) {
            std::cout << "Pasajero registrado exitosamente.\n";
        } else {
            std::cout << "No se pudo registrar el pasajero. Ya existe un usuario con ese nickname.\n";
        }
    } else if (tipoUsuario == 2) {
        usuarioOk = ctrlU->altaConductor(nickname, nombre, contrasena, email, libretas);
        if (usuarioOk) {
            std::cout << "Conductor registrado exitosamente.\n";
        } else {
            std::cout << "No se pudo registrar el conductor. Ya existe un usuario con ese nickname.\n";
        }
        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int resultadoRegistrarVehiculo = -3;
            if (tipo == 0) {
                resultadoRegistrarVehiculo = ctrlU->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, TipoVehiculo::Auto);

            } else if (tipo == 1) {
                resultadoRegistrarVehiculo = ctrlU->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, TipoVehiculo::Moto);
            } else {
                std::cout << "Tipo de vehiculo invalido.\n";
                continue;
            }
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::altaViaje() {
    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);
    //obtengo interfaz correspondiente
    IUsuario* ctrlUsuario = Fabrica::getInstance()->getIUsuario();
    //TODO: Coleccion de DTVehiculosConductor = controlador->listarVehiculosConductor(nickname)
    std::set<DTVehiculosConductor*> vehiculosConductor = ctrlUsuario->listarVehiculosConductor(nickname);
    //TODO: Recorrer la coleccion y mostrar "> Matricula: xx, Capacidad: yy, Marca: zzz, Modelo: www, Tipo: ttt"
    //todo de arriba mal redactado: solo mostrar "> Matricula: xx, Modelo: yy, Capacidad: zz"
    for(DTVehiculosConductor* it : vehiculosConductor){
        std::cout << "> Matricula: " << it->getMatricula() << ", Modelo: " << it->getModelo() << ", Capacidad: " << it->getCapacidad() << std::endl;
    }

    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);
    bool matriculaValida = false;
    //TODO: Validar matricula en listado
    for(DTVehiculosConductor* it : vehiculosConductor){
        if(it->getMatricula() == matricula){
            matriculaValida = true;
        }
    }
    if (!matriculaValida) {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool viajeOk = false;
    //obtengo interfaz correspondiente
    IViaje* ctrlViaje = Fabrica::getInstance()->getIViaje();
    //TODO: viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio)
    viajeOK = ctrlViaje->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);
    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
    //TODO: Colecion de String = controlador->listarPasajeros()
    //TODO: Recorrer la colección y mostrar "> xx"
    std::set<std::string> pasajeros = CtrlViaje->listarPasajeros();
    for (std::set<std::string>::iterator i = pasajeros.begin(); i != pasajeros.end(); i++){
        std::cout << "> " << *i << "\n";
    };
    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    bool nicknameValido = false;
    //TODO: Validar nickname en listado
    for (std::set<std::string>::iterator i = pasajeros.begin(); i != pasajeros.end(); i++){
        if (*i == nickname){ 
            nicknameValido = true;
            break;
        };
    };

    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //TODO: Coleccion de DTConsultaViaje = controlador->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos)
    //TODO: Recorrer la coleccion y mostrar: "> Codigo: xx, Marca: yy, Modelo: zzz, Conductor: aaa, CalificacionPromedio: qqq, PrecioTotal: eee"
    std::set<DTConsultaViaje> consViaje = CtrlViaje->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);
    for (std::set<std::DTCondutlaViaje>::iterator i = consViaje.begin(); i != consViaje.end(); i++){
        std::cout << "> Codigo: ", i->getCodigo()
                  << ", Marca: ", i->getMarca()
                  << ", Modelo: ", i->getModelo()
                  << ", Conductor: ", i->getConductor()
                  << ", CalificacionPromedio", i->getCalificacionProm()
                  << ", PrecioTotal: ", i->getPrecioTotal() << "\n";
    } 
    
    bool hayViajes = false;//TODO: Validar coleccion vacía

    if (!consViaje.empty()){
        hayViajes = true;
    }

    if (!hayViajes) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    //TODO: Validar codigo en listado
    for(std::set<DTConsultaViaje>::iterator i = consViaje.begin(); i != consViaje.end(), i++){
        if (i->getCodigo() == codigo){
            codigoValido = true;
            break;
        }
    }

    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = false;
    //TODO: reservaOk = controlador->generarReserva(nickname, codigo, asientos)
    reservaOk = CtrlViaje->generarReserva(nickname, codigo, asientos);
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
    Fabrica* fabrica = Sistema::getInstance()->getFabrica();
    IUsuario* instIUsuario = fabrica->getIUsuario();
    IViaje* instIViaje = fabrica->getIViaje();

    //TODO:DTUsuario = controlador->listarUsuarios()
    std::set<DTUsuario*> conjUsu = instIUsuario->listarUsuarios();
    //TODO: Recorrer la coleccion std::set<DTUsuario*> conjUsuarios y mostrar "> Nickname: xx, Nombre: yyy"
    for (std::set<DTUsuario*>::iterator it = conjUsu.begin(); it != conjUsu.end(); ++it) {
        DTUsuario* u = *it;
        std::cout << "> Nickname: " << u->getNickname() << ", Nombre: " << u->getNombre() << std::endl;
    }////
    
    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    bool nicknameValido = false;
    //TODO: Validar nickname en listado
    for (std::set<DTUsuario*>::iterator it = conjUsu.begin(); it != conjUsu.end(); ++it) {
        DTUsuario* u = *it;
        if (u->getNickname() == nickname) {
            nicknameValido = true; // si está el nickname en el listado es válido
            break;
        }
    } /////
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    //TODO: Coleccion de DTListarViaje = controlador->listarViajes(nickname)
    std::set<DTListarViaje*> cjViajes = instIUsuario->listarViajes(nickname);
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    for (std::set<DTListarViaje*>::iterator it = cjViajes.begin(); it != cjViajes.end(); ++it) {
        DTListarViaje* viaje = *it;
        std::cout << "> Codigo: " << viaje->getCodigo()
              << ", Fecha: " << viaje->getFecha()
              << ", Origen: " << viaje->getOrigen()
              << ", Destino: " << viaje->getDestino()
              << ", Conductor: " << viaje->getConductor()
              << std::endl;
    }
    ////////
    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    //TODO: Validar codigo en listado
    for (std::set<DTListarViaje*>::iterator it = cjViajes.begin(); it != cjViajes.end(); ++it) {
        DTListarViaje* viaje = *it;
        if (viaje->getCodigo() == codigo) {
            codigoValido = true; // si está el código en el listado es válido
            break;
        }
    }
    //////////////////
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    //TODO: Coleccion de DTUsuarioViaje = Controlador->listarUsuariosViaje(codigo)
    std::set<DTUsuarioViaje*> conjUV = instIUsuario->listarUsuariosViaje(codigo);
    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Tipo: yyy"
    for (std::set<DTUsuarioViaje*>::iterator it = conjUV.begin(); it != conjUV.end(); ++it) {
        DTUsuarioViaje* uv = *it;
        std::cout << "> Nickname: " << uv->getNickname() << ", Tipo: " << uv->getTipo() << std::endl;
    }
    ///////
    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool nicknameCalificadoValido = false;
    //TODO: Validar nickname en listado
    for (std::set<DTUsuarioViaje*>::iterator it = conjUV.begin(); it != conjUV.end(); ++it) {
        DTUsuarioViaje* uv = *it;
        if (uv->getNickname() == nicknameCalificado) {
            nicknameCalificadoValido = true; // si está el nickname en el listado es válido
            break;
        }
    }
    //////

    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = false;
    //TODO: calificacionOk = Controlador->calificarUsuario(nicknameCalificado, calificacion)
    calificacionOk = instIUsuario->calificarUsuario(nicknameCalificado, calificacion);
    //////
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {
    Fabrica* fabrica = Fabrica::getInstance();
    IViaje* ctrlV = fabrica->getIViaje();

    std::set<DTListarViaje*> viajes = ctrlV->listarViajes();
    for (DTListarViaje* v : viajes) {
        std::cout << "> Codigo: " << v->getCodigo()
                << ", Fecha: " << v->getFecha()
                << ", Origen: " << v->getOrigen()
                << ", Destino: " << v->getDestino()
                << ", Conductor: " << v->getConductor() << "\n";
    }
    
    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    for (DTListarViaje* v : viajes) {
        if (v->getCodigo() == codigo) {
            codigoValido = true;
            break;
        }
    }
    for (DTListarViaje* v : viajes) {
        delete v;
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    DTDetalleViaje* detalle = ctrlV->detalleViaje(codigo);

    std::cout << ">> Viaje <<\n";
    std::cout << "--- Codigo: " << detalle->getCodigo()
            << ", Fecha: " << detalle->getFecha()
            << ", Origen: " << detalle->getOrigen()
            << ", Destino: " << detalle->getDestino()
            << ", AsientosPublicados: " << detalle->getAsientosPublicados()
            << ", Precio por asiento: " << detalle->getPrecio() << "\n";
            
    std::cout << ">> Vehiculo <<\n";
    DTDetalleVehiculo dv = detalle->getVehiculo();
    std::cout << "--- Matricula: " << dv.getMatricula()
            << ", Capacidad: " << dv.getCapacidad()
            << ", Marca: " << dv.getMarca()
            << ", Modelo: " << dv.getModelo()
            << ", Tipo: " << (dv.getTipo() == Auto ? "Auto" : "Moto") << "\n";

        std::cout << ">> Reservas <<\n";
        for (DTDetalleReserva& dr : detalle->getReservas()) {
            std::cout << "--- AsientosReservados: " << dr.getAsientosReservados()
                    << ", Fecha: " << dr.getFecha()
                    << ", Pasajero: " << dr.getPasajero() << "\n";
        }
    delete detalle;

    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        ctrlV->eliminarViaje();
        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
        ctrlV->cancelarEliminarViaje();
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
