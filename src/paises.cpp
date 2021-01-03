/**
  * @file paises.cpp
  * @brief Fichero con definiciones para el TDA Paises
  *
  * Funciones de la clase Paises
  *
  */

#include <iostream>
#include "../include/pais.h"
#include "../include/punto.h"
#include "../include/paises.h"

using namespace std;
// _____________________________________________________________________________
void Paises::Insertar(const Pais &P){
  datos.insert(P);
}
// _____________________________________________________________________________
void Paises::Borrar(const Pais &P){
  datos.erase(P);
}
