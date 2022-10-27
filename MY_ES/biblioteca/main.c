#include <stdio.h>
#include "item.h"
#include "list.h"
#include "libro.h"
#include "biblioteca.h"

int main(){
  FILE *fp = fopen("text.txt","r");

  Item b;
  char nome[]="nocera";
  Biblioteca k = createBiblioteca(nome);
  for(int i=0;i<5;i++){
    b = inputItem(fp);
    addBook(k,b);
  }

  printListForAuthor(k);

  fclose(fp);
}
