#include <stdio.h>
#include "btree.h"

int main(){
  BTree b1,b2,b3,b4,b5;
  BTree b6,b7,b8,b9,b10;
  int vett[]={1,2,3,4,5};

  b5 = buildTree(NULL,NULL,&vett[4]);
  b4 = buildTree(NULL,NULL,&vett[3]);
  b3 = buildTree(NULL,NULL,&vett[2]);
  b2 = buildTree(b4,b5,&vett[1]);
  b1 = buildTree(b2,b3,&vett[0]);

  b10 = buildTree(NULL,NULL,&vett[4]);
  b9 = buildTree(NULL,NULL,&vett[3]);
  b8 = buildTree(NULL,NULL,&vett[2]);
  b7 = buildTree(b9,b10,&vett[1]);
  b6 = buildTree(b7,b8,&vett[0]);

  if(isEqual(b1,b6))
    printf("Sono uguali\n");
  else
    printf("NON sono uguali\n");
}
