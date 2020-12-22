#ifndef __PAIS__
#define __PAIS__
#include "punto.h"
class Pais{
  private:
    Punto p;
    string pais;
    string bandera;

  public:
    Pais(){}
    Punto GetPunto()const;
    string GetPais()const;
    string GetBandera()const;

    bool operator<(const Pais &P)const;

    bool operator==(const Pais &P)const;

     bool operator==(const Punto &P)const;

    friend istream & operator>>(istream & is, Pais & P){
      double lat,lng;
      is>>lat>>lng>>P.pais>>P.bandera;

      P.p=Punto(lat,lng,"");
      return is;
    }

    friend ostream & operator<<(ostream & os, const Pais &P){
      os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
      return os;
    }
};
#endif
