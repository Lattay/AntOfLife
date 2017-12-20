# Ant of Life

What would happen if a Langton's ant run on a Conway's Game of life field ?
Let's give a try !

# Features

## Simulator
This programm is able to run three types of simulations :
- the original Conway's game of life
- the original Langton's ant
- a hybrid simulation where cells obey to Conway's rules but there is a Langton's ant running on top of it.

These simulations are displayed in a window created with the SFML librairy.
The window automatically take a size that should fit a resolution around 1300x800.

Command line argument allow the user to :
- selecting one of the tree simulation
- specify a file to build the map
- specify the size (in pixel) of cells
- use a random generated map, specifing the proportion of living cells and the size of the map
- specify the minimum time between two refreshing (in millisecond)

## Editor
This programm allow you to create or modify map files.
The map is displayed just as it would be in simulator. Cells can be switched by left-clicking it.

Command line argument allow the user to :
- create a new map of arbitrary size (in cells)
- specify the size (in pixel) of cells
- open existing file to be modified
- save map to a file

# Use

To compile the project you have to install SFML devellopments headers and dynamic librairies. You should also have a C++11 compiler (only tested with g++ 7.2.0).

For linux/unix users you can then launch the `make` command in the project folder. It would create AntOfLife (simulator) and AntOfLifeEditor (editor) executable.
To compile only one of the two programe you can use the `make simulator` or `make editor` commands.

For others I do not really know how to proceed. I would be glad to know the best way to compile it under Windows and MacOS.

When the simulator is compiled you can launch it without arguments to show the option list :
```
$ ./AntOfLife
```

It is the same for the editor :
```
$ ./AntOfLifeEditor
```

# TODO

- [x] Basic Conway's GoL rules
- [x] Loading of a file
- [x] Displaying in real time
- [x] Basic Langton's ant rules
- [x] CLI config (input file, size...)
- [x] Regulated framerate
- [ ] Saving
- [ ] Creation of a map editor
- [ ]
