/*
1) cancFinoItem() data una coda Q e un elemento el, vengono cancellati tutti gli elementi fino a el,
   se el non esiste viene cancellata tutta la coda.
2) fondiDaItem()

3) estraiMaxN() che data una coda Q e un intero n, estragga da Q, cancellandolo, il più grande fra i primi n elementi.
*/

#include <stdio.h>
#include "queue.h"

int main(){

  Queue q = newQueue();
  Item item;

  puts("Inserire valori q1:");
  for(int i=0;i<5;i++){
      item = inputItem();
      enqueue(q,item);
  }

  printf("Inserire item: ");
  item = inputItem();
  Item *vett;
  if(presenteRic(q,item,0,vett))
    printf("Elemento presente\n");
  else
    printf("Elemento NON presente\n");

  printQueue(q);
  puts("");
}
