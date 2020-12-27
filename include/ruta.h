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

    ~Ruta();

    list<Punto> GetListaPuntos();

    string GetCodigo();

    bool estaPunto(const Punto & p);

    bool estaVacia();

    void SetCodigo(const string valor);

    void SetPuntos(const list<Punto> & puntos_n);

    void InsertarPunto(const Punto & p);

    Ruta & operator=(const Ruta &r);

    friend ostream & operator<<(ostream & os, const Ruta & r){
      os << r.codigo << " " << puntos.size() << " ";
      for (list<int>::iterator it = puntos.begin(); it < puntos.end(); ++it) {
        cout << *it << " ";
      }
      cout << endl; ////////////
      return os;
    }

    friend istream & operator>>(istream & is, Ruta & r){
      //R1 5 puntos
      string codigo_n;
      list<Punto> puntos_n;
      int tamanio;
      Punto punto_aux;
      is >> codigo_n >> tamanio;
      puntos_n.resize(tamanio);
      for (int i = 0; i < tamanio; i++) {
        is >> punto_aux;
        puntos_n.push_back(punto_aux);
      }
      r.codigo = codigo_n;
      r.puntos = puntos_n;
      return is;
    }

};
#endif
