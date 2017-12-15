CC=g++
CFLAGS=-g -Wall
LFLAGS=`pkg-config --libs sfml-graphics`

all : final clean
	
final : main.o cmd.o window.o map.o ant.o
	g++ window.o map.o main.o cmd.o ant.o -o AntOfLife $(LFLAGS)

main.o :
	g++ -c main.cpp -o main.o $(CFLAGS)

window.o :
	g++ -c window.cpp -o window.o $(CFLAGS)

map.o :
	g++ -c map.cpp -o map.o $(CFLAGS)

ant.o :
	g++ -c ant.cpp -o ant.o $(CFLAGS)

cmd.o :
	g++ -c cmdline.cpp -o cmd.o $(CFLAGS)

clean :
	rm *.o
