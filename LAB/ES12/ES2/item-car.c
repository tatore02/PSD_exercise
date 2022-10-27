#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "car.h"

#define N 20

Item inputItem(){
  char *modello = malloc(N*sizeof(char));
  printf("Inserire nome modello: ");
  scanf("%s",modello);
  int annoProd;
  printf("Inserire anno produzione: ");
  scanf("%d",&annoProd);
  int annoImm;
  printf("Inserire anno immatricolazione: ");
  scanf("%d",&annoImm);
  char *targa = malloc(N*sizeof(char));
  printf("Inserire targa: ");
  scanf("%s",targa);

  return newCar(modello,annoProd,annoImm,targa);
}

void outputItem(Item x){
  Car a = x;
  printf("Modello: %s\nAnno produzione: %d\nAnno immatricolazione: %d\nTarga: %s\n",getModello(a),getAnnoProd(a),getAnnoImm(a),getTarga(a));
}

int compareItem(Item x1,Item x2){
  Car a1 = x1;
  Car a2 = x2;

  if(getAnnoProd(a1) > getAnnoProd(a2))
    return 1;
  else return 0;
}

int compareItem2(char *x1,Item x2){
  Car a2 = x2;

  return strcmp(x1,getModello(a2));
}

void swapItem(Item *x1,Item *x2){
  Item temp = x1;
  x1 = x2;
  x2 = x1;
}
