#ifndef __UI_H__
#define __UI_H__
#include <stdint.h>
#include <snake.h>
#include <food.h>

struct Game {
  struct Snake *snake;
  struct Food food;
  uint32_t width, height;
  uint8_t done;
};

struct Game *init();
void update(struct Game *game);
void destroy(struct Game *game);
#endif
