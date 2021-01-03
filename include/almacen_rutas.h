/**
  * @file almacen_rutas.h
  * @brief Fichero cabecera para el TDA Almacen Rutas
  * @author Blanca Abril González y David Román Castellano
  */

#ifndef __ALMACEN_RUTAS__
#define __ALMACEN_RUTAS__
#include "../include/punto.h"
#include "../include/ruta.h"
#include <map>
#include <iostream>
using namespace std;


/**
  * @class Almacen_rutas
  * @brief Clase Almance de Rutas, la cual está formada por un mapa de
  * rutas y sus respectivos códigos
  */

class Almacen_rutas{
private:
  map<string,Ruta> rutas; /** Mapa de las rutas del Almacén*/
public:

  /**
    * @brief Constructor por defecto del Almacén de Rutas
  */

  Almacen_rutas(){}

  /**
    * @brief Consulta una ruta específica dado su código identificador
    * @param codigo identificador de la ruta
    * @return Ruta deseada en caso de que exista
  */

  Ruta GetRuta(string codigo);

  /**
    * @brief Consulta las rutas del almacén que pasan por un punto en específico
    * @param punto Punto el cual se desea ver que rutas pasan por él
    * @return lista de rutas que pasan por ese punto
  */

  list<Ruta> GetRutas(Punto punto);

  /**
    * @brief Inserta una ruta en el almacén de rutas
    * @param ruta Ruta la cual se va a insertar en el almacén
  */

  void Insertar(const Ruta &ruta);

  /**
    * @brief Borra una ruta en el almacén de rutas dado su código de identificación
    * @param clave Identificador de la ruta
  */

  void Borrar(const string &clave);

  /**
    * @brief Asignar un Almacén de Rutas
    * @param Ar Almacén de rutas de la que se van a copiar sus atributos
  */

  Almacen_rutas & operator=(const Almacen_rutas &Ar);

  /**
    * @brief Quita separadores
    * @param is los datos de entrada que recibe
  */

  void QuitaSeparadores(istream &is);

  /**
  * @brief Operador que imprime el almacén de rutas por pantalla
    * @param os los datos de salida que imprime
    * @param Ar Almacen de rutas a mostrar por pantalla
  */

  friend ostream & operator<<(ostream & os, const Almacen_rutas &Ar){
    map<string,Ruta>::const_iterator it;
    for ( it = Ar.rutas.begin(); it != Ar.rutas.end(); it++) {
      os << it->first << " " << it->second;
      os << endl;
    }

    return os;
  }

  /**
    * @brief Operador que lee un Almacen de Rutas
    * @param is los datos de entrada
    * @param Ar Almacen de ruta para guardar los parámetros que se lean
  */

  friend istream & operator>>(istream & is, Almacen_rutas &Ar){
    Almacen_rutas arlocal;
    string a;
    is>>a;
    if (a=="#Rutas"){
  Ruta rlocal;
  bool salir=false;
  arlocal.QuitaSeparadores(is);
  while (!salir){
    if (is.peek()!='#' && is){
        is>>rlocal;
        arlocal.Insertar(rlocal);
        arlocal.QuitaSeparadores(is);
    }
    else salir=true;
  }
    }
    Ar=arlocal;
    return is;
  }

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
