#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <list.h>
#include <snake.h>

void printf_part(void *data) {
  struct SnakePart *snake_part = (struct SnakePart *)(data);
  printf("(%i, %i, %c)", snake_part->pos.x, snake_part->pos.y, snake_part->shape);
}

int main(void) {
  printf("snake test\n");
  struct Snake *snake = make_snake(20, 20, '#');
  move_snake(snake);
  printf_snake(*snake, printf_part);
  move_snake(snake);
  printf_snake(*snake, printf_part);
  move_snake(snake);
  printf_snake(*snake, printf_part);
  move_snake(snake);
  printf_snake(*snake, printf_part);
  return EXIT_SUCCESS;
}
