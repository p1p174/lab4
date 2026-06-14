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
    ctrlU->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", libs); }
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

    //vehiculos
    ctrlU->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", Auto);
    ctrlU->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", Auto);
    ctrlU->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", Auto);
    ctrlU->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", Auto);
    ctrlU->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", Moto);
    ctrlU->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", Moto);
    ctrlU->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", Auto);
    ctrlU->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", Moto);

    //viajes
    ctrlV->altaViaje("ABJ4586", DTFecha(21,10,2026), "montevideo", "mercedes", 4, 200);
    ctrlV->altaViaje("ACM4455", DTFecha(20,10,2026), "young", "montevideo", 5, 250);
    ctrlV->altaViaje("BAS7895", DTFecha(20,10,2026), "young", "montevideo", 4, 200);
    ctrlV->altaViaje("BCS4105", DTFecha(21,10,2026), "montevideo", "mercedes", 9, 200);
    ctrlV->altaViaje("LDA4875", DTFecha(21,10,2026), "montevideo", "mercedes", 1, 300);
    ctrlV->altaViaje("PDB1205", DTFecha(21,10,2026), "montevideo", "mercedes", 1, 350);
    ctrlV->altaViaje("SBJ4874", DTFecha(21,10,2026), "montevideo", "mercedes", 4, 260);
    ctrlV->altaViaje("SCF2469", DTFecha(20,10,2026), "montevideo", "cerro chato", 1, 150);
    ctrlV->altaViaje("ABJ4586", DTFecha(15,3,2026), "montevideo", "colonia", 4, 140);
    ctrlV->altaViaje("BCS4105", DTFecha(15,3,2026), "montevideo", "colonia", 9, 180);
    ctrlV->altaViaje("SBJ4874", DTFecha(15,3,2026), "montevideo", "colonia", 1, 100);
    ctrlV->altaViaje("SBJ4874", DTFecha(14,3,2026), "montevideo", "colonia", 4, 600);
    ctrlV->altaViaje("LDA4875", DTFecha(20,10,2026), "young", "montevideo", 1, 250);

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
    {auto tmp = ctrlU->listarViajes("santi_90"); for (auto* p : tmp) delete p;}
    {auto tmp = ctrlU->listarUsuariosViaje(9); for (auto* p : tmp) delete p;}
    ctrlU->calificarUsuario("matil92", 4);

    {auto tmp = ctrlU->listarViajes("mari_b"); for (auto* p : tmp) delete p;}
    {auto tmp = ctrlU->listarUsuariosViaje(9); for (auto* p : tmp) delete p;}
    ctrlU->calificarUsuario("matil92", 4);

    {auto tmp = ctrlU->listarViajes("matil92"); for (auto* p : tmp) delete p;}
    {auto tmp = ctrlU->listarUsuariosViaje(9); for (auto* p : tmp) delete p;}
    ctrlU->calificarUsuario("mari_b", 3);

    {auto tmp = ctrlU->listarViajes("ana_silva"); for (auto* p : tmp) delete p;}
    {auto tmp = ctrlU->listarUsuariosViaje(10); for (auto* p : tmp) delete p;}
    ctrlU->calificarUsuario("valen_uy", 5);

    {auto tmp = ctrlU->listarViajes("ana_silva"); for (auto* p : tmp) delete p;}
    {auto tmp = ctrlU->listarUsuariosViaje(10); for (auto* p : tmp) delete p;}
    ctrlU->calificarUsuario("joaco_r", 5);

    {auto tmp = ctrlU->listarViajes("mari_b"); for (auto* p : tmp) delete p;}
    {auto tmp = ctrlU->listarUsuariosViaje(12); for (auto* p : tmp) delete p;}
    ctrlU->calificarUsuario("carlos_r", 5);

    {auto tmp = ctrlU->listarViajes("carlos_r"); for (auto* p : tmp) delete p;}
    {auto tmp = ctrlU->listarUsuariosViaje(12); for (auto* p : tmp) delete p;}
    ctrlU->calificarUsuario("nacho_f", 5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
