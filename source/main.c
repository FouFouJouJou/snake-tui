#include <stdio.h>
#include <stdlib.h>
#include <tui.h>
#include <unistd.h>
#include <ncurses.h>

#define FRAME_RATE (4*1000000/60)

int main(void) {
  struct Game *game = init();
  while (game->done == false) {
    update(game);
    render(game);
    usleep(FRAME_RATE);
    erase();
  }
  destroy(game);
  return EXIT_SUCCESS;
}
