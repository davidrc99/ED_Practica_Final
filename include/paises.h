/**
  * @file paises.h
  * @brief Fichero cabecera para el TDA paises
  * @author Blanca Abril González y David Román Castellano
  */

#ifndef __PAISES__
#define __PAISES__
#include "../include/pais.h"
#include "../include/punto.h"
#include <set>
#include <iostream>
using namespace std;

/**
  * @class Paises
  * @brief Clase Paises, la cual está formada por un conjunto de
  * objetos de clase Pais
  */

class Paises{
  private:
    set<Pais> datos;  /**Conjunto de paises*/
  public:

    /**
      * @brief Constructor por defecto de Paises
    */

      Paises(){}

      /**
        * @brief Inserta un país en el conjunto de países
        * @param P Pais el cual se va a insertar en el conjunto
      */

      void Insertar(const Pais &P);

      /**
        * @brief Borra un país del conjunto de países
        * @param P Pais el cual se va a borrar del conjunto
      */

      void Borrar(const Pais &P);
      class const_iterator;

	class iterator{
	private:
	    set<Pais>::iterator p;
	public:
	    iterator(){}
	    iterator & operator ++(){
	      ++p;
	      return * this;
	    }

	    iterator & operator --(){
        --p;
        return * this;
	    }

	    bool operator ==(const iterator  & it){
        return it.p ==p;
	    }

	    bool operator !=(const iterator  & it){
        return it.p !=p;
	    }

	     const Pais & operator*()const{
         return *p;
	    }

	    friend class Paises;
	    friend class const_iterator;
	};


	class const_iterator{
	private:
	    set<Pais>::const_iterator p;
	public:
	    const_iterator(){}
	    const_iterator(const iterator & it){
	      p=it.p;
	    }

      const_iterator & operator=(const iterator & it){
        p=it.p;
        return *this;
	    }
	    const_iterator & operator ++(){
        ++p;
        return * this;
	    }

	    const_iterator & operator --(){
        --p;
        return * this;
	    }
	    bool operator ==(const const_iterator  & it){
        return it.p ==p;
	    }
	    bool operator !=(const const_iterator  & it){
        return it.p !=p;
	    }
	    const Pais &operator*()const {
    	  return *p;
	    }
	    friend class Paises;

	};
	iterator begin(){
	  iterator it;
	  it.p = datos.begin();
	  return it;
	}

	const_iterator begin()const{
	  const_iterator it;
	  it.p = datos.begin();
	  return it;
	}
	iterator end(){
	  iterator it;
	  it.p = datos.end();
	  return it;
	}
	const_iterator end()const{
	  const_iterator it;
	  it.p = datos.end();
	  return it;
	}
	iterator find(const Pais &p){
	    iterator it;
	    set<Pais>::iterator i;
	    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
	    it.p=i;
	    return it;
	}
	iterator find(const Punto &p){
	    iterator it;
	    set<Pais>::iterator i;
	    for (i=datos.begin(); i!=datos.end() && !((*i).GetPunto()==p);++i);
	    it.p=i;
	    return it;
	}

  /**
    * @brief Operador que lee un conjunto de paises
    * @param is los datos de entrada
    * @param R Conjunto de paises el cual se va a guardar los parámetros que se lean
  */

	friend istream & operator>>(istream & is, Paises & R){
    Paises rlocal;
    if (is.peek()=='#'){
      string a;
      getline(is,a);
    }

    Pais P;
    while (is>>P){
      rlocal.Insertar(P);
    }
    R=rlocal;
    return is;
	}

  /**
  * @brief Operador que imprime el conjunto de paises por pantalla
    * @param os los datos de salida que imprime
    * @param R Conjunto de Paises a mostrar por pantalla
  */

	friend ostream & operator<<(ostream & os, const Paises &R){

    Paises::const_iterator it;
      for (it=R.begin(); it!=R.end(); ++it){
        os<<*it<<"\t";
      }
    return os;
	}
};
#endif
