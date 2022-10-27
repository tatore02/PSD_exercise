#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funzioni.h"

void inputFile(FILE *fp,int v[],int n){
  for(int i=0;i<n;i++)
    fscanf(fp,"%d",&v[i]);
}

void output(int v[],int n){
  for(int i=0;i<n;i++)
    printf("%d ",v[i]);
  puts("");
}

void outputFile(FILE *fp,int v[],int n){
  for(int i=0;i<n;i++)
    fprintf(fp,"%d ",v[i]);
  fprintf(fp,"\n");
}

void test(FILE *out,FILE *ora){
  FILE *fp_test=fopen("test.txt","w");
  char line1[20];
  char line2[20];
  char *linePtr1=line1;
  char *linePtr2=line2;
  int i=1;
  while(fgets(line1,20,out)!=NULL && fgets(line2,20,ora)!=NULL){
    //fprintf(fp_test,"%s",line1); //debug
    //fprintf(fp_test,"%s",line2); //debug
    //printf("line 1: %s",line1);
    //printf("line 2: %s",line2);
    if(strcmp(line1,line2)==0)
      fprintf(fp_test,"TEST %d : T\n",i);
    else fprintf(fp_test,"TEST %d : F\n",i);
    i++;
    //if(linePtr1==NULL || linePtr2==NULL) break;
  }
  fclose(fp_test);
}

int somma(int a[],int n){
  int s=0;
  for(int i=0;i<n;i++)
    s+=a[i];
return s;
}

void somma_array(int a[],int b[],int s[],int n){
  for(int i=0;i<n;i++)
    s[i]=a[i]+b[i];
}

int scalare(int a[],int b[],int n){
  int prod=0;
  for(int i=0;i<n;i++)
    prod+=a[i]*b[i];
  return prod;
}
