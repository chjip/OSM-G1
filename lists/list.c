#include <stdlib.h>
#include <stdio.h>
#include "list.h"

//#define DEBUG

/*
  typedef void* Data;

  typedef struct listnode {
  Data content;
  struct listnode* next;
  } Listnode;
*/

/* add an element at the end of the list */
void append(Listnode **start, Data elem) {
  if (*start == NULL) {
    prepend(start,elem);
    return;
  }

  Listnode *curr = *start;
  while (curr->next!=NULL) 
    curr = curr->next;

  prepend(&(curr->next),elem);
}

/* add an element at the front */
void prepend(Listnode **start, Data elem) {
  Listnode *new = (Listnode *) malloc(sizeof(Listnode));
  new->content = elem;
  new->next = *start;
  *start = new;
 
#ifdef DEBUG
  printf("made new listnode.\n  address to new listnode is  %p\n  address to next listnode is %p\n", (void*)new, (void*)new->next);
#endif
}

/* length */
int length(Listnode *start) {
  if (start == NULL) return 0;

  Listnode *curr = start;
  int i = 1;
  while (curr->next != NULL) {
    curr = curr->next;
    i++;
  }

  return i;
}

/* return first element (if not empty) */
Data head(Listnode *start) {
  return start->content;
}

void remv(Listnode **start, int (*match)(Data)) {
  Listnode *curr, **last;
  if (*start == NULL) return;
  last = start;
  curr = *start;
  while (curr!=NULL && !(match(curr->content))) {
    last = &(curr->next);
    curr = curr->next;
  }
  if (curr == NULL) return; /* not found, do nothing */
  
  *last = curr->next;  /* found, remove and free */
  free(curr); 
}


