BIN = bin
OBJ = obj
SRC = src
INC = include
LIB = lib
FLAGS = -Wall -g -I$(INC) -c

compilador:=g++

all:

clean:
	rm -f $(OBJ)/* $(BIN)/*

rebuild:
	clean $(BIN)/*

mrproper : clean
		-rm $(BIN)/* doc/html/*

documentacion:
	echo "Creando la Documentación..."
	doxygen Doxyfile

#Prueba de Subida
