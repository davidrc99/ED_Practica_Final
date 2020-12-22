#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__
#include "../include/punto.h"
#include "../include/ruta.h"
class Almacen_rutas{
private:
  map<string,Ruta> rutas;
  map<Punto,list<Ruta> > puntos_enRutas;

public:
  Almacen_rutas(){}
  void funcion_prueba();



};
#endif
