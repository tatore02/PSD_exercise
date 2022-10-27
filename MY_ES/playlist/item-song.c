#include "item.h"
#include "song.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Item inputItem(){
  char titolo[10];
  char autore[10];

  printf("Inserire titolo: ");
  scanf("%s",titolo);

  printf("Inserire autore: ");
  scanf("%s",autore);

  return createSong(titolo,autore);
}

void outputItem(Item a){
  Song s = a;
  printf("Titolo: %s\nAutore: %s\n",getTitolo(s),getAutore(s));
}

int compareItem(Item a1,Item a2){
  Song s1 = a1;
  Song s2 = s2;

  char *str1 = getAutore(s1);
  char *str2 = getAutore(s2);

  return strcmp(str1,str2);
}

void swapItem(Item *a1,Item *a2){
  Item tmp = *a1;
  *a1 = *a2;
  *a2 = tmp;
}
