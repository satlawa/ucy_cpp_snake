#include "file_controller.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <string>
#include <algorithm>


void FileController::ReadOptions(std::array<int, 3> &options) {
//void ReadOptions(float (&options)[3]) {

  std::string line;
  std::ifstream stream("options.txt");
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> options[0] >> options[1] >> options[2];
  }
  std::cout << options[0] << '\n';
  std::cout << options[1] << '\n';
  std::cout << options[2] << '\n';
}


//void FileController::ReadHighscore(int (&highscores)[5]) {
void FileController::ReadHighscore(std::array<int, 5> &highscores) {
//void ReadHighscore(int (&highscores)[5]) {

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
//void WriteOptions(float (&options)[3]) {

  std::ofstream stream("options.txt");
  if (stream.good()) {
    stream << options[0] << " " << options[1] << " " << options[2] << " ";
    stream.close();
  }
}


//void FileController::WriteHighscore(int (&highscores)[5]) {
void FileController::WriteHighscore(std::array<int, 5> &highscores) {
//void WriteHighscore(int (&highscores)[5]) {

  std::ofstream stream("highscores.txt");
  if (stream.good()) {
    for(int i = 0; i < 5; i++) {
      std::cout << "Writing number: " << highscores[i] << std::endl;
      stream << highscores[i] << " ";
      //stream.write((char *)&f1,sizeof(float));
    }
    stream.close();
  }
}

/*
int main() {
  float options[3];
  ReadOptions(options);

  std::cout << options[0] << '\n';
  std::cout << options[1] << '\n';
  std::cout << options[2] << '\n';

  int highscores[5];
  ReadHighscore(highscores);

  std::cout << "-------------------------------------" << '\n';
  int n = sizeof(highscores) / sizeof(highscores[0]);
  std::cout << "-------------------------------------" << '\n';
  std::sort(highscores, highscores + n, greater<int>());

  int index, value;
  //std::cin >> index >> value;
  //highscores[index] = value;

  WriteHighscore(highscores);

  float fvalue;
  std::cin >> index >> fvalue;
  options[index] = fvalue;

  WriteOptions(options);

  return 0;
}
*/
