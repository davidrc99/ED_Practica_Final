#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__
#include "../include/punto.h"
#include "../include/ruta.h"
#include <map>
#include <iostream>
using namespace std;
class Almacen_rutas{
private:
  map<string,Ruta> rutas;
public:
  Almacen_rutas(){}

  Ruta GetRuta(string codigo);
  list<Ruta> GetRutas(Punto punto);
  void Insertar(const string &clave, const Ruta &ruta);
  void Borrar(const string &clave);
  Almacen_rutas & operator=(const Almacen_rutas &Ar);
  friend ostream & operator<<(ostream & os, const Almacen_rutas &Ar){
    map<string,Ruta>::const_iterator it;
    for ( it = Ar.rutas.begin(); it != Ar.rutas.end(); it++) {
      os << it->first << " " << it->second;
      os << endl;
    }

    return os;
  }
  friend istream & operator>>(istream & is, Almacen_rutas &Ar){
    int num_rutas;
    if(!Ar.rutas.empty()){
      Ar.rutas.clear();
    }
    if (is.peek()=='#'){
      string a;
      getline(is,a);
    }
    if (is.peek()=='/'){
      string num_rutas_str;
      is.ignore();
      getline(is,num_rutas_str);
      num_rutas = atoi(num_rutas_str.c_str());
    }
    Ruta R;
    for (int i = 0; i < num_rutas; i++){
        is >> R;
        Ar.Insertar(R.GetCodigo(),R);
    }
    return is;
  }

  //////////////////
  class iterator{
  private:
    map<string,Ruta>::iterator r;
  public:
    iterator(){}
    iterator & operator++(){
      ++r;
      return * this;
    }
    iterator & operator--(){
      --r;
      return * this;
    }

    iterator & operator=(const iterator & it){
      r=it.r;
      return *this;
    }

    bool operator==(const iterator  & it){
      return it.r ==r;
    }

    bool operator!=(const iterator  & it){
      return it.r !=r;
    }

    friend class Almacen_rutas;
    friend class const_iterator;
  };

  iterator begin(){
	  iterator it;
	  it.r = rutas.begin();
	  return it;
	}

  iterator end(){
    iterator it;
    it.r = rutas.end();
    return it;
  }

  iterator find( Ruta &ruta_param){
      iterator it;
      map<string,Ruta>::iterator i;
      for (i=rutas.begin(); i!=rutas.end();++i){
        if(((*i).first==ruta_param.GetCodigo())){
          it.r=i;
        }
      }
      return it;
  }

  class const_iterator{
  private:
    map<string,Ruta>::const_iterator r;
  public:
    const_iterator(){}
    const_iterator(const iterator & it){
      r=it.r;
    }

    const_iterator & operator=(const iterator & it){
      r=it.r;
      return *this;
    }

    const_iterator & operator ++(){
      ++r;
      return * this;
    }
    const_iterator & operator --(){
      --r;
      return * this;
    }
    bool operator ==(const const_iterator  & it){
      return it.r ==r;
    }

    bool operator !=(const const_iterator  & it){
      return it.r !=r;
    }

    friend class Almacen_rutas;
    friend class iterator;
  };

  const_iterator begin()const{
    const_iterator it;
    it.r = rutas.begin();
    return it;
  }

  const_iterator end()const{
    const_iterator it;
    it.r = rutas.end();
    return it;
  }

};
#endif
