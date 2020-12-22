#ifndef __PUNTO__
#define __PUNTO__
#include <string>
class Punto{
private:
  double lat;
  double lng;
  string descripcion;
public:
  Punto(){
    lat=0;
    lng=0;
    descripcion=" ";
  }

  void funcion_prueba();


};
#endif
