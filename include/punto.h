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
public:
  Punto(){
    lat=0;
    lng=0;
    descripcion=" ";
  }

  Punto(double lat2, double lng2,string descripcion2){
    lat=lat2;
    lng=lng2;
    descripcion=descripcion2;
  }


};
#endif
