CC = gcc
CFLAGS = -c -Wall -g
INCLUDEPATH = ./../include
SRCPATH = ./../src
OBJPATH = ./../obj
BINPATH = ./../bin

$(BINPATH)/exe: $(OBJPATH)/main.o $(OBJPATH)/functions.o
	$(CC) -Wall -g -o exe  $(OBJPATH)/main.o $(OBJPATH)/functions.o
	mv exe $(BINPATH) 

$(OBJPATH)/main.o: $(SRCPATH)/main.c $(INCLUDEPATH)/header.h
	$(CC) $(CFLAGS) $(SRCPATH)/main.c -I $(INCLUDEPATH)/
	mv main.o $(OBJPATH)/

$(OBJPATH)/functions.o: $(SRCPATH)/functions.c $(INCLUDEPATH)/header.h
	$(CC) $(CFLAGS) $(SRCPATH)/functions.c -I $(INCLUDEPATH)/
	mv functions.o $(OBJPATH)/

clear:
	rm $(BINPATH)/exe $(OBJPATH)/main.o $(OBJPATH)/functions.o
