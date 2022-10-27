#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libro.h"
#include "list.h"

struct libro{
  char *titolo;
  char *autore;
  int codice;
};

Libro createLibro(char *title,char *author,char *code){
  Libro b = malloc(sizeof(struct libro));
  b->titolo = strdup(title);
  b->autore = strdup(author);
  b->codice = atoi(code);

  return b;
}

char *getTitolo(Libro b){
  return b->titolo;
}

char *getAutore(Libro b){
  return b->autore;
}

int getCodice(Libro b){
  return b->codice;
}
