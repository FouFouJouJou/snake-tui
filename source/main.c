#include <stdio.h>
#include <stdlib.h>
#include <tui.h>
#include <unistd.h>
#include <ncurses.h>

#define FRAME_RATE (4*1000000/60)

int main(void) {
  struct Game *game = init();
  while (game->done == false) {
    if(process_input(game) == END_OF_GAME) break;
    update(game);
    render(game);
    usleep(FRAME_RATE);
    erase();
  }
  uint32_t score=game->score;
  destroy(game);
  printf("your final score: %i\n", score);
  return EXIT_SUCCESS;
}
