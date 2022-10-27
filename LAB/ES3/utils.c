#include "utils.h"

void swap(int *a,int *b){
  int temp=0;
  temp=*a;
  *a = *b;
  *b=temp;
}

int contaSpazi(char *a){
  int count=0;
  for(int i=0;;i++){
    if(a[i]==32) count++;
    if(a[i]=='\0') break;
  }
  return count;
}
