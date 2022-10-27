#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){
  int *x=malloc(sizeof(int));
  scanf("%d",x);
  return x;
}

void outputItem(Item x){
  int *intero=x;
  printf("%d ",*intero);
}

int compareItem(Item x1,Item x2){
  int *intero1=x1;
  int *intero2=x2;
  return *intero1 - *intero2;
}

void swapItem(Item *x1,Item *x2){
  Item temp = *x2;
  *x2= *x1;
  *x1 = temp;
}
