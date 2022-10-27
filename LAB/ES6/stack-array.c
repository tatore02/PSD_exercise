#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#define START_DIM 10
#define ADD_DIM 5

struct stack{
  Item *elements;
  int top;
  int dim;
};

Stack newStack(){
  Stack s = malloc(sizeof(struct stack));
  if(s == NULL){  //controllo malloc
    puts("Memoria non allocata");
    return NULL;
  }

  s->top = 0;

  s->elements = malloc(sizeof(Item) * START_DIM);
  if(s->elements == NULL){
    puts("Memoria degli elementi non allocata");
    return NULL;
  }

  s->dim = START_DIM;

  return s;
}

int isEmptyStack(Stack s){
  if(s->top == 0)
    return 1;
  else
    return 0;
}

int push(Stack s, Item item){
  Item *temp;
  if(s->top == s->dim){
    temp = realloc(s->elements, sizeof(Item) * ((s->dim) + ADD_DIM));
    if(temp == NULL){
      puts("Memoria non allocata");
      return 0;
    }
    else{
      s->elements = temp;
      s->dim += ADD_DIM;
      printf("Spazio esteso a %d\n", s->dim);
    }
  }
  s->elements [s->top]= item;
  (s->top)++;
  return 1;
}

int pop(Stack s){
  if(isEmptyStack(s))
    return 0;
  else{
    (s->top)--;
    return 1;
  }
}

Item top(Stack s){
  if(isEmptyStack(s))
    return 0;
  else
    return s->elements[(s->top)-1];
}

void printStack(Stack s){
  int i;
  for(i = (s->top)-1; i >= 0;i--)
    outputItem(s->elements[i]);
}
