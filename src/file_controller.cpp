/*
FileController Class containing the code for reading and writing data to
files options.txt and highscores.txt.
*/
#include "file_controller.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <string>
#include <algorithm>


void FileController::ReadOptions(std::array<int, 3> &options) {
// read data from file options.txt

  std::string line;
  std::ifstream stream("options.txt");
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> options[0] >> options[1] >> options[2];
  }
}


void FileController::ReadHighscore(std::array<int, 5> &highscores) {
// read data from file highscores.txt

  std::string line;
  std::ifstream stream("highscores.txt");
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for(int i = 0; i < 5; i++) {
      linestream >> highscores[i];
    }
  }
}


void FileController::WriteOptions(std::array<int, 3> &options) {
// write data from file options.txt

  std::ofstream stream("options.txt");
  if (stream.good()) {
    stream << options[0] << " " << options[1] << " " << options[2] << " ";
    stream.close();
  }
}


void FileController::WriteHighscore(std::array<int, 5> &highscores) {
// write data to file highscores.txt

  std::ofstream stream("highscores.txt");
  if (stream.good()) {
    for(int i = 0; i < 5; i++) {
      std::cout << "Writing number: " << highscores[i] << std::endl;
      stream << highscores[i] << " ";
    }
    stream.close();
  }
}
