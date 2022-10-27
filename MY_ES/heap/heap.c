#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "item.h"

#define COUNT 5

struct node{
  Item item;
  struct node *left;
  struct node *right;
};


void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void outputArray(int *array,int size){
  for(int i=0;i<size-1;i++)
    printf("%d ",array[i]);
}

void insertHeap(int* array,int *size,int a){
  *size += 1;
  array = (int*) realloc(array,(*size) * sizeof(int));

  array[*(size) - 1] = a;

  int index_padre;
  int index = *size - 1;
  if(index != 0){
    do{
      if((index % 2) != 0)  //figlio di sinistra
        index_padre = index / 2;
      else index_padre = (index / 2) - 1; //figlio di destra

      if(array[index] > array[index_padre])
        swap(&array[index],&array[index_padre]);
    }while(index_padre != 0);
  }
}
