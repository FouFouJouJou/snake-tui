#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <list.h>
#include <position.h>
#include <snake.h>
#define Y_SPEED 1
#define X_SPEED 1

struct SnakePart *make_snake_part_with_position(struct Position pos, char shape) {
  struct SnakePart *snake_part=malloc(sizeof(struct SnakePart));
  snake_part->pos=pos;
  snake_part->shape=shape;
  return snake_part;
}

struct SnakePart *make_snake_part(uint32_t x, uint32_t y, char shape) {
  return make_snake_part_with_position(make_position(x,y), shape);
}

struct Snake *make_empty_snake() {
  struct Snake *snake=malloc(sizeof(struct Snake));
  snake->parts=make_empty_list();
  snake->score=0;
  return snake;
}

struct Snake *make_snake(uint32_t x, uint32_t y, char shape) {
  struct Snake *snake = make_empty_snake();
  snake->direction = RIGHT;
  struct SnakePart *snake_part = make_snake_part(x, y, shape);
  append_value(snake->parts, snake_part, sizeof(*snake_part));
  return snake;
}

void grow(struct Snake *snake, enum Direction direction) {
  struct Position current_pos =
    get_head_part(snake)->pos;
  switch(direction) {
    case UP: 
      current_pos.y-=Y_SPEED;
      break;
    case DOWN: 
      current_pos.y+=Y_SPEED;
      break;
    case LEFT: 
      current_pos.x-=X_SPEED;
      break;
    case RIGHT: 
      current_pos.x+=X_SPEED;
      break;
  }
  struct SnakePart *new_snake_head=make_snake_part_with_position(current_pos, '#');
  push_value(snake->parts, new_snake_head, sizeof(*new_snake_head));
}

struct SnakePart *get_head_part(struct Snake *snake) {
  struct SnakePart *snake_part = 
    (struct SnakePart*)get_head_value(snake->parts);
    return snake_part;
}

void set_snake_direction(struct Snake *snake, enum Direction direction) {
    snake->direction=direction;
}

void move_snake(struct Snake *snake) {
  struct Position current_pos =
    get_head_part(snake)->pos;
  switch(snake->direction) {
    case UP: 
      current_pos.y-=Y_SPEED;
      break;
    case DOWN: 
      current_pos.y+=Y_SPEED;
      break;
    case LEFT: 
      current_pos.x-=X_SPEED;
      break;
    case RIGHT: 
      current_pos.x+=X_SPEED;
      break;
  }
  push(snake->parts, pop_tail(snake->parts));
  get_head_part(snake)->pos=current_pos;
}

void printf_snake(struct Snake snake, void(*print)(void*)) {
  printf_list(*(snake.parts), print);
}
void free_snake(struct Snake *snake) {
  free_list(snake->parts);  
  free(snake);
}

char *direction_to_string(enum Direction direction) {
  switch(direction) {
    case UP: return "UP";
    case DOWN: return "DOWN";
    case LEFT: return "LEFT";
    case RIGHT: return "RIGHT";
  }
  return 0;
}
