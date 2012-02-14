#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"

int match (Data data) {
  if (data == NULL) return 0;
  if (*((int*)data) == 78) return 1;
  return 0;
}

void printlist (Listnode *plist) {
  if (plist == NULL) return;
  while(plist != NULL) {
    printf("List at %p, element is %d and next is %p\n", (void *)plist, *((int*)plist->content), (void *)plist->next);
    plist = plist->next;
  }
}

int main () {

  Listnode *plist = NULL;
  Listnode **pplist = &plist;

  printf("Length is now: %d\n", length(plist));

  int a = 78;
  Data pa = &a;
  prepend(pplist, pa);
 
  printf("Length is now: %d\n", length(plist));
  
  printf("Head works, if %d == %d\n",a, *(int*)head(*pplist));
 
  int c = 453;
  Data elem1 = &c;

  prepend(pplist, elem1); 
  prepend(pplist, elem1); 

  printf("Head works, if %d == %d\n",c, *(int*)head(*pplist));
  printf("Length is now: %d\n", length(plist));

  append(pplist, elem1);
  printf("Length is now: %d\n", length(plist));
  
  printlist(plist);
  remv(pplist, match); 
  printf("Length is now: %d\n", length(plist));
  printlist(plist);

  exit(0);
}
