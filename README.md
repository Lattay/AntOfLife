# Ant of Life

What would happen if a Langton's ant run on a Conway's Game of life field ? The would create a
Let's give a try !

# Use

To compile the project you have to install SFML devellopments headers and dynamic librairies. You should also have a C++11 compiler (only tested with g++ 7.2.0).

For linux users you can then launch the make command in the project folder.

For others I do not really know how to proceed. I you know how to install SFML then use a C++11 compatible compiler to compile all cpp files from the project and then link them to create the final program.

When the program is compiled you can launch it without arguments to show the option list :
```
$ ./AntOfLife
```

# Features

## Graphic UI

The program would be used with a CLI but we want to watch the thing running so I should create a graphic UI based on SFML.

## Loading fields

Conway game of life is interesting because we can build incredible structures within it. Those structures must come from somewere and since I don't want to build an interactive UI the program have to load field files.

## Saving output

It would be nice to save the output of the game. I will see if I can manage to do this.

# TODO

- [x] Basic Conway's GoL rules
- [x] Loading of a file
- [x] Displaying in real time
- [x] Basic Langton's ant rules
- [x] CLI config (input file, size...)
- [x] Regulated framerate
- [ ] Saving
