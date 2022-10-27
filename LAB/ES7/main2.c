#include <stdio.h>
#include "item.h"
#include "list.h"

int main(){
  List l = newList();
  Item item;
  int pos=0;

  puts("Inserire elementi in lista:");
  for(int i=0;i<5;i++){
    item = inputItem();
    addHead(l,item);
  }

  printf("Inserire elemento da cercare: ");
  item = inputItem();
  searchListRec(l,item,&pos);
  if(pos!=-1)
    printf("Elemento trovato in posizione %d\n",pos);
  else
    printf("Elemento NON trovato\n");

}
