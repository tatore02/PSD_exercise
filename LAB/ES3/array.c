#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "array.h"

int *inputArrayDyn(int *size,char *line){
  int i=0,n=0;
  *size=contaSpazi(line)+1;
  int *arr=malloc((*size)*sizeof(int));
  while(sscanf(line,"%d%n",&arr[i],&n)==1){
    line+=n;
    i++;
  }
  return arr;
}

int *concatenaVet(int *a,int n,int *b,int m,int *size){
  *size=n+m;
  int *vet=malloc((*size)*sizeof(int));
  int i,j=0;
  for(i=0;i<n;i++)
    vet[i]=a[i];
  for(;i<*size;i++){
    vet[i]=b[j];
    j++;
  }
    return vet;
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

int minimo(int x[],int n){
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
  for(i=0;i<n-1;i++){
    int min = minimo(&x[i],n-i)+i;
    swap(&x[i],&x[min]);
  }
}

void insertSortedSort(int x[],int *n, int value){
  int i;
  for(i=*n;i>0;i--){
    if(value<x[i-1])
      x[i]=x[i-1];
    else
      break;
  }
  x[i]=value;
  *n+=1;
  }

void insertionSort(int x[],int n){
  int i;
  for(i=1;i<n;)
    insertSortedSort(x,&i,x[i]);
  }

void bubbleSort(int x[],int n){
  int i,j;
  for(i=1;i<n;i++)
    for(j=0;j<n-1;j++)
      if(x[j]>x[j+1])
        swap(&x[j],&x[j+1]);

}

int bubbleSort2(int x[],int n){
    int i,j,ordinato=0,count=0;
    for(i=1;i<n && !ordinato;i++){
      ordinato=1;
      for(j=0;j<n-1;j++){
        count++;
        if(x[j]>x[j+1]){
          swap(&x[j],&x[j+1]);
          ordinato=0;
        }
      }
    }
    return count;
  }

int ricercaBin(int x[], int n,int el){
  int begin=0,center,end=n-1;
  while(begin<=end){
    center=(begin+end)/2;
    if(el==x[center]) return center;
    else if(el<x[center]) end=center-1;
    else begin=center+1;  //if(el>x[center])
    }
  return -1;
}
