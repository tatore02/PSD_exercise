#include <stdio.h>
#include "queue.h"

int main(){

  Queue q = newQueue();
  Item item;

  puts("Inserire valori:");
  for(int i=0;i<5;i++){
      item = inputItem();
      enqueue(q,item);
  }
  reverseQueueRIC(q);
  puts("Coda rovesciata:");
  printQueue(q);
}
