#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/IUsuario.h"
#include "../include/IViaje.h"
#include "../include/IControladorFechaActual.h"
#include "../include/DTFecha.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoVehiculo.h"
#include <iostream>
#include <set>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    
    std::cout << "Cargando datos harcodeados del sistema...\n";
    
    Fabrica* f = Fabrica::getInstance();
    IUsuario* ctrlU = f->getIUsuario();
    IViaje* ctrlV = f->getIViaje();
    IControladorFechaActual* ctrlF = f->getIControladorFechaActual();

    //conductores
    { std::set<TipoLibreta> libs; libs.insert(AutoAmateur);
    ctrlU->altaConductor("mati192", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", libs); }
    { std::set<TipoLibreta> libs; libs.insert(AutoProfesional);
    ctrlU->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", libs); }
    { std::set<TipoLibreta> libs; libs.insert(MotoAmateur);
    ctrlU->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", libs); }
    { std::set<TipoLibreta> libs; libs.insert(MotoProfesional);
    ctrlU->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", libs); }
    { std::set<TipoLibreta> libs; libs.insert(AutoProfesional); libs.insert(MotoAmateur);
    ctrlU->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", libs); }

    //pasajeros
    ctrlU->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    ctrlU->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    ctrlU->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    ctrlU->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    ctrlU->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    //reservas
    ctrlF->setFecha(DTFecha(14,3,2026));
    ctrlV->generarReserva("santi_90", 9, 2);
    ctrlV->generarReserva("mari_b", 9, 1);
    ctrlV->generarReserva("nacho_f", 10, 5);
    ctrlV->generarReserva("valen_uy", 10, 3);
    ctrlV->generarReserva("joaco_r", 10, 1);

    ctrlF->setFecha(DTFecha(13,3,2026));
    ctrlV->generarReserva("mari_b", 12, 1);
    ctrlV->generarReserva("nacho_f", 12, 1);
    ctrlV->generarReserva("nacho_f", 9, 1);

    ctrlF->setFecha(DTFecha(1,6,2026));
    ctrlV->generarReserva("mari_b", 1, 2);

    //calificaciones
    ctrlU->listarViajes("santi_90");
    ctrlU->listarUsuariosViaje(9);
    ctrlU->calificarUsuario("mati192", 4);

    ctrlU->listarViajes("mari_b");
    ctrlU->listarUsuariosViaje(9);
    ctrlU->calificarUsuario("mati192", 4);

    ctrlU->listarViajes("mati192");
    ctrlU->listarUsuariosViaje(9);
    ctrlU->calificarUsuario("mari_b", 3);

    ctrlU->listarViajes("ana_silva");
    ctrlU->listarUsuariosViaje(10);
    ctrlU->calificarUsuario("valen_uy", 5);

    ctrlU->listarViajes("ana_silva");
    ctrlU->listarUsuariosViaje(10);
    ctrlU->calificarUsuario("joaco-r", 5);

    ctrlU->listarViajes("mari_b");
    ctrlU->listarUsuariosViaje(12);
    ctrlU->calificarUsuario("carlos_r", 5);

    ctrlU->listarViajes("carlos_r");
    ctrlU->listarUsuariosViaje(12);
    ctrlU->calificarUsuario("nacho_f", 5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
