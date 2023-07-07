#ifndef __FOOD_H__
#define __FOOD_H__
#include <position.h>

struct Food {
  struct Position pos;
  char shape;
};

struct Food make_food(uint32_t x_limit, uint32_t y_limit, char shape);
struct Food make_random_food(uint32_t x_limit, uint32_t y_limit, char shape);
#endif
