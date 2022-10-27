#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#define M 20

Item inputItem(){
  char *x=malloc(M * sizeof(char));
  scanf("%s",x);
  return x;
}

void outputItem(Item x){
  char *stringa=x;
  printf("%s\n",stringa);
}

int compareItem(Item x1,Item x2){
  char *stringa1=x1;
  char *stringa2=x2;
  return strcmp(stringa1,stringa2);
}

void swapItem(Item *x1,Item *x2){
  Item *temp = *x1;
  *x1 = *x2;
  *x2 = *temp;
}
