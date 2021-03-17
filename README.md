# CPPND: Capstone Snake Game

This is the submission for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The program is an extend of the Snake game provided by Udacitys repo https://github.com/udacity/CppND-Capstone-Snake-Game.

The core modifications are the following

Object Oriented
The provided code was already written in an object oriented way, however the class Snake had attributes that wehere not encapsulated and thus open to user manipulation. This was changed and all Code is now encasulated.

MENU
The main enhancment to the project is the addition of a Game menu, that shows up when the user starts the game. The Menu consists of three submenus that have the following possibilities:

The menues allow the user to
* start the game,
* look and reset the previous highscores
* look and change the current game options
* quit the game

The Menus are implemented in the Class Menu (menu.cpp, menu.h)

I/O
An further addition is the ability to save the options that the user can manipulate such as snake speed and speed increase and the top 5 highscores to files on the harddisk.
When this data is manipulation by thee user, it is imedietly written to disk minimizing the data loss in the case of a program crash. In the process of starting the program the data is automatically loaded into the game and is accessable. The reading and writing of the files is implemented in the Class FileController (file_controller.cpp, file_controller.h) and the data is stored in the files options.txt and highscores.txt.


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


### Project Requirements fullfilled

##Loops, Functions, I/O

#The project reads data from a file and process the data, or the program writes data to a file.
The project reads data from an external file or writes data to a file as part of the necessary operation of the program.
The project was extended to write game options ans the highscore into a file and reads it with the start of the program. Class FileController is responsible for reading and writing the data to files.

#The project accepts user input and processes the input.
The project accepts input from a user as part of the necessary operation of the program.
By adding the menu to the game the user is able to change some basic settings as well as have a look at the highsores.


##Object Oriented Programming
The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.

#The project uses Object Oriented Programming techniques.
The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
The whole project is designed with Object Oriented Programming techniques in mind.

#Classes use appropriate access specifiers for class members.
All class data members are explicitly specified as public, protected, or private.
All new classes where designd to meet this criteria. Additionally the attributes of the snake class where categorised as private ()

#Class constructors utilize member initialization lists.
All class members that are set to argument values are initialized through member initialization lists.

#Classes encapsulate behavior.
Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
All new classes where designd to meet this criteria. Additionally the attributes of the snake class where encapsulated so that they can be accessed just via member functions.
