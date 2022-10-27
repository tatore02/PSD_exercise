#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
#define N 5

int main(){
  int x[N];
  int y[N];
  int z[N]; //per risultato

  FILE *fp_input=fopen("input.txt","r");
  FILE *fp_output=fopen("output.txt","w");

  if(fp_input==NULL || fp_output==NULL){
    puts("Errore apertura file");
    exit(1);
  }
  //somma
  inputFile(fp_input,x,N);
  fprintf(fp_output,"%d\n",somma(x,N));
  printf("La somma degli elementi del vettore: %d\n",somma(x,N));
  //somma vettori
  inputFile(fp_input,y,N);
  somma_array(x,y,z,N);
  outputFile(fp_output,z,N);
  puts("Il vettore somma:");
  output(z,N);
  //scalare
  fprintf(fp_output,"%d",scalare(x,y,N));
  printf("Scalare : %d\n",scalare(x,y,N));

  fclose(fp_input);
  fclose(fp_output);

  FILE *fp_oracle=fopen("oracle.txt","r");
  FILE *fp_out=fopen("output.txt","r");
  if(fp_oracle==NULL || fp_out==NULL){
    puts("Errore apertura file");
    exit(1);
  }
  
  test(fp_out,fp_oracle);

  fclose(fp_output);
  fclose(fp_oracle);
}
