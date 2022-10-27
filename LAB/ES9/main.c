#include <stdio.h>
#include "btree.h"
#include "item.h"

int main(){
  BTree b1,b2,b3,b4,b5,b6,b7;

  int x[]={1,2,3,4,5,6,7};


  b7 = buildTree(NULL,NULL,&x[6]);
  b6 = buildTree(NULL,NULL,&x[5]);
  b5 = buildTree(NULL,NULL,&x[4]);
  b4 = buildTree(NULL,NULL,&x[3]);
  b3 = buildTree(b6,b7,&x[2]);
  b2 = buildTree(b4,b5,&x[1]);
  b1 = buildTree(b2,b3,&x[0]);

  printf("Stampa per livelli:\n");
  printLiv(b1);
  printf("\nPreorder:\n");
  preOrder(b1);
  printf("\nPreorder iterativa:\n");
  preOrderIter(b1);

}
