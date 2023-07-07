#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <food.h>
#include <snake.h>
#include <tui.h>

struct Game *make_game() {
  struct Game *game=malloc(sizeof(struct Game));
  game->snake=make_snake(20,20,'#');
  //game->food=make_random_food('|');
  game->width=100;
  game->height=100;
  game->done=false;
  game->direction = RIGHT;
  return game;
}
struct Game *init() {
  initscr();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  timeout(10);
  curs_set(FALSE);
  return make_game();
}

enum Direction input_to_direction(int key, enum Direction default_direction) {
  switch(key) {
    case KEY_DOWN: return DOWN;
    case KEY_UP: return UP;
    case KEY_LEFT: return LEFT;
    case KEY_RIGHT: return RIGHT;
    case ERR:
    default:
      return default_direction;
  }
}

void update(struct Game *game) {
  int key=getch();
  if(key == KEY_CLOSE || key == KEY_EXIT || key == KEY_END) {
    game->done=true;
    return;
  }
  game->direction=input_to_direction(key, game->direction);
  move_snake(game->snake, game->direction);
  //collistion detection with the food
  //if(snake_head_collide(game->food.pos)) {
  //  grow(game->snake, game->direction);
  //}
}

void render_part(void *data) {
  struct SnakePart *snake_part=(struct SnakePart *)data;
  move(snake_part->pos.y, snake_part->pos.x);
  addch(snake_part->shape);
  refresh();
}

void render(struct Game *game) {
  printf_snake(*(game->snake), render_part);
  refresh();
}
void free_game(struct Game *game) {
  free_snake(game->snake);
  free(game);
}

void destroy(struct Game *game) {
  (void)game;
  endwin();
}
