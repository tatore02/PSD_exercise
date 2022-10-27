#include <stdio.h>
#include "item.h"
#include "list.h"

#define DIM 8

int main(){
  int i,pos;
  Item item;
  Item trovato;
  List l=newList();
  List new;

    for(i=0; i<5; i++){
      item = inputItem();
      addListTail(l, item);
    }
    sortList(l);
    puts("\nLISTA ORDINATA:");
    printList(l);
  }
