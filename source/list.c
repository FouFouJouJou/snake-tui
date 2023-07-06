#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <list.h>

struct Node *make_empty_node() {
  struct Node *node=malloc(sizeof(struct Node));
  node->value=0;
  node->next=node->prev=0;
  return node;
}

struct Node *make_node(void *value, size_t size) {
  struct Node *node=make_empty_node();
  node->value=malloc(size);
  memcpy(node->value, value, size);
  return node;
}

void free_node(struct Node *node) {
  free(node->value);
  free(node);
}

struct List *make_empty_list() {
  struct List *list=malloc(sizeof(struct List));
  list->head=list->tail=0;
  return list;
}

void push(struct List *list, struct Node *node) {
  if(list->head == 0) {
    list->head=malloc(sizeof(struct Node));
    list->head=list->tail=node;
    list->head->prev=list->tail->next=0;
  }
  else {
    node->next=list->head;
    list->head=node;
  }
}

void append(struct List *list, struct Node *node) {
  if(list->head == 0) {
    list->head=malloc(sizeof(struct Node));
    list->head=list->tail=node;
    list->head->prev=list->head->next=0;
  }
  else {
    list->tail->next=node;
    list->tail=node;
  }
}

struct Node *pop_tail(struct List *list) {
  if(list->tail == 0) return 0;
  struct Node *tail=list->tail; 
  list->tail=list->tail->prev;
  list->tail->next=0;
  return tail;
}

void free_list(struct List *list) {
  struct Node *node_pointer=list->head;
  while(node_pointer != 0) {
    struct Node *next=node_pointer->next; 
    free_node(node_pointer);
    node_pointer=next;
  }
}

void printf_list(struct List list, void(*print)(struct Node)) {
  struct Node *node_pointer=list.head;  
  while(node_pointer != 0) {
    print(*node_pointer);
    node_pointer=node_pointer->next;
  }
  printf("(nil)\n");
}
