#ifndef __RUTA__
#define __RUTA__
#include "../include/punto.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;
class Ruta{
 private:
   list<Punto> puntos;
   string codigo;

   void Copiar(const Ruta &r){
     puntos = r.puntos;
     codigo = r.codigo;
   }

 public:
    Ruta();

    Ruta(list<Punto> puntos_n, string codigo_n);

    Ruta(const Ruta &r);

    list<Punto> GetListaPuntos();

    string GetCodigo();

    bool estaPunto(const Punto & p);

    bool estaVacia();

    void SetCodigo(const string valor);

    void SetPuntos(const list<Punto> & puntos_n);

    void InsertarPunto(const Punto & p);

    Ruta & operator=(const Ruta &r);

    bool operator==(const Ruta &r)const;

    bool operator!=(const Ruta &r)const;

    friend ostream & operator<<(ostream & os, const Ruta & r){
      // os << r.codigo << " ";
      list<Punto>::const_iterator it;
      for (it = r.puntos.begin(); it != r.puntos.end(); ++it) {
        cout << *it << " ";
      }
      return os;
    }

    friend istream & operator>>(istream & is, Ruta & r){
      string codigo_n;
      list<Punto> puntos_n;
      int tamanio;
      Punto punto_aux;
      is >> codigo_n >> tamanio;
      for (int i = 0; i < tamanio; i++) {
        is >> punto_aux;
        puntos_n.push_back(punto_aux);
      }
      r.codigo = codigo_n;
      r.puntos = puntos_n;
      return is;
    }
    //////////////////
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

      //  const Ruta & operator*()const{
      //    return *r;
      // }
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
