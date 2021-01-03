#include "../include/punto.h"
#include <iostream>
using namespace std;

Punto::Punto(){
  lat = 0;
  lng = 0;
  descripcion = "";
}

Punto::Punto(double lat_n, double lng_n,string des_n){
  lat = lat_n;
  lng = lng_n;
  descripcion = des_n;
}

Punto::Punto(const Punto &p){
  Copiar(p);
}

double Punto::GetLongitud()const{
  return lng;
}

double Punto::GetLatitud()const{
  return lat;
}

string Punto::GetDescripcion(){
  return descripcion;
}

void Punto::SetLongitud(double valor){
  lng = valor;
}

void Punto::SetLatitud(double valor){
  lat = valor;
}

void Punto::SetDescripcion(string valor){
  descripcion = valor;
}

Punto & Punto::operator=(const Punto &p){
    if (this!=&p){
        Copiar(p);
    }
    return *this;
}

bool Punto::operator==(const Punto &p)const {
  if(lat==p.lat && lng==p.lng && descripcion==p.descripcion)
    return true;

  return false;
}

bool Punto::operator!=(const Punto &p)const {
  if(lat==p.lat && lng==p.lng && descripcion==p.descripcion)
    return false;

  return true;
}
