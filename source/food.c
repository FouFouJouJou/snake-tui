#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <food.h>
#include <position.h>

struct Food make_food(uint32_t x, uint32_t y, char shape) {
  struct Food food;
  food.pos=make_position(x,y);
  food.shape=shape;
  return food;
}

struct Food make_random_food(uint32_t x_limit, uint32_t y_limit, char shape) {
  srand(time(0));
  uint32_t random_x=(rand()%(x_limit))+1;
  uint32_t random_y=(rand()%(y_limit))+1;
  return make_food(random_x, random_y, shape);
}
