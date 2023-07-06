#ifndef __UTIL_H__
#define __UTIL_H__
#include <stdint.h>

struct Position {
  uint32_t x,y;
};
struct Position make_position(uint32_t x, uint32_t y);
struct Position make_random_position_in_range(uint32_t x_limit, uint32_t y_limit);
#endif
