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

documentacion:
	echo "Creando la Documentación..."
	doxygen Doxyfile
