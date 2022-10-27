#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "song.h"

#define N 30

Item inputItem(FILE *fp){
  char *titolo = malloc(N*sizeof(char));
  char *artista = malloc(N*sizeof(char));
  char *durata = malloc(N*sizeof(char));

  fscanf(fp,"%s\n",titolo);
  fscanf(fp,"%s\n",artista);
  fscanf(fp,"%s\n",durata);

  return createSong(titolo,artista,durata);
}

void outputItem(Item x){
  Song s = x;
  printf("Nome: %s\nCantante: %s\nDurata: %s secondi\n",getTitolo(s),getArtista(s),getDurata(s));
}

int compareItem(Item x1,Item x2){
  Song s1 = x1;
  Song s2 = x2;
  printf("DEBUG: %d\n",strcmp(getTitolo(s1),getTitolo(s2)));
  return strcmp(getTitolo(s1),getTitolo(s2));
}

void swapItem(Item *x1,Item *x2){
  Item temp = *x1;
  *x1 = *x2;
  *x2 = temp;
}
