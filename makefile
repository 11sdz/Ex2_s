CC = gcc
CFLAGS = -Wall
TARGET = main.o my_mat.o my_mat.h

mains: main.o libmatrix.a
	$(CC) $(CFLAGS) -g -o connections main.o ./libmatrix.a -lm
all: mains

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -lm

my_math.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) my_mat.c -lm

libmatrix.a: $(TARGET)
	ar -rcs libmatrix.a my_mat.o

clean: 
	rm -f *.o *.a connections
