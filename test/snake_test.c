#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <list.h>
#include <snake.h>

int main(void) {
  printf("snake test\n");
  struct Snake *snake = make_snake(20, 20, '#');
  move_snake(snake, DOWN);
  printf_snake(*snake);
  move_snake(snake, DOWN);
  printf_snake(*snake);
  grow(snake, DOWN);
  printf_snake(*snake);
  move_snake(snake, RIGHT);
  printf_snake(*snake);
  move_snake(snake, RIGHT);
  printf_snake(*snake);
  grow(snake, RIGHT);
  printf_snake(*snake);
  return EXIT_SUCCESS;
}
