#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "item.h"

struct song{
  char *titolo;
  char *artista;
  char *durata;
};

Song createSong(char *titolo, char *artista, char* durata){
  Song s = malloc(sizeof(struct song));
  s->titolo = titolo;
  s->artista = artista;
  s->durata = durata;

  return s;
}

char *getTitolo(Song s){
  return s->titolo;
}

char *getArtista(Song s){
  return s->artista;
}

char *getDurata(Song s){
  return s->durata;
}
