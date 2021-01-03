/**
  * @file ruta.h
  * @brief Fichero cabecera para el TDA Ruta
  * @author Blanca Abril González y David Román Castellano
  */

#ifndef __RUTA__
#define __RUTA__
#include "../include/punto.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

/**
  * @class Ruta
  * @brief Clase ruta, la cual está formada por una lista de
  * puntos y un código que la identifica
  *
  */

class Ruta{
 private:
   list<Punto> puntos; /** lista de puntos de la ruta */
   string codigo; /** código que identifica a la Ruta */


   /**
     * @brief Copiar una Ruta
     * @param r ruta de la cual va a ser copiada sus atributos
     */

   void Copiar(const Ruta &r){
     puntos = r.puntos;
     codigo = r.codigo;
   }

 public:

   /**
     * @brief Constructor por defecto de Ruta
     */

    Ruta();

    /**
      * @brief Constructor por parámetros de Ruta
      * @param puntos_n lista de puntos que va a formar la Ruta
      * @param codigo_n código que va a identificar a la Ruta
      */

    Ruta(list<Punto> puntos_n, string codigo_n);

    /**
      * @brief Constructor de copia de Ruta
      * @param r ruta de la cual va a ser copiada sus atributos
      */

    Ruta(const Ruta &r);

    /**
      * @brief Consulta la lista de Puntos que tiene la ruta
      * @return Devuelve una lista de tipo list de la STL de Puntos
      */

    list<Punto> GetListaPuntos();

    /**
      * @brief Consulta el identificador que tiene la ruta
      * @return Devuelve el identificador de la ruta
      */

    string GetCodigo() const;


    /**
      * @brief Consulta si un punto específico se encuentra en la ruta
      * @param p Punto el cual se desea saber si está en la ruta o no
      * @return Devuelve verdadero en caso de que se encuentre el Punto p
      * en la ruta
      */

    bool estaPunto(const Punto & p);

    /**
      * @brief Consulta si la ruta está vacía
      * @return Devuelve verdadero en caso de que la ruta no tenga ningún punto
      */

    bool estaVacia();

    /**
      * @brief Establece el identificador de la ruta
      * @param valor identificador que tendrá la ruta
      */

    void SetCodigo(const string valor);

    /**
      * @brief Establece la lista de puntos de la ruta
      * @param puntos_n lista de puntos que tendrá la ruta
      */

    void SetPuntos(const list<Punto> & puntos_n);

    /**
      * @brief Inserta un punto específico en la ruta
      * @param p Punto específico que será insertado
      */

    void InsertarPunto(const Punto & p);

    /**
      * @brief Asignar una ruta
      * @param r ruta de la que se van a copiar sus atributos
    */

    Ruta & operator=(const Ruta &r);

    /**
      * @brief Comprueba si una ruta es igual a otra
      * @param r ruta a comparar
      * @return devuelve true si las rutas son iguales y false en caso contrario
    */

    bool operator==(const Ruta &r)const;

    /**
      * @brief Comprueba si una ruta es diferente a otra
      * @param r ruta a comparar
      * @return devuelve true si las rutas son diferentes y false en caso contrario
    */

    bool operator!=(const Ruta &r)const;

    /**
      * @brief Quita separadores
      * @param is los datos de entrada que recibe
    */

    void QuitaSeparadores(istream &is);

    /**
      * @brief Operador que imprime una ruta por pantalla
      * @param os datos de salida que imprime
      * @param r ruta a mostrar por pantalla
    */

    friend ostream & operator<<(ostream & os, const Ruta & r){
      list<Punto>::const_iterator it;
      for (it = r.puntos.begin(); it != r.puntos.end(); ++it) {
        cout << *it << " ";
      }
      return os;
    }

    /**
      * @brief Operador que almacena una ruta
      * @param is datos de entrada
      * @param r ruta para almacenar sus parametros
    */

    friend istream & operator>>(istream & is, Ruta & r){
      int tamanio;
      string codigo_n;
      Punto plocal;
      Ruta rlocal;
      is >> codigo_n>> tamanio;
      rlocal.codigo = codigo_n;
      for (int i = 0; i < tamanio; i++) {
        is >> plocal;
        rlocal.puntos.push_back(plocal);
      }
      r=rlocal;
      return is;


    }


    class iterator{
    private:
      list<Punto>::iterator r;
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
      bool operator==(const iterator  & it){
        return it.r ==r;
      }

      bool operator!=(const iterator  & it){
        return it.r !=r;
      }

      iterator & operator=(const iterator & it){
        r=it.r;
        return *this;
      }

      const Punto & operator*(){
        return *r;
     }

      friend class Ruta;
      friend class const_iterator;
    };

    iterator begin(){
  	  iterator it;
  	  it.r = puntos.begin();
  	  return it;
  	}

    iterator end(){
      iterator it;
      it.r = puntos.end();
      return it;
    }

    iterator find(const Punto &r){
        iterator it;
        list<Punto>::iterator i;
        for (i=puntos.begin(); i!=puntos.end() && !((*i)==r);++i);
        it.r=i;
        return it;
    }


    class const_iterator{
    private:
      list<Punto>::const_iterator r;
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

       const Punto & operator*()const{
         return *r;
      }

      friend class Ruta;
      friend class iterator;
    };

    const_iterator begin()const{
      const_iterator it;
      it.r = puntos.begin();
      return it;
    }

    const_iterator end()const{
      const_iterator it;
      it.r = puntos.end();
      return it;
    }

};
#endif
