#include <iostream>
#include "../include/ruta.h"
#include "../include/punto.h"

Ruta::Ruta(){
  puntos = null;
  codigo = " ";
}

Ruta::Ruta(list<Punto> puntos_n, string codigo_n){
  puntos = puntos_n;
  codigo = codigo_n;
}

Ruta::Ruta(const Ruta &r){
  Copiar(r);
}

Ruta::~Ruta(){
  puntos = null;
  codigo = " ";
}

list<Punto> Ruta::GetListaPuntos(){
  return puntos;
}

string Ruta::GetCodigo(){
  return codigo;
}

bool Ruta::estaPunto(const Punto & p){
  for (list<int>::iterator it = puntos.begin(); it < puntos.end(); ++it) {
    if(*it == p){
      return true;
    }
  }
  return false;
}

void Ruta::SetCodigo(const string valor){
  codigo = valor;
}

void Ruta::SetPuntos(const list<Punto> & puntos_n){
  puntos = puntos_n;
}

void Ruta::InsertarPunto(const Punto & p){
  puntos.push_back(p);
}

Ruta & Ruta::operator=(const Ruta &r){
  if (this!=&r){
      Copiar(r);
  }
  return *this;
}
