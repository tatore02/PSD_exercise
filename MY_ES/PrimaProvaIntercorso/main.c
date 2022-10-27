#include <stdio.h>
#include "list.h"

int main(){
  Item a;
  Item vect[2];
  List l = newList();
  puts("Inserire valori:");
  for(int i=0;i<3;i++){
    a = inputItem();
    addListTail(l,a);
  }

/*char *str = concatena(l);
  printf("\n%s\n",str);*/

  vect[0] = dueMinimo(l);
  vect[1] = dueMinimo(l)+1;
  printf("\nMinimo:");
  outputItem(vect[0]);
  printf("\nSecondo minimo:");
  outputItem(vect[1]);
}
