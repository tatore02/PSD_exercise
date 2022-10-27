#include "song.h"

typedef struct playlist *Playlist;

Playlist createPlaylist();
void addSong(Playlist,Item);
void removeSong(Playlist,Item);
void sortPlaylist(Playlist);
void printPlaylist(Playlist);
