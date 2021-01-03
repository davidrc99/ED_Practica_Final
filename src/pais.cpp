#include <iostream>
#include "../include/pais.h"
#include "../include/punto.h"


using namespace std;

Punto Pais::GetPunto()const{
  return p;
}

string Pais::GetPais()const{
  return pais;
}

string Pais::GetBandera()const{
  return bandera;
}

bool Pais::operator<(const Pais &P)const{
  return pais<P.pais;
}

bool Pais::operator==(const Pais &P)const{
  return pais==P.pais;
}

bool Pais::operator==(const Punto &P)const{
  return p==P;
}
