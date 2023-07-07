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

void *get_head_value(struct List *list) {
  return list->head->value;
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

void append_value(struct List *list, void *data, size_t size) {
  append(list, make_node(data, size));  
}

void push_value(struct List *list, void *data, size_t size) {
  push(list, make_node(data, size));  
}

void push(struct List *list, struct Node *node) {
  if(list->head == 0) {
    list->head=malloc(sizeof(struct Node));
    list->head=list->tail=node;
    list->head->prev=list->tail->next=0;
  }
  else {
    node->next=list->head;
    list->head->prev=node;
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
    node->prev=list->tail;
    list->tail->next=node;
    list->tail=node;
  }
}

struct Node *pop_tail(struct List *list) {
  struct Node *tail;
  if(list->tail == 0) return 0;
  else if(list->tail == list->head) {
    tail=list->head;
    list->head=0;
    return tail;
  }
  else {
    tail=list->tail; 
    list->tail=list->tail->prev;
    list->tail->next=0;
    return tail;
  }
}

void free_list(struct List *list) {
  struct Node *node_pointer=list->head;
  while(node_pointer != 0) {
    struct Node *next=node_pointer->next; 
    free_node(node_pointer);
    node_pointer=next;
  }
}

void printf_list(struct List list, void(*print)(void *)) {
  struct Node *node_pointer=list.head;
  while(node_pointer != 0) {
    print(node_pointer->value);
    node_pointer=node_pointer->next;
  }
}
