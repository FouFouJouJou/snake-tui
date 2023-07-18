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
  game->snake=make_snake(20,20, SNAKE_PART_CHAR);
  getmaxyx(stdscr, game->height, game->width);
  game->food=make_random_food(game->width,game->height, FOOD_CHAR);
  game->done=false;
  game->score=0;
  return game;
}
void render_border(struct Game *game) {
  for(uint32_t i=0; i<game->width; ++i) {
    move(0,i);
    addch('-');
    move(game->height-1, i);
    addch('-');
  }
  for(uint32_t i=0; i<game->height; ++i) {
    move(i,0);
    addch('|');
    move(i, game->width-1);
    addch('|');
  }
}

void init_curses() {
  initscr();
  noecho();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  timeout(1);
  curs_set(FALSE);
}

struct Game *init() {
  init_curses();
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


uint8_t process_input(struct Game *game) {
  int key=getch();
  if(key == 27) {
    game->done=true;
    return END_OF_GAME;
  }
  enum Direction new_direction=input_to_direction(key, get_snake_direction(game->snake));
  set_snake_direction(game->snake, new_direction);
  return ON_GOING;
}

void process_collisions(struct Game *game) {
  if(collide(game->food.pos, get_head_part(game->snake)->pos)) {
    game->score+=1;
    grow(game->snake);
    game->food=make_random_food(game->width,game->height, FOOD_CHAR);
  }
}

void update(struct Game *game) {
  move_snake(game->snake);
  process_collisions(game);
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

void render_score(struct Game *game) {
  char str[32];
  sprintf(str, "%d", game->score);
  move(game->height/2, game->width/2);
  printw("%s", str);
}

void render(struct Game *game) {
  render_border(game);
  render_score(game);
  render_food(game->food);
  printf_snake(*(game->snake), render_part);
  refresh();
}
void free_game(struct Game *game) {
  free_snake(game->snake);
  free(game);
}

void destroy(struct Game *game) {
  free_game(game);
  endwin();
}
