/*
Menu Class containing the code for displaying and interacting with the menus.
*/

#include "menu.h"
#include <iostream>
#include <array>
#include <vector>
#include <unistd.h>


void Menu::PrintMainMenu() {
// print out game title and menu options to the console

  // clear console
  std::cout << "\033c";
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
// print out the current option values and manipulation options to the console

  // clear console
  std::cout << "\033c";
  std::cout << "==========================================" << '\n';
  std::cout << "============   GAME OPTIONS   ============" << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "   World Size:             " << options[0] << '\n';
  std::cout << "   Snake Speed:            " << options[1] << '\n';
  std::cout << "   Snake Speed Increase:   " << options[2] << '\n';
  std::cout << " " << '\n';
  std::cout << "------------------------------------------" << '\n';
  std::cout << " " << '\n';
  std::cout << "   0 - Change World Size" << '\n';
  std::cout << "   1 - Change Snake Speed" << '\n';
  std::cout << "   2 - Change Snake Speed Increased" << '\n';
  std::cout << "   3 - Back to Main Menu" << '\n';
  std::cout << " " << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "Please enter the number of your choice: ";
}


void Menu::PrintHighscoresMenu() {
// print out top 5 highscores and manipulation options to the console

  // clear console
  std::cout << "\033c";
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

void Menu::PrintGameOver(int &score) {
// print out game over screen

  // clear console
  std::cout << "\033c";
  std::cout << "==========================================" << '\n';
  std::cout << "=============   GAME OVER   ==============" << '\n';
  std::cout << "==========================================" << '\n';
  std::cout << " " << '\n';
  std::cout << "                Score: " << score << '\n';
  std::cout << " " << '\n';
  std::cout << "==========================================" << '\n';
  sleep(1.5);
}

int Menu::ConsoleInputInt(int min, int max) {
// checks the imput of the user and declines any input that is
//    either from another data type or is out of range
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


void Menu::MainMenu() {
// logic of main menu

  // read option and highscores from files
  file_controller.ReadOptions(options);
  file_controller.ReadHighscore(highscores);

  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};

  int choice;
  bool stay = true;

  do {
    PrintMainMenu();
    choice = ConsoleInputInt(0, 3);

    // start game
    if (choice == 0) {
      // create instances of the folling classes to
      Renderer renderer(kScreenWidth, kScreenHeight, options[0], options[0]);
      Controller controller;
      Game game(options[0], options[0], options[1], options[2]);
      // run game
      int score = game.Run(controller, renderer, kMsPerFrame);
      // print Game Over and score
      PrintGameOver(score);
      // add highscore to highscore table
      bool update = AddHighscore(score);
      if (update == true) {
        // write highscore to file
        file_controller.WriteHighscore(highscores);
      }
    } // enter highscores
    else if (choice == 1) {
      HighscoresMenu();
    } // enter options menu
    else if (choice == 2) {
      OptionsMenu();
    } // quit game
    else if (choice == 3) {
      stay = false;
    }
  } while(stay == true);
}


void Menu::OptionsMenu() {
// logic of options menu

  int choice;
  bool stay = true;

  do {
    PrintOptionsMenu();
    choice = ConsoleInputInt(0, 3);

    // change World Size
    if (choice == 0) {
      std::cout << "Please enter new World Size (range: 16 - 64): ";
      options[0] = ConsoleInputInt(16, 64);
      // write to file
      file_controller.WriteOptions(options);
      std::cout << "World Size successfully changed to: " << options[0] << '\n';
    } // change Snake Speed
    else if (choice == 1) {
      std::cout << "Please enter new Snake Speed (range: 1 - 100): ";
      options[1] = ConsoleInputInt(1, 100);
      // write to file
      file_controller.WriteOptions(options);
      std::cout << "Snake Speed successfully changed to: " << options[1] << '\n';
    } // change Snake Speed Increase
    else if (choice == 2) {
      std::cout << "Please enter new Snake Speed Increase (range: 0 - 10): ";
      options[2] = ConsoleInputInt(0, 10);
      // write to file
      file_controller.WriteOptions(options);
      std::cout << "Snake Speed Increase successfully changed to: " << options[2] << '\n';
    } // go back to main menu
    else if (choice == 3) {
      stay = false;
    }
  } while(stay == true);
}


void Menu::HighscoresMenu() {
// logic of highscores menu

  int choice;
  bool stay = true;

  do {
    PrintHighscoresMenu();
    choice = ConsoleInputInt(0, 1);

    // reset all highscores
    if (choice == 0) {
      std::cout << "Are you shure you want to reset all Highscores (Press 'y' to confirm): ";
      char answer;
      std::cin >> answer;
      if (answer == 'y') {
        // set all highscores to 0
        highscores.fill(0);
        // write to file
        file_controller.WriteHighscore(highscores);
        std::cout << "All Highscores successfully set to 0\n";
      }
    } // go back to main menu
    else if (choice == 1) {
      stay = false;
    }
  } while(stay == true);
}


bool Menu::AddHighscore(int &score) {
// add provided highscore to top 5 highscores, if it is high enough
//    and sort the highscores

  int i = 4;
  while (highscores[i] < score && i >= 0) {
    if (i < 4) {
      highscores[i+1] = highscores[i];
    }
    i--;
  }
  if (i < 4) {
    highscores[i+1] = score;
    return true;
  } else {
    return false;
  }
}
