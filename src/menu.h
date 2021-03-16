#ifndef MENU_H
#define MENU_H

#include "file_controller.h"
#include <iostream>
#include <array>

class Menu {
 public:
   Menu(FileController &file_controller);
   void MainMenu();

 private:
  int ConsoleInputInt(int min, int max);
  float ConsoleInputFloat(float min, float max);

  void OptionsMenu();
  void HighscoresMenu();

  void PrintMainMenu();
  void PrintOptionsMenu();
  void PrintHighscoresMenu();

  std::array<int, 5> highscores = { 9, 7, 5, 3, 1 };
  std::array<int, 3> options = { 32, 10, 1 };
};

#endif
