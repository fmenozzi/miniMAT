# miniMAT [![Build Status](https://travis-ci.org/fmenozzi/miniMAT.svg?branch=master)](https://travis-ci.org/fmenozzi/miniMAT)

A small MATLAB interpreter written in C++11 with minimal dependencies

## Building from Source
1. Make sure you have installed the dependencies:
    * A compiler compliant with the C++11 standard (e.g. `g++` 4.8 or `clang++` 3.x)
    * `make`
    * `cmake`
    * `git`
    
2. Download and build miniMAT:

   First, clone the repository (Depending on your network settings, you may have to use the `https` protocol instead of the `git` protocol):

         $ git clone git://github.com/fmenozzi/miniMAT.git
         $ cd miniMAT
        
   Next, we want to make sure that we're using the latest stable release. Use `git tag` to get a list of releases and `git checkout` to switch to the latest tag.
   
   Now, create a build directory. Once inside, simply run `cmake` and `make` to build the project (If you want to do additional configuration with CMake, run `ccmake` instead):

         $ mkdir build && cd build
         $ cmake ..
         $ make
    
3. From the build directory, type `./miniMAT` to launch the REPL

## Current Features
miniMAT aims to be a subset of MATLAB. The features currently supported include:
  * Evaluation of expressions using `+`, `-`, `*`, `/`, `^`, `(`, and `)`
  * Support for floating point numbers in scientific notation (e.g. `0.314159e+1`)
  * Assignment and manipulation of scalars (including the `ans` variable)
  * Assignment and manipulation of matrix literals (e.g. `[1 2 3; a, A(2), A(1,1)]`)
  * Read-only single-value matrix indexing (e.g. `A(2)`, `A(1,1)`)
  * `who` and `whos` to view variables in current scope
  * `clear` to delete variables from the current scope
  * `clc` to clear the console
  * `quit` and `exit` to quit the application
  * REPL and error diagnostic output closely resembling MATLAB output

## Future Features
miniMAT is growing rapidly. Features planned for future releases include:
  * Additional capabilities for matrix manipulation (e.g. transpose, `\` operator, ranges, read-write indexing, etc.)
  * More "standard" functions
  * Command history
  * Scripting
  * GUI
  * And much more

## License
miniMAT is licensed under the [MIT License](http://opensource.org/licenses/MIT)
