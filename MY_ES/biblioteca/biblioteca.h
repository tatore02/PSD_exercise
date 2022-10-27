#include "libro.h"
#include "item.h"
#include "list.h" 

typedef struct biblioteca *Biblioteca;

Biblioteca createBiblioteca(char *);
void addBook(Biblioteca,Libro);
Item searchBook(Biblioteca);
Item removeBook(Biblioteca,Item);
void sortBiblioteca(Biblioteca);
void printBiblioteca(Biblioteca);

//gestione prestiti
void darePrest(Biblioteca);
Item searchBookPrest(Biblioteca );
Item removeBookPrest(Biblioteca,Item);
void ricevPres(Biblioteca );
void sortListPrest(Biblioteca );
void printListPrest(Biblioteca );

List searchBook2(Biblioteca );
void printListForAuthor(Biblioteca);
