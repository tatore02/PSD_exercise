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
  printf("%d\n",*intero);
}

int compareItem (Item a1, Item a2){
  int *intero1=a1;
  int *intero2=a2;
  return *intero1-*intero2;
}

void swapItem(Item *x1,Item *x2){
  Item temp = *x2;
  *x2 = *x1;
  *x1 = temp;
}

int ItemToInt(Item a){
  int *intero = a;
  return *intero;
}

float ItemToFloat(Item a){
  float *fl = a;
  return *fl;
}


Item intToItem(int a){
  int vett[1];
  vett[0] = a;
  Item item = &vett[0];
  return item;
}

Item div2(Item a){
  int *intero = a;
  *intero = *intero / 2;
  return intToItem(*intero);
}
