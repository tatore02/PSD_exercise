#include <stdlib.h>
#include <stdio.h>
#include "stackToQueue.h"
#include "item.h"
#include "stack.h"

struct queue{
  Stack enq;
  Stack deq;
};

Queue newQueue(){
  Queue q = malloc(sizeof(struct queue));
  q->enq = newStack();
  q->deq = newStack();
  return q;
}

int isEmptyQueue(Queue q){
  if(isEmptyStack(q->enq) && isEmptyStack(q->deq))
    return 1;
  return 0;
}

void enqueue(Queue q,Item a){
  push(q->enq,a);
}

void dequeue(Queue q){
  if(isEmptyQueue(q)){
    puts("Coda vuota");
    return;
  }
  while(!isEmptyStack(q->enq)){
    Item a = top(q->enq);
    push(q->deq,a);
    pop(q->enq);
  }
  pop(q->deq);
}

void printQueue(Queue q){
  if(isEmptyStack(q->enq))
    printStack(q->deq);
  else{
    while(!isEmptyStack(q->enq)){
      Item a = top(q->enq);
      push(q->deq,a);
      pop(q->enq);
    }
    printStack(q->deq);
  }
}
