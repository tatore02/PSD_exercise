#include <stdio.h>
#include "btree.h"
#include "item.h"
#define N 7
/*
Si devono scrivere due funzioni ricorsive:
  int sommaNodi(tree t);
  int cercaMax(tree t);
*/

int main(){
  BTree b1,b2,b3,b4,b5;

  int x[]={7,3,9,1,5};


  b5 = buildTree(NULL,NULL,&x[4]);
  b4 = buildTree(NULL,NULL,&x[3]);
  b3 = buildTree(NULL,NULL,&x[2]);
  b2 = buildTree(b4,b5,&x[1]);
  b1 = buildTree(b2,b3,&x[0]);


  int levels = height(b1) +1;
  int sum[levels];

  printTree(b1);

  sumByLevel(b1,0,sum);
  printf("\n\nSomma per livelli:\n");
  for(int i=0;i<levels;i++)
    printf("%d\n",sum[i]);
}
