#include "stackToQueue.h"
#include "stack.h"
#include <stdlib.h>

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
  return (isEmptyStack(q->enq) && isEmptyStack(q->deq));
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
    pop(q->enq);
    push(q->deq,a);
  }
  pop(q->deq);
}

void printQueue(Queue q){
  if(!isEmptyStack(q->enq)){
    while(!isEmptyStack(q->enq)){
      Item a = top(q->enq);
      pop(q->enq);
      push(q->deq,a);
    }
    printStack(q->deq);
  }
  else
    printStack(q->deq);
}
