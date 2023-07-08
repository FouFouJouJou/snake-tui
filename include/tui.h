#ifndef __UI_H__
#define __UI_H__
#include <stdint.h>
#include <stdbool.h>
#include <snake.h>
#include <food.h>

struct Game {
  struct Snake *snake;
  struct Food food;
  uint32_t width, height, score;
  bool done;
};

struct Game *init();
void update(struct Game *game);
enum Direction input_to_direction(int key, enum Direction default_direction);
void render(struct Game *game);
void destroy(struct Game *game);
#endif
