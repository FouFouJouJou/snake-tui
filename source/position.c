#include <stdint.h>
#include <position.h>

struct Position make_position(uint32_t x, uint32_t y) {
  struct Position pos={.x=x, .y=y};
  return pos;
}
