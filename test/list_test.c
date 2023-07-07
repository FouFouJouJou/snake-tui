#include <stdio.h>
#include <stdlib.h>
#include <list.h>

void printf_int_node(void *data) {
  printf("%d", *((int *)(data)));
}

int main(void) {
  struct List *list=make_empty_list();
  int int1=1, int3=3, int0=0;
  append(list, make_node(&int1, sizeof(int)));
  append(list, make_node(&int3, sizeof(int)));
  push(list, make_node(&int0, sizeof(int)));
  printf_list(*list, printf_int_node);
  free_list(list); 
  return EXIT_SUCCESS;
}
