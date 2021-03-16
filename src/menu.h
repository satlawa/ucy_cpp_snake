#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <array>


struct options {
  int world_size = 32;
  float snake_speed = 0.1;
  float snake_increase_speed = 0.02;
};

int world_size = 32;
float snake_speed = 0.1;
float snake_increase_speed = 0.02;

std::array<int, 5> highscores = { 9, 7, 5, 3, 1 };
//int highscores[5] = {5,3,2,1,0};

//void Menu::PrintMainMenu() {
void PrintMainMenu();
void PrintOptionsMenu();
void PrintHighscores();

int ConsoleInput(int min, int max);

void OptionsMenu();
void MainMenu();
void HighscoresMenu();

#endif
