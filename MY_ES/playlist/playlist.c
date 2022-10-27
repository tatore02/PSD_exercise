#include "playlist.h"
#include "list.h"
#include <stdlib.h>

struct playlist{
  List songs;
};

Playlist createPlaylist(){
  Playlist p = malloc(sizeof(struct playlist));
  p->songs = newList();

  return p;
}

void addSong(Playlist p,Item a){
  addHead(p->songs,a);
}

void removeSong(Playlist p,Item a){
  removeListItem(p->songs,a);
}

void sortPlaylist(Playlist p){
  sortList(p->songs);
}

void printPlaylist(Playlist p){
  printList(p->songs);
}
