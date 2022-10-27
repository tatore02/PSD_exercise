#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

void printStackReverse(Stack s){
  reverseList(s->elements);
  printList(s->elements);
}


char* reverseStr(char *x){
  Stack s = newStack();
  char *new = malloc(sizeof(char) * strlen(x));
  int i=0;
  Item c;

  for(;i < strlen(x);i++){
    c = &(x[i]);
    push(s,c);
  }

  i=0;
  for(;!isEmptyStack(s);i++){
    c = top(s);
    pop(s);
    //new[i] = *ItemToChar(c);  OSCURATO PERCHE' VIENE LINKATO item-int.c E NON item-string.c
  }
  return new;
}

void IntToBin(int a){
  Stack s = newStack();

  Item tmp;
  tmp = &a;
  int intero=1,resto;
  while(intero != 0){
    //intero = ItemToInt(tmp);
    resto = intero % 2;
    intero = intero/2;

    tmp = &resto;
    push(s,tmp);

    tmp = &intero;
  }

  puts("Stampa numero:");
  printStackReverse(s);
}


void reverseStackRic(Stack s){
  if(!isEmptyStack(s)){
    Item a = top(s);
    pop(s);
    reverseStackRic(s);
    push(s,a);
  }
}

Stack reverseStack(Stack s){
  Stack s2 = newStack();

  while(!isEmptyStack(s)){
    Item a = top(s);
    pop(s);
    push(s2,a);
  }
  return s2;
}

int isEqualStack(Stack s1,Stack s2){
  Item a1,a2;
  while(!isEmptyStack(s1) && !isEmptyStack(s2)){
    a1 = top(s1);
    a2 = top(s2);
    pop(s1);
    pop(s2);
    if(compareItem(a1,a2) != 0)
      return 0;
  }
  return 1;
}

int isEqualStackRic(Stack s1,Stack s2){
  if(isEmptyStack(s1) && isEmptyStack(s2))
    return 1;
  else if(compareChar(top(s1),top(s2)) != 0)
    return 0;
  else{
    pop(s1);
    pop(s2);
    return isEqualStackRic(s1,s2);
  }
}


int palindromaStringa(char* str){
  Stack s1 = newStack();
  Stack s2 = newStack();

  int len = strlen(str);

  while(*str != '\0'){
    Item tmp = str;
    push(s1,tmp);
    str++;
  }

  for(int i = len/2; i > 0; i--){
    Item tmp = top(s1);
    pop(s1);
    push(s2,tmp);
  }

  return isEqualStackRic(s1,s2);
}



float mediaStack(Stack s){
  int a=0;
  int i=0;
  while(!isEmptyStack(s)){
    //a += ItemToInt(top(s));
    pop(s);
    i++;
  }

  return (float)a/i;
}

void sortedInsert(Stack s,Item a){
  if(isEmptyStack(s) || compareItem(a,top(s)) > 0){
    push(s,a);
    return;
  }

  //se l'elemento da inserire è minore della testa dello stack
  Item tmp = top(s);
  pop(s);

  sortedInsert(s,a);
  push(s,tmp);
}

void sortStack(Stack s){
  if(isEmptyStack(s))
    return;

  Item tmp = top(s);
  pop(s);

  sortStack(s);
  sortedInsert(s,tmp);
}
