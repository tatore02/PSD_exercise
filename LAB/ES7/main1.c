#include <stdio.h>
#include "item.h"
#include "list.h"

int main(){
  List l = newList();
  Item item;

  puts("Inserire elementi in lista:");
  for(int i=0;i<5;i++){
    item = inputItem();
    addHead(l,item);
  }

  puts("Lista:");
  printListRec(l);

}
