#include <stdlib.h>
#include "queue.h"
#include "list.h"
#include "item.h"

struct queue{
  List elements;
};

Queue newQueue(){
  Queue q = malloc(sizeof(struct queue));
  q->elements = newList();

  return q;
}

int isEmptyQueue(Queue q){
  return isEmpty(q->elements);
}

int enqueue(Queue q, Item e){
  return addListTail(q->elements,e);
}

Item dequeue(Queue q){
  return removeHead(q->elements);
}

void printQueue(Queue q){
  printList(q->elements);
}

void reverseQueueRIC(Queue q){
  if(isEmptyQueue(q))
    return;

  Item a = dequeue(q);
  reverseQueueRIC(q);
  enqueue(q,a);
}
