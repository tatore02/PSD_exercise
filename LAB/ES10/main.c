#include <stdio.h>
#include "btree.h"
#include "item.h"
#define N 7

int main(){
  BTree b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14;
  Item x[N];
  Item y; //per ricerca

  puts("Inserire elementi albero:");
  for(int i=0;i<N;i++)
    x[i] = inputItem();

  b7 = buildTree(NULL,NULL,x[6]);
  b6 = buildTree(NULL,NULL,x[5]);
  b5 = buildTree(NULL,NULL,x[4]);
  b4 = buildTree(NULL,NULL,x[3]);
  b3 = buildTree(b6,b7,x[2]);
  b2 = buildTree(b4,b5,x[1]);
  b1 = buildTree(b2,b3,x[0]);

  //es1
  /*
  printf("Inserire item da cercare: ");
  inputItem();
  if(search(b1,y))
    printf("Item trovato\n");
  else
    printf("Item non trovato\n");

  //es2
  printf("Massimo: ");
  outputItem(max(b1));
  puts("");
  */
  //es 3
  Item x1[N];
  puts("Inserire elementi secondo albero:");
  for(int i=0;i<N;i++)
    x1[i] = inputItem();

  b14 = buildTree(NULL,NULL,x1[6]);
  b13 = buildTree(NULL,NULL,x1[5]);
  b12 = buildTree(NULL,NULL,x1[4]);
  b11 = buildTree(NULL,NULL,x1[3]);
  b10 = buildTree(b13,b14,x1[2]);
  b9 = buildTree(b11,b12,x1[1]);
  b8 = buildTree(b9,b10,x1[0]);

  if(isEqualRic(b1,b8))
    printf("Alberi uguali\n");
  else
    printf("Alberi diversi\n");

}
