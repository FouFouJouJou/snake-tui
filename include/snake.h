#ifndef __SNAKE_H__
#define __SNAKE_H__
#include <stdint.h>
#include <position.h>
#define SNAKE_PART_CHAR '#'

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
  enum Direction direction;
  uint32_t score;
};

char *direction_to_string(enum Direction direction);
struct Snake *make_snake(uint32_t x, uint32_t y, char shape);
struct SnakePart *get_head_part(struct Snake *snake);
void grow(struct Snake *snake);
void move_snake(struct Snake *snake);
void set_snake_direction(struct Snake *snake, enum Direction direction);
enum Direction get_snake_direction(struct Snake *snake);
void printf_snake(struct Snake snake, void(*print)(void *));
void free_snake();
#endif
