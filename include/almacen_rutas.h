#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__
#include "../include/punto.h"
#include "../include/ruta.h"
#include <map>
#include <iostream>
using namespace std;
class Almacen_rutas{
private:
  map<string,Ruta> rutas;
  map<Punto,list<Ruta> > puntos_enRutas;

public:
  Almacen_rutas(){}

};
#endif
