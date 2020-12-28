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
    map<string,Ruta>::iterator it;
    os << "#[CODIGO] [RUTA]" << endl;
    for ( it = Ar.rutas.begin(); it != Ar.rutas.end(); it++) {
      os << it->first << " " << it->second;
      os << endl;
    }

    return os;
  }
  friend istream & operator>>(istream & is, const Almacen_rutas &Ar){
    Almacen_rutas Ar_aux;
    if (is.peek()=='#'){
      string a;
      getline(is,a);
    }
    Ruta R;
    while(is>>R){
      Ar_aux.Insertar(R.GetCodigo(),R);
    }
    Ar =Ar_aux;
    return is;
  }

  //////////////////
  class iterator{
  private:
    map<string,Ruta>::iterator r;
  public:
    iterator(){}
    iterator & operator ++(){
      ++r;
      return * this;
    }
    iterator & operator --(){
      --r;
      return * this;
    }
    bool operator ==(const iterator  & it){
      return it.r ==r;
    }

    bool operator !=(const iterator  & it){
      return it.r !=r;
    }

     const Almacen_rutas & operator*()const{
       return *r;
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

  iterator find(const Ruta &r){
      iterator it;
      map<string,Ruta>::iterator i;
      for (i=rutas.begin(); i!=rutas.end() && !((*i)==r);++i);
      it.r=i;
      return it;
  }

  iterator find(const Punto &r){
      iterator it;
      map<string,Ruta>::iterator i;
      for (i=rutas.begin(); i!=rutas.end() && !((*i)==r);++i);
      it.r=i;
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

     const Almacen_rutas & operator*()const{
       return *r;
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
