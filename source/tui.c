#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <food.h>
#include <snake.h>
#include <tui.h>

bool collide(struct Position pos1, struct Position pos2) {
  return pos1.x == pos2.x && pos1.y == pos2.y;
}

struct Game *make_game() {
  struct Game *game=malloc(sizeof(struct Game));
  game->snake=make_snake(20,20,'#');
  game->food=make_food(22,30,'@');
  game->width=200;
  game->height=200;
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
  if(collide(game->food.pos, get_head_part(game->snake)->pos)) {
    grow(game->snake, game->direction);
    game->food=make_food(20,20,'@');
  }
}

void render_part(void *data) {
  struct SnakePart *snake_part=(struct SnakePart *)data;
  move(snake_part->pos.y, snake_part->pos.x);
  addch(snake_part->shape);
}

void render_food(struct Food food) {
  move(food.pos.y, food.pos.x);
  addch(food.shape);
}


void render(struct Game *game) {
  render_food(game->food);
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
