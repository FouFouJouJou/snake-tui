#include <stdint.h>
#include <food.h>
#include <position.h>

struct Food make_food(uint32_t x, uint32_t y, char shape) {
  struct Food food;
  food.pos=make_position(x,y);
  food.shape=shape;
  return food;
}
