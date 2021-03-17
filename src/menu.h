#ifndef MENU_H
#define MENU_H

#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "file_controller.h"

#include <iostream>
#include <array>

class Menu {
 public:
   void MainMenu();

 private:
  FileController file_controller;

  void OptionsMenu();
  void HighscoresMenu();

  void PrintMainMenu();
  void PrintOptionsMenu();
  void PrintHighscoresMenu();
  void PrintGameOver(int &score);

  int ConsoleInputInt(int min, int max);
  bool AddHighscore(int &score);

  std::array<int, 5> highscores = { 9, 7, 5, 3, 1 };
  std::array<int, 3> options = { 40, 20, 2 };
};

#endif
