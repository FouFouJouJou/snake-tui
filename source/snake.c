#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <list.h>
#include <position.h>
#include <snake.h>

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
  struct SnakePart *snake_part = make_snake_part(x, y, shape);
  append_value(snake->parts, snake_part, sizeof(*snake_part));
  return snake;
}

void grow(struct Snake *snake, enum Direction direction) {
  struct Position current_pos =
    get_head_part(snake)->pos;
  switch(direction) {
    case UP: 
      printf("growing UP\n");
      current_pos.y-=1;
      break;
    case DOWN: 
      printf("growing DOWN\n");
      current_pos.y+=1;
      break;
    case LEFT: 
      printf("growing LEFT\n");
      current_pos.x-=1;
      break;
    case RIGHT: 
      printf("growing RIGHT\n");
      current_pos.x+=1;
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


void move_snake(struct Snake *snake, enum Direction direction) {
  struct Position current_pos =
    get_head_part(snake)->pos;
  switch(direction) {
    case UP: 
      printf("moving UP\n");
      current_pos.y-=1;
      break;
    case DOWN: 
      printf("moving DOWN\n");
      current_pos.y+=1;
      break;
    case LEFT: 
      printf("moving LEFT\n");
      current_pos.x-=1;
      break;
    case RIGHT: 
      printf("moving RIGHT\n");
      current_pos.x+=1;
      break;
  }
  push(snake->parts, pop_tail(snake->parts));
  get_head_part(snake)->pos=current_pos;
}

void printf_snake_part_node(struct Node node) {
  struct SnakePart *snake_part = (struct SnakePart *)(node.value);
  printf("(%i, %i, %c)", snake_part->pos.x, snake_part->pos.y, snake_part->shape);
}

void printf_snake(struct Snake snake) {
  printf_list(*(snake.parts),  printf_snake_part_node);
}
void free_snake(struct Snake *snake) {
  free_list(snake->parts);  
  free(snake);
}
