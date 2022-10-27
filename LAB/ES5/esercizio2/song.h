typedef struct song *Song;

Song createSong(char *title, char *artist, char* duration);
char *getTitolo(Song);
char *getArtista(Song);
char *getDurata(Song);
