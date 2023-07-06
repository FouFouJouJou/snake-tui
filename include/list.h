#ifndef __LIST_H__  
#define __LIST_H__
struct Node {
  void *value;  
  struct Node *next;
  struct Node *prev;
};

struct List {
  struct Node *head;
  struct Node *tail;
};

struct Node *make_empty_node();
struct Node *make_node(void *value, size_t size);
void free_node(struct Node *node);
struct List *make_empty_list();
void push(struct List *list, struct Node *node);
void append(struct List *list, struct Node *node);
struct Node *pop_tail(struct List *list);
void free_list(struct List *list);
void printf_list(struct List list, (void)(*print)(struct Node));
void printf_node(struct Node node);
#endif
