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

  puts("Deallocazione lista...");
  destroyListRec(l);
  if(isEmpty(l))
    puts("Lista deallocata");
  else  puts("Lista non deallocata");
  }
