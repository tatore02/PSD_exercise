#include "array.h"
#include <stdio.h>

int minimo(int x[],int n){  //confronta l'elemento [1] del vettore all'elemento [0]
  int min=0;
  int i=0;
  for(i=1;i<n;i++){
    if(x[i]<x[min])
      min=i;
  }
  return min;
}

void sSort(int x[],int n){
  int i;
  for(i=0;i<n;i++){
    int min = minimo(x+i,n-i);
    swap(&x[i],&x[min]);
  }
}

void sSortRIC(int x[],int size){
  if(size==1)
    return;

  int min = minimo(x+1,size-1)+1;
  if(x[min] < x[0])
    swap(&x[0],&x[min]);
  sSortRIC(x+1,size-1);
}

int minimoItem(Item x[],int n){
  int min=0;
  int i=0;
  for(i=1;i<n;i++){
    if(compareItem(x[i],x[min]) < 0)
      min=i;
  }
  return min;
}

void sSortItemRIC(Item x[],int size){
  if(size==1)
    return;

  int min = minimoItem(x+1,size-1)+1;
  if(compareItem(x[min],x[0]) < 0)
    swapItem(&x[min],&x[0]);
  sSortItemRIC(x+1,size-1);

}

void inputArray(int x[],int n){
  int i=0;
  for(i=0;i<n;i++)
    scanf("%d", &x[i]);
}

void outputArray(int x[],int n){
  int i=0;
  for(i=0;i<n;i++)
    printf("%d ", x[i]);

}
