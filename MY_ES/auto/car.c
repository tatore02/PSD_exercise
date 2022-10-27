#include "car.h"
#include <stdlib.h>
#include <string.h>

struct car{
  char *modello;
  char *targa;
  int anno;
};

Car createCar(char *mod,char *tar,int an){
  Car c = malloc(sizeof(struct car));

  c->modello = malloc(sizeof(strlen(mod)));
  strcpy(c->modello,mod);
  c->targa = malloc(sizeof(strlen(tar)));
  strcpy(c->targa,tar);
  c->anno = an;

  return c;
}

char* getModello(Car c){
  return c->modello;
}

char* getTarga(Car c){
  return c->targa;
}

int getAnno(Car c){
  return c->anno;
}
