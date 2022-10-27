#include "car.h"
#include <stdio.h>
#include <string.h>

Item inputItem(){
  char modello[15];
  char targa[10];
  int anno;

  printf("Inserire nome modello: ");
  scanf("%s",modello);

  printf("Inserire targa: ");
  scanf("%s",targa);

  printf("Inserire anno produzione: ");
  scanf("%d",&anno);

  return createCar(modello,targa,anno);
}

void outputItem(Item a){
  Car c = a;

  printf("Modello: %s\tTarga: %s\tAnno produzione: %d\n",getModello(c),getTarga(c),getAnno(c));
}

int compareAnno(Item a1,Item a2){
  Car c1 = a1;
  Car c2 = a2;

  return getAnno(c1) - getAnno(c2);
}

int compareTarga(Item a,char *targa){
  Car c = a;

  return strcmp(getTarga(c),targa);
}

int compareModello(Item a,char* modello){
  Car c = a;

  return strcmp(getModello(c),modello);
}


void swapItem(Item* a1,Item* a2){
  Item tmp = *a1;
  *a1 = *a2;
  *a2 = tmp;
}
