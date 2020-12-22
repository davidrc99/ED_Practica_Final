#ifndef __PUNTO__
#define __PUNTO__
#include <string>
#include <iostream>
using namespace std;

void QuitaSeparadores(istream &is){
  while(is && (is.peek()=='\t' || is.peek()==' ' || is.peek()=='\n'))
    is.get();
}

class Punto{
private:
  double lat;
  double lng;
  string descripcion;

  void Copiar(const Punto &p){
    lat = p.lat;
    lng = p.lng;
    descripcion = p.descripcion;
  }

public:
  Punto();

  Punto(double lat_n, double lng_n,string des_n)

  Punto(const Punto &p);

  double GetLongitud();

  double GetLatitud();

  string GetDescripcion();

  void SetLongitud(double valor);

  void SetLatitud(double valor);

  void SetDescripcion(string valor);

  Punto & operator=(const Punto &p){
      // if (this!=&p){
      //     Copiar(p);
      // }
      // return *this;
  }

  //Operador ==

  //Operador entrada y Salida (descomentar funcion en pais)

};
#endif
