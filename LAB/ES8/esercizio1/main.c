#include <stdio.h>
#include "item.h"
#include "array.h"
#define N 5

int main(){

  Item x[N];
  puts("Inserire valori:");
  for(int i=0;i<N;i++)
    x[i] = inputItem();

  sSortItemRIC(x,N);
  puts("Elementi ordinati: ");

  for(int i=0;i<N;i++)
    outputItem(x[i]);

}
