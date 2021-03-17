# CPPND: Capstone Snake Game

This is the submission for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The program is an extend of the Snake game provided by Udacitys repo https://github.com/udacity/CppND-Capstone-Snake-Game.

The core modifications of the Snake Game starter code are the following:

### OBJECT ORIENTED
The provided code was already written in an object oriented way, however the Class `Snake` had attributes that where public and thus open to user manipulation. This was changed and all code is now encapsulated.`

### MENU
The main enhancement to the starter project is the addition of a Game Menu. This Game Menu shows up when the user starts the game and consists of three sub menus that have the following capabilities:

The menus allow the user to:
* start the game
* view and reset the previous highscores
* view and change the current game-options
* quit the game

Accessing the **Highscore Menu** allows the user to view the top 5 highscores and reset the highscores. The **Options Menu** accessed through the **Main Menu** allows the user to view the current game-options such as **World Size**, **Snake Speed** and **Snake Speed Increase**.
The Menus are implemented in the Class `Menu` (files: `menu.cpp`, `menu.h`)

### I/O
An other addition to the starter code is the ability to save the top 5 highscores and the game-options that the user manipulated to files on the harddisk. This allows the game to preserve the highscores as well as the options beyond the termination of the program. Whenever some of the data is changed by the user, it is immediately written to disk minimizing the chance of data loss in the case of a program crash. In the process of starting the program the data is automatically loaded into the game.
The reading and writing of the files is implemented in the Class `FileController` (files: `file_controller.cpp`, `file_controller.h`) and the data is stored in the files `options.txt` and `highscores.txt`.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## Project Requirements fullfilled

### Loops, Functions, I/O

**The project reads data from a file and process the data, or the program writes data to a file.**
*The project reads data from an external file or writes data to a file as part of the necessary operation of the program.*
The project was extended to write the game-options and the highscore into files and read it on the start of the program. Class `FileController` is responsible for reading and writing the data to files.

**The project accepts user input and processes the input.**
*The project accepts input from a user as part of the necessary operation of the program.*
By adding the menu to the game the user is able to change some basic settings as well as have a look at the highsores (Class `Menu`).


### Object Oriented Programming

**The project uses Object Oriented Programming techniques.**
*The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.*
The whole project is designed with Object Oriented Programming techniques in mind.

**Classes use appropriate access specifiers for class members.**
*All class data members are explicitly specified as public, protected, or private.*
All new Classes (`Menu`, `FileController`) where designed to meet this criteria. Additionally, all attributes of the Class `Snake` where categorized as private.

**Classes encapsulate behavior.**
*Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.*
As stated in the paragraph above all new Classes (`Menu`, `FileController`) and the attributes of the Class `Snake` where encapsulated so that they can just be accessed just via member functions.
