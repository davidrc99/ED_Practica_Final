/**
  * @file pais.cpp
  * @brief Fichero con definiciones para el TDA Pais
  *
  * Funciones de la clase Pais
  *
  */

#include <iostream>
#include "../include/pais.h"
#include "../include/punto.h"


using namespace std;
// _____________________________________________________________________________
Punto Pais::GetPunto()const{
  return p;
}
// _____________________________________________________________________________
string Pais::GetPais()const{
  return pais;
}
// _____________________________________________________________________________
string Pais::GetBandera()const{
  return bandera;
}
// _____________________________________________________________________________
bool Pais::operator<(const Pais &P)const{
  return pais<P.pais;
}
// _____________________________________________________________________________
bool Pais::operator==(const Pais &P)const{
  return pais==P.pais;
}
// _____________________________________________________________________________
bool Pais::operator==(const Punto &P)const{
  return p==P;
}
