#include <stdlib.h>
#include <stdio.h>
#include "biblioteca.h"

struct biblioteca{
  char *name;
  List books;
  List prest;
};

Biblioteca createBiblioteca(char *nome){
  Biblioteca k = malloc(sizeof(struct biblioteca));
  k->name = nome;
  k->books = newList();
  k->prest = newList();
  return k;
}

void addBook(Biblioteca k,Libro b){
  addHead(k->books,b);
}

Item searchBook(Biblioteca k){
  int cod;
  printf("Inserire codice da ricercare: ");
  scanf("%d",&cod);

  int n=0;
  return searchList(k->books,cod,&n);
}

Item removeBook(Biblioteca k,Item item){
  Libro b = item;
  return removeListItem(k->books,b);
}

void sortBiblioteca(Biblioteca k){
  sortList(k->books);
}

void printBiblioteca(Biblioteca k){
  printf("Catalogo libro:\n");
  printf("Titolo:\tAutore:\tCodice:\n");
  printList(k->books);
}

void darePrest(Biblioteca k){
  Item a = searchBook(k);
  removeBook(k,a);
  addHead(k->prest,a);
}

Item searchBookPrest(Biblioteca k){
  int cod;
  printf("Inserire codice da ricercare: ");
  scanf("%d",&cod);

  int n=0;
  return searchList(k->prest,cod,&n);
}

Item removeBookPrest(Biblioteca k,Item item){
  Libro b = item;
  return removeListItem(k->prest,b);
}

void ricevPres(Biblioteca k){
  Item a = searchBookPrest(k);
  removeBookPrest(k,a);
  addHead(k->books,a);
}

void sortListPrest(Biblioteca k){
  sortList(k->prest);
}

void printListPrest(Biblioteca k){
  printf("Lista libri dati in prestito:\n");
  printf("Titolo:\tAutore:\tCodice:\n");
  printList(k->prest);
}

List searchBook2(Biblioteca k){
  printf("Inserire autore da cercare: ");
  char str[10];
  scanf("%s",str);

  int n=0;
  return searchList2(k->books,str,&n);
}

void printListForAuthor(Biblioteca k){
  List l = newList();
  l = searchBook2(k);

  sortList2(l);
  printf("Titolo:\tAutore:\tCodice:\n");
  printList(l);
}
