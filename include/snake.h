#ifndef __SNAKE_H__
#define __SNAKE_H__
#include <stdint.h>

struct Position {
  uint32_t x,y;
};

struct Food {
  struct Position pos;
  char shape;
};

struct SnakePart {
  struct Position pos;
  char shape;
};

struct Snake {
  struct List *parts;
  uint32_t score;
};

struct Snake *make_empty_snake();
void free_snake();
#endif
