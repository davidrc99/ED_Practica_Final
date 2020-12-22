#include <iostream>
#include "pais.h"
#include "paises.h"

using namespace std;

void Paises::Insertar(const Pais &P){
  datos.insert(P);
}

void Paises::Borrar(const Pais &P){
  datos.erase(P);
}
