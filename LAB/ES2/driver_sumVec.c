#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
#define N 5

int main(){
  FILE *in=fopen("input.txt","r");
  FILE *ou=fopen("output.txt","a");
  if(in==NULL || ou==NULL){
    puts("File non aperti correttamente");
    exit(1);
  }
  int x[N];
  int y[N];
  int z[N]; //risultato

  inputFile(in,x,N);
  inputFile(in,y,N);
  somma_array(x,y,z,N);
  outputFile(ou,z,N);
  fclose(in);
  fclose(ou);
}
