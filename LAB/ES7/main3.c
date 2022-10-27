#include <stdio.h>
#include "item.h"
#include "list.h"

int main(){
  List l = newList();
  Item item;
  int n=0;

  puts("Inserire elementi in lista:");
  for(int i=0;i<5;i++){
    item = inputItem();
    addHead(l,item);
  }

  printf("Inserire elemento da cercare: ");
  item = inputItem();
  n=countItemListRec(l,item);
  if(n!=0)
    printf("Elemento trovato in lista %d volte\n",n);
  else
    printf("Elemento NON trovato\n");
}
