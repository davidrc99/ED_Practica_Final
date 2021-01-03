#include <iostream>
#include "../include/almacen_rutas.h"
#include "../include/punto.h"
#include "../include/ruta.h"
using namespace std;
Ruta Almacen_rutas::GetRuta(string codigo){
  map<string,Ruta>::iterator it;
  it = rutas.find(codigo);
  return (*it).second;
}

void Almacen_rutas::Insertar(const Ruta &ruta){
  map<string,Ruta>::iterator it;
  it = rutas.find(ruta.GetCodigo());
  if((*it).second!=ruta){
    rutas.insert(pair<string,Ruta>(ruta.GetCodigo(),ruta));
  }else{
    cout << "[ERROR] Ya existe" << endl;
  }
}

list<Ruta> Almacen_rutas::GetRutas(Punto punto){
  list<Ruta> lista_rutas;
  map<string,Ruta>::iterator it;
  for ( it = rutas.begin(); it != rutas.end(); ++it) {
    if((*it).second.estaPunto(punto)){
      lista_rutas.push_back((*it).second);
    }
  }

  return lista_rutas;
}

void Almacen_rutas::Borrar(const string &clave){
  map<string,Ruta>::iterator it;
  it = rutas.find(clave);
  rutas.erase(it);

}

Almacen_rutas & Almacen_rutas::operator=(const Almacen_rutas &Ar){
  if (this!=&Ar){
      rutas = Ar.rutas;
  }
  return *this;
}

void Almacen_rutas::QuitaSeparadores(istream &is){
  while (is &&(is.peek()=='\t'|| is.peek()==' '|| is.peek()=='\n'))
    is.get();
}
