#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "libro.h"

Item inputItem(FILE *fp){
  char *titolo;
  char *autore;
  char *codice;

  titolo = malloc(30*sizeof(char));
  autore = malloc(20*sizeof(char));
  codice = malloc(3*sizeof(char));

  fscanf(fp,"%s\n",titolo);
  fscanf(fp,"%s\n",autore);
  fscanf(fp,"%s\n",codice);

  return createLibro(titolo,autore,codice);
}

void outputItem(Item a){
  Libro b = a;
  printf("%s\t%s\t%d\n",getTitolo(b),getAutore(b),getCodice(b));
}

int compareItem(Item x1,Item x2){
  Libro b1 = x1;
  Libro b2 = x2;

  return getCodice(b1) - getCodice(b2);
}

int compareItem2(int x1,Item item){
  int x2 = getCodice(item);

  return x1-x2;
}

int compareItem3(char *x1,Item x2){
  Libro b2 = x2;

  return strcmp(x1,getAutore(b2));
}

int compareItem4(Item x1,Item x2){
  Libro b1 = x1;
  Libro b2 = x2;

  return strcmp(getTitolo(b1),getTitolo(b2));
}

int ItemToInt(Item a){
  int *intero = a;
  return *intero;
}

void swapItem(Item *x1,Item *x2){
  Item temp = *x1;
  *x1 = *x2;
  *x2 = temp;
}
