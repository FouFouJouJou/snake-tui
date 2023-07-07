#ifndef __SNAKE_H__
#define __SNAKE_H__
#include <stdint.h>
#include <position.h>

enum Direction {
  UP=0
  ,DOWN
  ,RIGHT
  ,LEFT
};
struct SnakePart {
  struct Position pos;
  char shape;
};

struct Snake {
  struct List *parts;
  uint32_t score;
};

struct Snake *make_snake(uint32_t x, uint32_t y, char shape);
struct SnakePart *get_head_part(struct Snake *snake);
void grow(struct Snake *snake, enum Direction direction);
void move(struct Snake *snake, enum Direction direction);
void printf_snake(struct Snake snake);
void free_snake();
#endif
