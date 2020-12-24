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

   void Copiar(const Ruta &r);
   void Borrar(const Ruta &r);
 public:
    Ruta();

    Ruta(list<Punto> puntos_n, string codigo_n);

    Ruta(const Ruta &r);

    ~Ruta();

    list<Punto> GetListaPuntos();

    string GetCodigo();

    bool estaPunto(const Punto & p);

    void SetCodigo(const string valor);

    void SetPuntos(const list<Punto> & puntos_n);

    void InsertarPunto(const Punto & p);

    Ruta & operator=(const Ruta &r);

    friend ostream & operator<<(ostream & os, const Ruta & r){}

    friend istream & operator>>(istream & is, Ruta & r){}


};
#endif
