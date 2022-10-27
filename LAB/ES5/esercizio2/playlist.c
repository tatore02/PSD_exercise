#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "playlist.h"
#include "list.h"

struct playlist{
  char *name;
  List songs;
};

Playlist createPlaylist(char *name){
  Playlist p = malloc(sizeof(struct playlist));
  p->name = name;
  p->songs = newList();
  return p;
}

void addSong(Playlist p,Song s){
  addHead(p->songs,s);
}

void removeSong(Playlist p,Item item){
  Song s = item;
  removeListItem(p->songs,s);
}

void sortPlaylist(Playlist p){
  sortList(p->songs);
}

void printPlaylist(Playlist p){
  printf("Playlist %s:\n",p->name);
  printList(p->songs);
}
