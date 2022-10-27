#include <stdio.h>
#include "array.h"

int main(){
  int n,m,size;
  char line1[100],line2[100];
  int *a,*b,*vet;

  printf("Inserisci primo vettore: ");
  //scanf("%[^\n]",line1);
  gets(line1);
  a=inputArrayDyn(&n,line1);
  puts("Primo vettore:");
  outputArray(a,n);

  printf("\nInserisci secondo vettore: ");
  //scanf("%[^\n]",line2);
  gets(line2);
  b=inputArrayDyn(&m,line2);
  puts("Secondo vettore:");
  outputArray(b,m);

  vet=concatenaVet(a,n,b,m,&size);
  puts("Vettore concatenato:");
  outputArray(vet,size);
}
