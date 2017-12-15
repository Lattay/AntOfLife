CC=g++
CFLAGS=-g -Wall
LFLAGS=`pkg-config --libs sfml-graphics`

all : final clean
	
final : main.o window.o map.o
	g++ window.o map.o main.o -o AntOfLife $(LFLAGS)

main.o :
	g++ -c main.cpp -o main.o $(CFLAGS)

window.o :
	g++ -c window.cpp -o window.o $(CFLAGS)


map.o :
	g++ -c map.cpp -o map.o $(CFLAGS)

clean :
	rm *.o
