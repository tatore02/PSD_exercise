#include <stdlib.h>
#include <stdio.h>
#include "item.h"

Item inputItem () {
  int *a=malloc(sizeof(int));
  scanf("%d",a);
  return a;
}

void outputItem (Item a) {
  int *intero=a;
  printf("%d ",*intero);
}

int compareItem (Item a1, Item a2){
  int *intero1=a1;
  int *intero2=a2;
  return *intero1-*intero2;
}

int ItemToInt(Item a){
  int *intero = a;
  return *intero;
}

Item intToItem(int a){
  int vett[1];
  vett[0] = a;
  Item item  = &a;
  return item;
}
