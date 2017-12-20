CC=g++
CFLAGS=-g -Wall
LFLAGS=`pkg-config --libs sfml-graphics`

all : _editor _simulator clean
	
simulator : _simulator clean

editor : _editor clean

_simulator : simulator.o cmd.o window.o map.o ant.o
	g++ window.o map.o simulator.o cmd.o ant.o -o AntOfLife $(LFLAGS)

_editor : editor.o cmd_editor.o window_ed.o map.o
	g++ window_ed.o map.o editor.o cmd_editor.o -o AntOfLifeEditor $(LFLAGS)

simulator.o :
	g++ -c simulator.cpp -o simulator.o $(CFLAGS)

editor.o :
	g++ -c editor.cpp -o editor.o $(CFLAGS)

window.o :
	g++ -c window.cpp -o window.o $(CFLAGS)

window_ed.o :
	g++ -c window.cpp -o window_ed.o -DEDITOR_MODE=1 $(CFLAGS)

map.o :
	g++ -c map.cpp -o map.o $(CFLAGS)

ant.o :
	g++ -c ant.cpp -o ant.o $(CFLAGS)

cmd.o :
	g++ -c cmdline.cpp -o cmd.o $(CFLAGS)

cmd_editor.o :
	g++ -c cmdline_editor.cpp -o cmd_editor.o $(CFLAGS)

clean :
	rm *.o
