/**
  * @file punto.h
  * @brief Fichero cabecera para el TDA Punto
  * @author Blanca Abril González y David Román Castellano
  *
*/

#ifndef __PUNTO__
#define __PUNTO__
#include <string>
#include <iostream>
using namespace std;

/**
  * @class Punto
  * @brief Clase Punto la cual esta formada por la latitud, la longitud y una breve descripcion.
  *
 */

class Punto{
private:
  double lat; /** latitud del punto */
  double lng; /** longitud del punto */
  string descripcion; /** descripcion del punto */

  /**
    * @brief Copiar un punto
    * @param p punto del que se van a copiar sus atributos
  */

  void Copiar(const Punto &p){
    lat = p.lat;
    lng = p.lng;
    descripcion = p.descripcion;
  }

  /**
    * @brief Quita separadores
    * @param is los datos de entrada que recibe
  */

  void QuitaSeparadores(istream &is){
    while(is && (is.peek()=='\t' || is.peek()==' ' || is.peek()=='\n'))
      is.get();
  }

public:
  /**
    * @brief Constructor por defecto de Punto
  */
  Punto();

  /**
    * @brief Constructor por parametros de Punto
    * @param lat_n latitud
    * @param lng_n longitud
    * @param des_n breve descripcion
  */

  Punto(double lat_n, double lng_n,string des_n);

  /**
    * @brief Constructor de copia de Punto
    * @param p punto del que se van a copiar sus atributos
  */

  Punto(const Punto &p);

  /**
    * @brief Consulta la longitud de un punto
    * @return Devuelve la longitud
  */

  double GetLongitud()const;

  /**
    * @brief Constructor por defecto de Punto
  */

  double GetLatitud()const;

  /**
    * @brief Consulta la descripcion de un punto
    * @return Devuelve la descripcion
  */

  string GetDescripcion();

  /**
    * @brief Establece la longitud de un punto
    * @param valor la longitud a establecer en el punto
  */

  void SetLongitud(double valor);

  /**
    * @brief Establece la latitud de un punto
    * @param valor la longitud a establecer en el punto
  */

  void SetLatitud(double valor);

  /**
    * @brief Establece la descripcion de un punto
    * @param valor la descripcion a establecer en el punto
  */

  void SetDescripcion(string valor);

  /**
    * @brief Asignar un punto
    * @param p punto del que se van a copiar sus atributos
  */

  Punto & operator=(const Punto &p);

  /**
    * @brief Comprueba si un punto es igual a otro
    * @param p punto a comparar
    * @return devuelve true si los puntos son iguales y false en caso contrario
  */

  bool operator==(const Punto &p)const ;

  /**
    * @brief Comprueba si un punto es diferente a otro
    * @param p punto a comparar
    * @return devuelve true si los puntos son diferentes y false en caso contrario
  */

  bool operator!=(const Punto &p)const ;

  /**
    * @brief Operador que imprime un punto por pantalla
    * @param os los datos de salida que imprime
    * @param p punto a mostrar por pantalla
  */

  friend ostream & operator<<(ostream & os, const Punto & P){
    os << "(" << P.lat << "," << P.lng << ")";
    return os;
  }

  /**
    * @brief Operador que almacena un punto
    * @param is los datos de entrada
    * @param p punto para almacenar sus parametros
  */

  friend istream & operator>>(istream & is, Punto & P){
    string lat,lng;
    string aux;

    getline(is,aux,'(');
    getline(is,lat,',');
    getline(is,lng,')');

    double lat_d = stod(lat);
    double lng_d = stod(lng);
    P.SetLatitud(lat_d);
    P.SetLongitud(lng_d);

    return is;
  }
};
#endif
