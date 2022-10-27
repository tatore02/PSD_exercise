/*
Si scriva una procedura che, data una coda L di interi
genera un’altra coda L’ in modo che tutti gli elementi dispari precedano,
nello stesso ordine che avevano inizialmente in L,
tutti gli elementi pari ... per esempio, se L = 3, 7, 8, 1, 4,
allora si ottiene L’ = 3, 7,1,8,4)
*/

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

  reverseQueue2(q,"ciao");
  printQueue(q);
}
