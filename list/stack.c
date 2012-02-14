#include <stdlib.h>
#include "stack.h"
#include "list.h"

void stack_init(stack_t* stack) {
  stack = stack; // just to get rid of warning
}

int stack_empty(stack_t* stack) {
  return (length(stack->list) == 0);
}

void* stack_top(stack_t* stack) {
  return head(stack->list);
}

int matchall(Data data) {
  data = data;
  return 1;
}

void* stack_pop(stack_t* stack) {
  void *h = head(stack->list);
  remv( &(stack->list), matchall );
  return h; 
}

int stack_push(stack_t* stack, void* data) {
  prepend(&(stack->list), data);
  return 0;
}
