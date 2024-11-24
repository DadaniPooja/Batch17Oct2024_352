SRC = ./../src/
OBJ = ./../obj/
BIN = ./../bin/
GFLAGS = gcc
INC = ./../include/
CFLAGS = -c -g -Wall
OFLAGS = -lm -o
IFLAGS = -I./../include/
VFLAGS = v --tool=memcheck --leak-check=yes --show-reachable=yes
EXECS = $(BIN)app


$(BIN)final :$(OBJ)main.o $(OBJ)function.o
	$(GFLAGS) $(OFLAGS)app $(OBJ)main.o $(OBJ)function.o
	mv app $(BIN)

$(OBJ)main.o:$(SRC)main.c $(INC)header.h 
	$(GFLAGS) $(CFLAGS) $(SRC)main.c $(IFLAGS)
	mv main.o $(OBJ)

$(OBJ)function.o:$(SRC)function.c $(INC)header.h
	$(GFLAGS) $(CFLAGS) $(SRC)function.c $(IFLAGS)
	mv function.o $(OBJ)

clean:
	rm $(OBJ)*
	rm $(BIN)app

valgrind:$(EXECS)
	valgrind $(VFLAGS) $(BIN)app
