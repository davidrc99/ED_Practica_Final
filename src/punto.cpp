/**
  * @file punto.cpp
  * @brief Fichero con definiciones para el TDA Punto
  *
  * Funciones de la clase Punto
  *
  */

#include "../include/punto.h"
#include <iostream>
using namespace std;
// _____________________________________________________________________________
Punto::Punto(){
  lat = 0;
  lng = 0;
  descripcion = "";
}
// _____________________________________________________________________________
Punto::Punto(double lat_n, double lng_n,string des_n){
  lat = lat_n;
  lng = lng_n;
  descripcion = des_n;
}
// _____________________________________________________________________________
Punto::Punto(const Punto &p){
  Copiar(p);
}
// _____________________________________________________________________________
double Punto::GetLongitud()const{
  return lng;
}
// _____________________________________________________________________________
double Punto::GetLatitud()const{
  return lat;
}
// _____________________________________________________________________________
string Punto::GetDescripcion(){
  return descripcion;
}
// _____________________________________________________________________________
void Punto::SetLongitud(double valor){
  lng = valor;
}
// _____________________________________________________________________________
void Punto::SetLatitud(double valor){
  lat = valor;
}
// _____________________________________________________________________________
void Punto::SetDescripcion(string valor){
  descripcion = valor;
}
// _____________________________________________________________________________
Punto & Punto::operator=(const Punto &p){
    if (this!=&p){
        Copiar(p);
    }
    return *this;
}
// _____________________________________________________________________________
bool Punto::operator==(const Punto &p)const {
  if(lat==p.lat && lng==p.lng && descripcion==p.descripcion)
    return true;

  return false;
}
// _____________________________________________________________________________
bool Punto::operator!=(const Punto &p)const {
  if(lat==p.lat && lng==p.lng && descripcion==p.descripcion)
    return false;

  return true;
}
