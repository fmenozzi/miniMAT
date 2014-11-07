# miniMAT [![Build Status](https://travis-ci.org/fmenozzi/miniMAT.svg?branch=master)](https://travis-ci.org/fmenozzi/miniMAT)

A small MATLAB interpreter written in C++ with minimal dependencies

## Building from Source
1. Make sure you have installed the dependencies:
    * A compiler compliant with the C++11 standard (e.g. `g++` 4.8 or `clang++` 3.x)
    * `make`
    * `cmake`
    * `git`
2. Download and build miniMAT:

    First, clone the repository (Depending on your network settings, you may have to use the `https` protocol instead of the `git` protocol):

        $ git clone git://github.com/fmenozzi/miniMAT.git

    Now, choose a directory to hold the build. In this example, we'll create a build directory within the repo itself:

        $ cd miniMAT
        $ mkdir build
        $ cd build
    
    Once inside your build directory, simply run `cmake` and `make` to build the project (If you want to do additional configuration with CMake, simply run `ccmake path/to/build` instead):
    
        $ cmake /path/to/build
        $ make

3. From the build directory, type `./miniMAT` to launch the REPL
4. Enjoy!

## Current Features
miniMAT aims to be a subset of MATLAB. Currently, that subset is very small, but I'm working on it! The features currently supported include:
  * Evaluation of numeric expressions (using `+`, `-`, `*`, `/`, `^`, `(`, and `)`)
  * Support for floating point numbers in scientific notation (e.g. `0.314159e+1`)
  * `quit` and `exit` to quit the application
  * REPL and error diagnostic output closely resembling MATLAB output

## Future Features
miniMAT is growing rapidly. Features planned for future releases include:
  * Variable assignment and manipulation
  * Matrix manipulation (obviously)
  * "Standard" functions including `clear`, `clc`, `who`, `whos`, etc.
  * Command history
  * Scripting
  * And much more
