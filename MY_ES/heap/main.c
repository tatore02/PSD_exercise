#include "heap.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

//realizzazione HEAP
int main(){

  int *array;
  array = malloc(1 * sizeof(int));
  array[0] = 15;
  int size = 1;

  int buffer;
  for(int i=0;i<5;i++){
    scanf("%d",&buffer);
    insertHeap(array,&size,buffer);
  }
  outputArray(array,size);

}
