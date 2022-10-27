#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
#define N 5

int main(){
  FILE *in=fopen("input.txt","r");
  FILE *ou=fopen("output.txt","w");
  if(in==NULL || ou==NULL){
    puts("File non aperti correttamente");
    exit(1);
  }
  int x[N];
  inputFile(in,x,N);
  fprintf(ou,"%d\n",somma(x,N));
  fclose(in);
  fclose(ou);
}
