#include "item.h"

typedef struct libro *Libro;

Libro createLibro(char *,char *,char *);
char *getTitolo(Libro);
char *getAutore(Libro);
int getCodice(Libro);
