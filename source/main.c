#include <stdio.h>
#include <stdlib.h>
#include <tui.h>
#include <unistd.h>
#include <ncurses.h>

#define FRAME_RATE 20000

int main(void) {
  struct Game *game = init();
  while(!game->done) {
    update(game);
    render(game);
    usleep(FRAME_RATE);
    clear();
  }
  destroy(game);
  return EXIT_SUCCESS;
}
