#include <iostream>
#include "../include/pais.h"
#include "../include/punto.h"
#include "../include/paises.h"

using namespace std;

void Paises::Insertar(const Pais &P){
  datos.insert(P);
}

void Paises::Borrar(const Pais &P){
  datos.erase(P);
}
