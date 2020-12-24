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
  copiar(p);  //Implementar
}

double Punto::GetLongitud(){
  return lng;
}

double Punto::GetLatitud(){
  return lat;
}

string Punto::GetDescripcion(){
  return descripcion;
}

void Punto::SetLongitud(double valor){
  lng = valor;
}

void Punto::SetLatitud(double valor){
  lng = lat;
}

void Punto::SetDescripcion(string valor){
  descripcion = valor;
}
