#ifndef __PUNTO__
#define __PUNTO__
#include <string>
#include <iostream>
using namespace std;

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

  void QuitaSeparadores(istream &is){
    while(is && (is.peek()=='\t' || is.peek()==' ' || is.peek()=='\n'))
      is.get();
  }

public:
  Punto();

  Punto(double lat_n, double lng_n,string des_n);

  Punto(const Punto &p);

  double GetLongitud()const;

  double GetLatitud()const;

  string GetDescripcion();

  void SetLongitud(double valor);

  void SetLatitud(double valor);

  void SetDescripcion(string valor);

  Punto & operator=(const Punto &p);

  bool operator==(const Punto &p)const ;

  bool operator!=(const Punto &p)const ;

  friend ostream & operator<<(ostream & os, const Punto & P){
    os << "(" << P.lat << "," << P.lng << ")";
    return os;
  }

  friend istream & operator>>(istream & is, Punto & P){
    string lat,lng;
    string aux;

    getline(is,aux,'(');
    getline(is,lat,',');
    getline(is,lng,')');

    double lat_d = stod(lat);
    double lng_d = stod(lng);
    P.SetLatitud(lat_d);
    P.SetLongitud(lng_d);

    return is;
  }
};
#endif
