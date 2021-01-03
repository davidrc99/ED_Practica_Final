#include "imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;





int main(int argc, char * argv[]){
  if (argc!=4){
    cout<<"Los parametros son :"<<endl;
    cout<<"1.-La imagen de entrada"<<endl;
    cout<<"2.-El angulo de rotación (en grados)"<<endl;
    cout<<"3.-El nombre de la imagen de salida"<<endl;
    return 0;
  }
  Imagen I;
  I.LeerImagen(argv[1]);
  double angulo=atof(argv[2]);
  angulo = angulo*(M_PI)/180; //Pasamos el angulo radianes
  Imagen Iout=Rota(I,angulo);
  Iout.EscribirImagen(argv[3]);

}
