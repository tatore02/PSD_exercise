#include <stdlib.h>
#include <string.h>
#include "car.h"
#include "list.h"

struct car{
  char modello[20];
  int annoProd;
  int annoImm;
  char targa[10];
};

Car newCar(char* mod,int prod,int imm,char* tar){
  Car a = malloc(sizeof(struct car));
  strcpy(a->modello,mod);
  a->annoProd = prod;
  a->annoImm = imm;
  strcpy(a->targa,tar);

  return a;
}

char *getModello(Car a){
  return a->modello;
}

int getAnnoProd(Car a){
  return a->annoProd;
}

int getAnnoImm(Car a){
  return a->annoImm;
}

char *getTarga(Car a){
  return a->targa;
}

void addCar(List l,Car a){
  addHead(l,a);
}

void deleteCar(List l,Item a){
  removeListItem(l,a);
}

Car ricercaCar(List l,Car a){
  int n=0;
  return searchList(l,a,&n);
}

void sortCar(List l){
  sortList(l);
}

void printCar(List l){
  printList(l);
}
