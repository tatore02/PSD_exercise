#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#define MAX 100

Item inputItem () {
  char *a=malloc(sizeof(char)*1);
  scanf("%c",a);
  return a;
}

void outputItem (Item a) {
  char *c = a;
  printf("%c",*c);
}

int compareItem (Item a1, Item a2){
  char *stringa1 = a1;
  char *stringa2 = a2;
  return strcmp(stringa1,stringa2);
}

int compareChar(Item a1,Item a2){
  char *c1 = a1;
  char *c2 = a2;
  return *c1 - *c2;
}

char *ItemToChar(Item c){
  char *carattere = c;
  return carattere;
}
