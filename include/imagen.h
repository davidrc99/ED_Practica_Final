/**
  * @file imagen.h
  * @brief Fichero cabecera para el TDA de imágenes
  * @author Blanca Abril González y David Román Castellano
  */

#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"
#include <cassert>
#include <iostream>
#include <string>
enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;

/**
  * @struct Pixel
  * @brief Struct Pixel el cual está formado por los pixeles RGB
  * y la transparencia.
  *
  */

struct Pixel{
  unsigned char r,g,b;
  unsigned char transp;
};

/**
  * @class Imagen
  * @brief Clase imagen, que está formado por una matriz de píxeles,
  * el número de filas y el número de columnas.
  *
*/

class Imagen{
  private:
    Pixel ** data; // matriz de pixeles
    int nf,nc; // número de filas y columnas

    /**
      * @brief Borrar una imagen
    */

    void Borrar();

    /**
      * @brief Copiar una imagen
      * @param I imagen de la cual se copian sus atributos
    */

    void Copiar(const Imagen &I);

  public:

  /**
    * @brief Constructor por defecto de Imagen
  */
   Imagen();

   /**
     * @brief Constructor por parametros de Imagen
     * @param f filas de la imagen
     * @param c columnas de la imagen
     */

   Imagen(int f,int c);

   /**
     * @brief Constructor por de copia de Imagen
     * @param I imagen de la cual se copian sus atributos
     */

   Imagen(const Imagen & I);

   /**
     * @brief Asignar una imagen
     * @param I imagen de la cual se copian sus atributos
     */

   Imagen & operator=(const Imagen & I);

   /**
     * @brief Destructor de Imagen
     */

   ~Imagen();

   /**
     * @brief Obtiene el pixel dadas unas coordenadas
     * @param i fila
     * @param j columna
     */

   Pixel & operator ()(int i,int j);

   /**
     * @brief Obtiene el pixel dadas unas coordenadas
     * @param i fila
     * @param j columna
     */

   const Pixel & operator ()(int i,int j)const;

   /**
     * @brief Muestra una imagen
     * @param nombre ruta donde se encuentra la imagen
     */

   void EscribirImagen(const char * nombre);

   /**
     * @brief Lee una imagen
     * @param nombre ruta donde se encuentra la imagen
     * @param nombremascara ruta de la máscara
     */

   void LeerImagen (const char *nombre,const string &nombremascara="");

   /**
    * Tranformar una imagen a transparente
    */

   void LimpiarTransp();

  /**
    * @brief Obtener el número de filas de una imagen
    * @return Devuelve el número de filas
    */

   int num_filas()const{return nf;}

   /**
    * @brief Obtener el número de columnas de una imagen
    * @return Devuelve el número de columnas
    */

   int num_cols()const{return nc;}

   /**
    * @brief Pone una imagen en una posición y con pegado Opaco
    * @param posi posición fila donde colocar la imagen
    * @param posj posición columna donde colocar la imagen
    * @param I imagen que queremos situar
    *tippegado tipo de pegado, puede ser OPACO o BLENDING
    */

   void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

   /**
    @brief Extraer una imagen segun su posición y dimensiones
    @param posi posición fila donde extraer la imagen
    @param posj posición columna donde extraer la imagen
    @param dimi dimensión fila donde extraer la imagen
    @param dimj dimensión columna donde extraer la imagen
    @return Devuelve una imagen
    */

   Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);
};

#endif
