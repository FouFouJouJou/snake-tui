#include <stdint.h>
#include <position.h>

struct Position make_position(uint32_t x, uint32_t y) {
  struct Position pos={.x=x, .y=y};
  return pos;
}
struct Position make_random_position_in_range(uint32_t x_limit, uint32_t y_limit) {
  return make_position(x_limit, y_limit);
}
