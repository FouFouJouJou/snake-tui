#include <stdlib.h>
#include <stdint.h>
#include <list.h>
#include <position.h>
#include <snake.h>

struct SnakePart *make_snake_part(uint32_t x, uint32_t y, char shape) {
  struct SnakePart *snake_part=malloc(sizeof(struct SnakePart));
  snake_part->pos=make_position(x,y);
  snake_part->shape=shape;
  return snake_part;
}

struct Snake *make_empty_snake() {
  struct Snake *snake=malloc(sizeof(struct Snake));
  snake->parts=make_empty_list();
  snake->score=0;
  return snake;
}

void add_part(struct Snake *snake, struct SnakePart *snake_part) {
  append_value(snake->parts, snake_part, sizeof(*snake_part));
}

void free_snake(struct Snake *snake) {
  free_list(snake->parts);  
  free(snake);
}
