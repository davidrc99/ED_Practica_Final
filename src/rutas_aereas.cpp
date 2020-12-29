#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "../include/punto.h"
#include "../include/ruta.h"
#include "../include/paises.h"
#include "../include/imagen.h"
#include "../include/almacen_rutas.h"
using namespace std;

int main(int argc, char * argv[]){
  if (argc!=7){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.-Fichero con la informacion de los paises"<<endl;
      cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
      cout<<"3.-Directorio con las banderas"<<endl;
      cout<<"4.-Fichero con el almacen de rutas"<<endl;
      cout<<"5.- Nombre de la imagen con el avion"<<endl;
      cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;

      return 0;
  }
  ifstream f (argv[1]);
  Almacen_rutas Ar;
  f.close();
   f.open (argv[4]);
  f>>Ar;
  cout<<"Las rutas: "<<endl<<Ar;
}
