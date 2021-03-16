#include <iostream>
#include "file_controller.h"
#include "menu.h"

int main() {

  FileController file_controller;
  Menu menu(file_controller);

  menu.MainMenu();

  return 0;
}
