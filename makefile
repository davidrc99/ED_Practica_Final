BIN = bin
OBJ = obj
SRC = src
INC = include
LIB = lib
DATOS = datos
FLAGS = -Wall -g -I$(INC) -c

compilador:=g++

main: $(BIN)/rutas_aereas
	./$(BIN)/rutas_aereas ./$(DATOS)/paises.txt ./$(DATOS)/imagenes/mapas/mapa1.ppm  ./$(DATOS)/imagenes/banderas ./$(DATOS)/almacen_rutas.txt ./$(DATOS)/imagenes/aviones/avion2.ppm ./$(DATOS)/imagenes/aviones/macara_avion2.pgm

$(BIN)/rutas_aereas: $(OBJ)/rutas_aereas.o $(LIB)/libfunciones.a
	$(compilador) -o $@ $< -lfunciones -L$(LIB)

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp $(INC)/almacen_rutas.h $(INC)/ruta.h $(INC)/imagen.h $(INC)/paises.h $(INC)/punto.h $(INC)/pais.h
	$(compilador) $(FLAGS) $< -o $@

$(LIB)/libfunciones.a: $(OBJ)/imagen.o $(OBJ)/almacen_rutas.o $(OBJ)/ruta.o $(OBJ)/paises.o $(OBJ)/pais.o $(OBJ)/punto.o  $(OBJ)/imagenES.o
	ar -rvs $@ $^

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(compilador) $(FLAGS) $< -o $@

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(compilador) $(FLAGS) $< -o $@

$(OBJ)/almacen_rutas.o: $(SRC)/almacen_rutas.cpp $(INC)/almacen_rutas.h $(INC)/ruta.h
	$(compilador) $(FLAGS) $< -o $@

$(OBJ)/paises.o: $(SRC)/paises.cpp $(INC)/paises.h $(INC)/pais.h
	$(compilador) $(FLAGS) $< -o $@

$(OBJ)/ruta.o: $(SRC)/ruta.cpp $(INC)/ruta.h $(INC)/punto.h
	$(compilador) $(FLAGS) $< -o $@

$(OBJ)/pais.o: $(SRC)/pais.cpp $(INC)/pais.h $(INC)/punto.h
	$(compilador) $(FLAGS) $< -o $@

$(OBJ)/punto.o: $(SRC)/punto.cpp $(INC)/punto.h
	$(compilador) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)/* $(BIN)/*

rebuild:
	clean $(BIN)/*

mrproper : clean
		-rm $(BIN)/* doc/html/*

documentacion:
	echo "Creando la Documentación..."
	doxygen Doxyfile
