#include "menu.h"
#include <iostream>
#include <array>
#include <vector>


/*Menu::Menu() {
  FileController file_controller;
}*/


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


void Menu::MainMenu() {
  // read option and highscores from files
  file_controller.ReadOptions(options);
  file_controller.ReadHighscore(highscores);

  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int choice;
  bool stay = true;

  do {
    PrintMainMenu();
    choice = ConsoleInputInt(0, 3);

    if (choice == 0) {
      // run game
      Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
      Controller controller;
      Game game(kGridWidth, kGridHeight, options[1], options[2]);
      int score = game.Run(controller, renderer, kMsPerFrame);
      std::cout << "Score: " << score << '\n';
      AddHighscore(score);
      file_controller.WriteHighscore(highscores);


    } else if (choice == 1) {
      // enter highscores
      HighscoresMenu();

    } else if (choice == 2) {
      // enter options menu
      OptionsMenu();
    } else if (choice == 3) {
      // quit game
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
      // change World Size
      std::cout << "Please enter new World Size (range: 16 - 64): ";
      options[0] = ConsoleInputInt(16, 64);
      // write to file
      file_controller.WriteOptions(options);
      std::cout << "World Size successfully changed to: " << options[0] << '\n';

    } else if (choice == 1) {
      // change Snake Speed
      std::cout << "Please enter new Snake Speed (range: 1 - 100): ";
      options[1] = ConsoleInputInt(1, 100);
      // write to file
      file_controller.WriteOptions(options);
      std::cout << "Snake Speed successfully changed to: " << options[1] << '\n';

    } else if (choice == 2) {
      // change Snake Speed Increase
      std::cout << "Please enter new Snake Speed Increase (range: 0 - 10): ";
      options[2] = ConsoleInputInt(0, 10);
      // write to file
      file_controller.WriteOptions(options);
      std::cout << "Snake Speed Increase successfully changed to: " << options[2] << '\n';

    } else if (choice == 3) {
      // go back to main menu
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
      // reset all highscores
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
    } else if (choice == 1) {
      // go back to main menu
      stay = false;
    }
  } while(stay == true);
}

/*
void Menu::AddHighscore(int &score) {
  highscores[0] = score;
}
*/

void Menu::AddHighscore(int &score) {
  std::cout << "score : " << score << "\n";
  //std::vector<int> v;

  int i = 4;
  while (highscores[i] < score && i >= 0) {
    if (i < 4) {
      highscores[i+1] = highscores[i];
    }
    i--;
    std::cout << "i : " << i << "\n";
  }
  if (i < 4) {
    highscores[i+1] = score;
  }
  std::cout << "------------------------------- "<< "\n";
  for (int j=0; j<5; j++){
    std::cout << "highscores[i] : " << j << " - "<< highscores[j] << "\n";
  }
  std::cout << "------------------------------- "<< "\n";
}

/*
int Menu::AddHighscore(int i) {
  if (highscores[i] < score) {
    return AddHighscore(--i);
  }
  else {
    int temp = highscores[i];
    highscores[i] = score;
    std::cout << i << "All Highscores successfully set to 0\n";
    return temp;
  }
}
*/
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
