#include <stdio.h>
#include "item.h"
#include "list.h"
#include "song.h"
#include "playlist.h"

int main(){

  FILE *fp = fopen("text.txt","r");

  char nome[]="Rock";
  Playlist p = createPlaylist(nome);
  //inserimento
  Item item;
  for(int i=0;i<4;i++){
    item = inputItem(fp);
    addSong(p,item);
  }
  printPlaylist(p);
  fclose(fp);
}
