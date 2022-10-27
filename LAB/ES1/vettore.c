//implementazione funzioni
#include <stdio.h>
#include "utils.h"

void inputArray(int x[], int n){
  printf("Inserire %d elementi nel vettore: \n", n);
  for(int i=0;i<n;i++)
    scanf("%d", &x[i]);
}

void outputArray(int x[], int n){
  puts("Elementi del vettore");
  for(int i=0;i<n;i++)
    printf("%d ",x[i]);
  puts("");
}

int ricerca(int x[], int n, int el){
  int pos=n;
  for(int i=0;i<n;i++){
    if(el==x[i])
      pos=i;
  }
  return pos;
}

int minimo(int x[], int n){
  int min=x[0];
    for(int i=1;i<n;i++)
      if(x[i]<min)
        min=i;
  return min;
}

int ordine(int x[], int n){
  int m=0,i;
  for(i=0;i<n;i++)
    if(x[i]<x[i+1]) m++;
    if(m==n)return 0;
    else return 1;
}

void scambia(int x[],int n){
  int i;
  for(i=0;i<n;i++)
    if(x[i]>x[i+1])
      swap(&x[i],&x[i+1]);
}

int eliminare(int x[], int *n, int el){
  int i;
  int tro=0;
	for(i=0;i<*n;i++)
		if(x[i]==el){
      tro=1;
      *n=*n-1;
			for(;i<*n;i++)
			x[i]=x[i+1];
		}
  return tro;
}

void aggiungere(int x[], int *n, int el){
  *n=*n+1;
  x[*n-1]=el;
}
