#include "song.h"
#include "item.h"

typedef struct playlist *Playlist;

Playlist createPlaylist(char *name);
void addSong(Playlist,Song);
void removeSong(Playlist,Item);
void sortPlaylist(Playlist);
void printPlaylist(Playlist);
