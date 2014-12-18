# miniMAT [![Build Status](https://travis-ci.org/fmenozzi/miniMAT.svg?branch=master)](https://travis-ci.org/fmenozzi/miniMAT)

A small MATLAB interpreter written in C++ with minimal dependencies

## Building from Source
1. Make sure you have installed the dependencies:
    * A compiler compliant with the C++11 standard (e.g. `g++` 4.8 or `clang++` 3.x)
    * `make`
    * `cmake`
    * `git`
    * `Eigen3` (`sudo apt-get install libeigen3-dev` will do on Linux systems. See [here](http://eigen.tuxfamily.org/index.php?title=Main_Page) for more information)
    
2. Download and build miniMAT:

    First, clone the repository (Depending on your network settings, you may have to use the `https` protocol instead of the `git` protocol):

        $ git clone git://github.com/fmenozzi/miniMAT.git
        
   Next, we want to make sure that we're using the latest stable release. To do so, run the following commands:
      
        $ cd miniMAT
        $ git describe --abbrev=0 --tags | git checkout

    Now, choose a directory to hold the build. In this example, we'll create a build directory within the repo itself:

        $ mkdir build
        $ cd build
   
   Now, we need to tell CMake where to find Eigen by creating an environment variable that points to the installation directory. On Linux, this can be accomplished with the following command (assuming the default installation directory for Eigen):
         
        $ export EIGEN3_INCLUDE_DIR=/usr/include/eigen3
    
    Once inside your build directory, simply run `cmake` and `make` to build the project (If you want to do additional configuration with CMake, run `ccmake` instead):
    
        $ cmake ..
        $ make

3. From the build directory, type `./miniMAT` to launch the REPL

## Current Features
miniMAT aims to be a subset of MATLAB. Currently, that subset is small, but I'm working on it! The features currently supported include:
  * Evaluation of numeric expressions (using `+`, `-`, `*`, `/`, `^`, `(`, and `)`)
  * Support for floating point numbers in scientific notation (e.g. `0.314159e+1`)
  * Assignment and manipulation of scalars (including the `ans` variable)
  * Assignment and manipulation of matrix literals with literal fields (e.g. `[1 2; 3 4]`)
  * Read-only single-value matrix indexing (e.g. `A(2)`, `A(1,1)`)
  * `who` and `whos` to view variables in current scope
  * `quit` and `exit` to quit the application
  * REPL and error diagnostic output closely resembling MATLAB output

## Future Features
miniMAT is growing rapidly. Features planned for future releases include:
  * Additional capabilities for matrix manipulation (e.g. read-write indexing, ranges)
  * More "standard" functions including `clear`, `clc`, etc.
  * Command history
  * Scripting
  * And much more
