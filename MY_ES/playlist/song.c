#include "song.h"
#include <stdlib.h>

struct song{
  char* titolo;
  char* autore;
};

Song createSong(char* titolo,char* autore){
  Song s = malloc(sizeof(struct song));
  s->titolo = titolo;
  s->autore = autore;

  return s;
}

char* getTitolo(Song s){
  return s->titolo;
}

char* getAutore(Song s){
  return s->autore;
}
