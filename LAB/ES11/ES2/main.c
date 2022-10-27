#include <stdio.h>
#include "item.h"
#include "stackToQueue.h"

int main(){
  Queue q = newQueue();
  Item a;
  puts("Inserire valori:");
  for(int i=0;i<5;i++){
    a = inputItem();
    enqueue(q,a);
  }
  printf("Stampa coda: ");
  printQueue(q);
  printf("\nRimozione elemento... ");
  dequeue(q);
  printQueue(q);
  puts("");
}
