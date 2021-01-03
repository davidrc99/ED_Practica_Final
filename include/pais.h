/**
  * @file pais.h
  * @brief Fichero cabecera para el TDA pais
  * @author Blanca Abril González y David Román Castellano
  */
#ifndef __PAIS__
#define __PAIS__
#include "punto.h"
#include <string>
#include <iostream>
using namespace std;
/**
  * @class Pais
  * @brief Clase Pais, la cual esta formada por un punto, el nombre del país y la bandera asignada.
  */

class Pais{
  private:
    Punto p; /** coordenada donde se encuentra el pais */
    string pais; /** nombre del pais */
    string bandera; /** bandera asignada */

  public:
    /**
      * @brief Constructor por defecto de Pais
    */

    Pais(){}

    /**
     * Obtener las coordenadas del pais
     * @return Devuelve un objeto Punto
     */

    Punto GetPunto()const;

    /**
     * Obtener el nombre del pais
     * @return Devuelve un string con el nombre
     */

    string GetPais()const;

    /**
     * Obtener la bandera del pais
     * @return Devuelve un string con la bandera
     */

    string GetBandera()const;

    /**
     * Operador que ordena alfabeticamente
     * @param P pais a comparar
     * @return Devuelve true si esta alfabeticamente por debajo
     */

    bool operator<(const Pais &P)const;

    /**
     * Operador que compara dos paises
     * @param P pais a comparar
     * @result Devuelve true si son iguales y false en caso contrario
     */

    bool operator==(const Pais &P)const;

    /**
     * Operador que compara dos puntos
     * @param P Punto a comparar
     * @result Devuelve true si son iguales y false en caso contrario
     */

     bool operator==(const Punto &P)const;

     /**
       * @brief Operador que almacena un pais
       * @param is los datos de entrada
       * @param P Pais el cual se va a almacenar sus parametros
     */

    friend istream & operator>>(istream & is, Pais & P){
      double lat,lng;
      is>>lat>>lng>>P.pais>>P.bandera;

      P.p=Punto(lat,lng,"");
      return is;
    }

    /**
      * @brief Operador que imprime un pais por pantalla
      * @param os los datos de salida que imprime
      * @param P Pais a mostrar por pantalla
    */

    friend ostream & operator<<(ostream & os, const Pais &P){
      os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
      return os;
    }
};
#endif
