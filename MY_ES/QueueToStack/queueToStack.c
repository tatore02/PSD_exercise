#include "queueToStack.h"
#include <stdlib.h>
#include <stdio.h>

struct stack{
  Queue q1;
  Queue q2;
};

Stack newStack(){
  Stack s = malloc(sizeof(struct stack));
  s->q1 = newQueue();
  s->q2 = newQueue();

  return s;
}

int isEmptyStack(Stack s){
  if(isEmptyQueue(s->q1) && isEmptyQueue(s->q2))
    return 1;
  else return 0;
}


void push(Stack s,Item a){
  Item tmp;

  if(isEmptyQueue(s->q1) && isEmptyQueue(s->q2))
    enqueue(s->q1,a);
  else if(isEmptyQueue(s->q1)){
    enqueue(s->q1,a);
    while(!isEmptyQueue(s->q2)){
      tmp = dequeue(s->q2);
      enqueue(s->q2,tmp);
    }
  }
  else if(isEmptyQueue(s->q2)){
    enqueue(s->q2,a);
    while(!isEmptyQueue(s->q1)){
      tmp = dequeue(s->q1);
      enqueue(s->q2,tmp);
    }
  }
}

void pop(Stack s){
  if(!isEmptyQueue(s->q1))
    dequeue(s->q1);
  else if(!isEmptyQueue(s->q2))
    dequeue(s->q2);
  else
    printf("Stack vuoto\n");
}

Item top(Stack s){
  Item vett[10];
  Item tmp;
  int i=0;

  if(!isEmptyQueue(s->q1)){
    while(!isEmptyQueue(s->q1)){
      vett[i] = dequeue(s->q1);
      i++;
    }
    tmp = vett[0];
    for(int j=0; j<i; j++)
      enqueue(s->q1,vett[j]);
  }
  else if(!isEmptyQueue(s->q2)){
    while(!isEmptyQueue(s->q2)){
      vett[i] = dequeue(s->q2);
      i++;
    }
    tmp = vett[0];
    for(int j=0; j<i; j++)
      enqueue(s->q2,vett[j]);
  }

  return tmp;
}

void printStack(Stack s){
  if(!isEmptyQueue(s->q1))
    printQueue(s->q1);
  else if(!isEmptyQueue(s->q2))
    printQueue(s->q2);
  else
    printf("Stack vuoto\n");
}
