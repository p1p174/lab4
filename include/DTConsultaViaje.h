#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTConsultaViaje {
private:
  int codigo;
  std::string marca;
  std::string modelo;
  std::string conductor;
  float calificacionProm;
  float precioTotal;

public:
  DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal);

  int getCodigo();
  std::string getMarca();
  std::string getModelo();
  std::string getConductor();
  float getCalificacionProm();
  float getPrecioTotal();

  //agrego definicion del operador <
  bool operator<(const DTConsultaViaje& otro) const {
    if (this->precioTotal != otro.precioTotal)
        return this->precioTotal < otro.precioTotal;
    return this->calificacionProm > otro.calificacionProm;
  }
};

#endif
