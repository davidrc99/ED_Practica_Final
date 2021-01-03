/**
  * @file ruta.cpp
  * @brief Fichero con definiciones para el TDA Ruta
  *
  * Funciones de la clase Ruta
  *
  */

#include <iostream>
#include "../include/ruta.h"
#include "../include/punto.h"

Ruta::Ruta(){}
// _____________________________________________________________________________
Ruta::Ruta(list<Punto> puntos_n, string codigo_n){
  puntos = puntos_n;
  codigo = codigo_n;
}
// _____________________________________________________________________________
Ruta::Ruta(const Ruta &r){
  Copiar(r);
}
// _____________________________________________________________________________
list<Punto> Ruta::GetListaPuntos(){
  return puntos;
}
// _____________________________________________________________________________
string Ruta::GetCodigo()const{
  return codigo;
}
// _____________________________________________________________________________
bool Ruta::estaPunto(const Punto & p){
  for (list<Punto>::iterator it = puntos.begin(); it != puntos.end(); ++it) {
    if(*it == p){
      return true;
    }
  }
  return false;
}
// _____________________________________________________________________________
bool Ruta::estaVacia(){
  return puntos.empty();
}
// _____________________________________________________________________________
void Ruta::SetCodigo(const string valor){
  codigo = valor;
}
// _____________________________________________________________________________
void Ruta::SetPuntos(const list<Punto> & puntos_n){
  puntos = puntos_n;
}
// _____________________________________________________________________________
void Ruta::InsertarPunto(const Punto & p){
  puntos.push_back(p);
}
// _____________________________________________________________________________
Ruta & Ruta::operator=(const Ruta &r){
  if (this!=&r){
      Copiar(r);
  }
  return *this;
}
// _____________________________________________________________________________
bool Ruta::operator==(const Ruta &r)const{
  if(this->puntos.size() != r.puntos.size() || this->codigo != r.codigo){
    return false;
  }else{
    list<Punto>::const_iterator it1 = this->puntos.begin();
    list<Punto>::const_iterator it2 = r.puntos.begin();

    while(it1 != this->puntos.end() && it2 != r.puntos.end()){
      if(*it1 != *it2){
        return false;
      }else{
        it1++;
        it2++;
      }
    }

    return true;
  }
}
// _____________________________________________________________________________
bool Ruta::operator!=(const Ruta &r)const{
  if(this->puntos.size() != r.puntos.size() || this->codigo != r.codigo){
    return true;
  }else{
    list<Punto>::const_iterator it1 = this->puntos.begin();
    list<Punto>::const_iterator it2 = r.puntos.begin();

    while(it1 != this->puntos.end() && it2 != r.puntos.end()){
      if(*it1 != *it2){
        return true;
      }else{
        it1++;
        it2++;
      }
    }

    return false;
  }
}
// _____________________________________________________________________________
void Ruta::QuitaSeparadores(istream &is){
  while (is &&(is.peek()=='\t'|| is.peek()==' '|| is.peek()=='\n'))
    is.get();
}
