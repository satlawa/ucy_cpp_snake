#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  float GetSpeed() const { return speed; }
  int GetSize() const { return size; }
  bool GetAlive() const { return alive; }

  float GetHeadX() const { return head_x; }
  float GetHeadY() const { return head_y; }
  std::vector<SDL_Point> GetBody() const { return body; }

  Direction GetDirection() const { return direction; }
  void SetDirection(Direction dir) { direction = dir; }

  void IncreaseSpeed(float increase) { speed += increase; }

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  float speed{0.1f};
  int size{1};
  bool alive{true};

  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  Direction direction = Direction::kUp;

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
