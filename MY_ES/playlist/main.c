#include "playlist.h"

int main(){
  Playlist p = createPlaylist();

  Item a;

  for(int i=0;i<3;i++){
    a = inputItem();
    addSong(p,a);
  }

  printPlaylist(p);
}
