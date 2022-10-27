#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "list.h"

struct stack{
  List elements;
};

Stack newStack(){
  Stack s = malloc(sizeof(struct stack));
  s->elements = newList();
  return s;
}

int isEmptyStack(Stack s){
  return isEmpty(s->elements);
}

int push(Stack s, Item item){
  addHead(s->elements, item);
  return 1;
}

int pop(Stack s){
  Item item = removeHead(s->elements);
  if(item == NULL)
    return 0;
  else
    return 1;
}

Item top(Stack s){
  return getHead(s->elements);
}

void printStack(Stack s){
  printList(s->elements);
}

void reverseStack(Stack s){
  reverseList(s->elements);
}
