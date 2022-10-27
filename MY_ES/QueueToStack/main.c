#include "queueToStack.h"

int main(){
  Stack s = newStack();

  Item a;
  for(int i=0;i<3;i++){
    a = inputItem();
    push(s,a);
    printStack(s);

  }

  //printStack(s);
}
