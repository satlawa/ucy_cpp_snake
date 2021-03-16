#include "menu.h"
#include <iostream>
#include <array>


Menu::Menu(FileController &file_controller) {
  file_controller.ReadOptions(options);
  file_controller.ReadHighscore(highscores);
}

//opt.world_size = 0;
//opt.snake_speed = 0.0;
//opt.snake_increase_speed = 0.0;

/*
Menu::Menu(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
}
*/
/*
struct options {
  int world_size = 32;
  float snake_speed = 0.1;
  float snake_increase_speed = 0.02;
};

int highscores[5] = {5,3,2,1,0};
*/

//void Menu::PrintMainMenu() {
void Menu::PrintMainMenu() {
  // clear console
  //std::cout << "\033c";
  // print out game title and menu options to console
  std::cout << "==========================================" << '\n';
  std::cout << "===========   THE SNAKE GAME   ===========" << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "   0 - Start Game" << '\n';
  std::cout << "   1 - Highscores" << '\n';
  std::cout << "   2 - Options" << '\n';
  std::cout << "   3 - Quit Game" << '\n';
  std::cout << " " << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "Please enter the number of your choice: ";
}

void Menu::PrintOptionsMenu() {
  // clear console
  //std::cout << "\033c";
  // print out game title and menu options to console
  std::cout << "==========================================" << '\n';
  std::cout << "============   GAME OPTIONS   ============" << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "   World Size:                " << options[0] << '\n';
  std::cout << "   Initial Snake Speed:       " << options[1] << '\n';
  std::cout << "   Increase in Snake Speed:   " << options[2] << '\n';
  std::cout << " " << '\n';
  std::cout << "------------------------------------------" << '\n';
  std::cout << " " << '\n';
  std::cout << "   0 - Change World Size" << '\n';
  std::cout << "   1 - Change Initial Snake Speed" << '\n';
  std::cout << "   2 - Change Increase in Snake Speed" << '\n';
  std::cout << "   3 - Back to Main Menu" << '\n';
  std::cout << " " << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "Please enter the number of your choice: ";
}

void Menu::PrintHighscoresMenu() {
  // clear console
  //std::cout << "\033c";
  // print out game title and menu options to console
  std::cout << "==========================================" << '\n';
  std::cout << "=============   HIGHSCORES   =============" << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "             Rank   -   Score" << '\n';
  std::cout << " " << '\n';
  for(int i = 0; i < 5; i++) {
    std::cout << "               " << i+1 << "    -     " << highscores[i] << '\n';
  }
  std::cout << " " << '\n';
  std::cout << "------------------------------------------" << '\n';
  std::cout << " " << '\n';
  std::cout << "   0 - Reset Highscores" << '\n';
  std::cout << "   1 - Back to Main Menu" << '\n';
  std::cout << " " << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "Please enter the number of your choice: " << '\n';
}

int Menu::ConsoleInputInt(int min, int max) {
  int choice;
  std::cin >> choice;
  while (!std::cin || choice > max || choice < min) {
    std::cout << "Wrong input. Please, select one of the valid numbers: ";
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
    std::cin >> choice;
  }
  return choice;
}

float Menu::ConsoleInputFloat(float min, float max) {
  float choice;
  std::cin >> choice;
  while (!std::cin || choice > max || choice < min) {
    std::cout << "Wrong input. Please, select one of the valid numbers: ";
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
    std::cin >> choice;
  }
  return choice;
}

//void Menu::MainMenu() {
void Menu::MainMenu() {
  int choice;
  bool stay = true;

  do {
    PrintMainMenu();
    choice = ConsoleInputInt(0, 3);

    if (choice == 0) {
      // run game

    } else if (choice == 1) {
      // enter highscores
      HighscoresMenu();

    } else if (choice == 2) {
      // enter options menu
      OptionsMenu();
    } else if (choice == 3) {
      // quit
      stay = false;
    }
  } while(stay == true);
}

void Menu::OptionsMenu() {
  int choice;
  bool stay = true;

  do {
    PrintOptionsMenu();
    choice = ConsoleInputInt(0, 3);

    if (choice == 0) {
      std::cout << "Please enter new World Size (range: 16 - 64): ";
      options[0] = ConsoleInputInt(16, 64);
      std::cout << "World Size successfully changed to: " << options[0] << '\n';

    } else if (choice == 1) {
      std::cout << "Please enter new Initial Snake Speed (range: 1 - 100): ";
      options[1] = ConsoleInputInt(1, 100);
      std::cout << "Initial Snake Speed successfully changed to: " << options[1] << '\n';

    } else if (choice == 2) {
      std::cout << "Please enter new Increase in Snake Speed (range: 0 - 10): ";
      options[2] = ConsoleInputInt(0, 10);
      std::cout << "Increase in Snake Speed successfully changed to: " << options[2] << '\n';

    } else if (choice == 3) {
      stay = false;
    }
  } while(stay == true);
}

void Menu::HighscoresMenu() {
  int choice;
  bool stay = true;

  do {
    PrintHighscoresMenu();
    choice = ConsoleInputInt(0, 1);

    if (choice == 0) {
      std::cout << "Are you shure you want to reset all Highscores (Press 'y' to confirm): ";
      char answer;
      std::cin >> answer;
      if (answer == 'y') {
        highscores.fill(0);
        std::cout << "All Highscores successfully set to 0\n";
      }
    } else if (choice == 1) {
      stay = false;
    }
  } while(stay == true);
}

/*
int main() {

  //std::array<int, 5> highscoresX = { 9, 7, 5, 3, 1 };
  //float options[3] = {0,0,0};
  FileController file_controller;

  file_controller.ReadHighscore(highscores);
  for(int i = 0; i < 5; i++) {
    std::cout << i << " - " << highscores[i] << "\n";
  }

  file_controller.ReadOptions(opt);
  std::cout << "option 1 - " << opt.world_size << "\n";
  std::cout << "option 1 - " << opt.snake_speed << "\n";

  //struct options o;
  MainMenu();

  return 0;
}
*/
