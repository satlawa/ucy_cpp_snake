#include "game.h"
#include <iostream>
#include "SDL.h"

Menu::Menu(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
}

void Menu::Show() {

  int option

  PrintStartScreen();

  while (!((std::cin >> option) || (option > 3)) {
    std::cout << "Wrong input. Please, try again: ";
    std::cin.clear();
  }

  if (option == 0) {

  } else if (option == 1) {

  } else if (option == 2) {

  }

}

void Menu::PrintStartScreen() {
  // print out game title and menu options to console
  std::std::cout << "==========================================" << '\n';
  std::std::cout << "===========   THE SNAKE GAME   ===========" << '\n';
  std::std::cout << "==========================================" << '\n';
  std::std::cout << " " << '\n';
  std::std::cout << "0 - Start Game" << '\n';
  std::std::cout << "1 - Highscores" << '\n';
  std::std::cout << "2 - Options" << '\n';
  std::std::cout << " " << '\n';
  std::std::cout << "==========================================" << '\n';
  std::std::cout << " " << '\n';
  std::std::cout << "Please enter the number of your choice: ";
}
