# Ant of Life

What would happen if a Langton's ant run on a Conway's Game of life field ?
Let's give a try !

# Features

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

# Use

To compile the project you have to install SFML devellopments headers and dynamic librairies. You should also have a C++11 compiler (only tested with g++ 7.2.0).

For linux users you can then launch the make command in the project folder.

For others I do not really know how to proceed. I you know how to install SFML then use a C++11 compatible compiler to compile all cpp files from the project and then link them to create the final program.

When the program is compiled you can launch it without arguments to show the option list :
```
$ ./AntOfLife
```

# TODO

- [x] Basic Conway's GoL rules
- [x] Loading of a file
- [x] Displaying in real time
- [x] Basic Langton's ant rules
- [x] CLI config (input file, size...)
- [x] Regulated framerate
- [ ] Saving
