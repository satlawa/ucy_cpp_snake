#ifndef FILE_CONTROLLER_H
#define FILE_CONTROLLER_H

#include <array>

class FileController {
 public:
   void ReadOptions(std::array<int, 3> &options);
   void ReadHighscore(std::array<int, 5> &highscores);

   void WriteOptions(std::array<int, 3> &options);
   void WriteHighscore(std::array<int, 5> &highscores);
};

#endif
