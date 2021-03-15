#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//#include <vector>
/*
class FileReader {
 public:
   // constructor / destructor
   FileReader(wxWindow *parent, wxWindowID id);
   ~FileReader();

   void ReadOptions(float &options[3]) {
     float options[3];
     string line;
     std::ifstream stream("options.txt");
     if (stream.is_open()) {
       std::getline(stream, line);
       std::istringstream linestream(line);
       linestream >> options[0] >> options[1] >> options[2];
     }
     std::cout << options[0] << '\n';
     std::cout << options[1] << '\n';
     std::cout << options[2] << '\n';

     return options;
   }

   void WriteOptions();

   ReadHighscore();
   void WriteHighscore();
}*/


void ReadOptions(float (&options)[3]) {
  string line;
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

void ReadHighscore(int (&highscores)[10]) {
  string line;
  std::ifstream stream("highscores.txt");
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for(int i = 0; i < 10; i++) {
      linestream >> highscores[i];
    }
  }
}

void WriteHighscore(int (&highscores)[10]) {

  std::ofstream stream("highscores.txt");
  if (stream.good()) {
    for(int i = 0; i < 10; i++) {
      std::cout << "Writing number: " << highscores[i] << std::endl;
      stream << highscores[i] << " ";
      //stream.write((char *)&f1,sizeof(float));
    }
    stream.close();
  }
}

void WriteOptions(int (&options)[3]) {

  std::ofstream stream("highscores.txt");
  if (stream.good()) {
    for(int i = 0; i < 10; i++) {
      std::cout << "Writing floating point number: " << std::fixed << options[i] << std::endl;
      stream.write((char *)&options[i],sizeof(float));
    }
    stream.close();
  }
}

int main() {
  float options[3];
  ReadOptions(options);

  std::cout << options[0] << '\n';
  std::cout << options[1] << '\n';
  std::cout << options[2] << '\n';

  int highscores[10];
  ReadHighscore(highscores);

  for(int i = 0; i < 10; i++) {
    std::cout << highscores[i] << '\n';
  }

  int index, value;
  std::cin >> index >> value;
  highscores[index] = value;

  WriteHighscore(highscores);
}
