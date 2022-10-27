#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "stack.h"

struct node{
  Item item;
  struct node *left;
  struct node *right;
};

BTree newTree(){
  return NULL;
}

int isEmptyTree(BTree btree){
  if(btree == NULL)
    return 1;
  return 0;
}

BTree buildTree(BTree b1, BTree b2, Item item){
  BTree b = malloc(sizeof(struct node));
  b->item = item;
  b->left = b1;
  b->right = b2;
  return b;
}

Item getBTreeRoot(BTree b){
  if(isEmptyTree(b))
    return NULL;
  return b->item;
}

BTree getLeft(BTree b){
  if(isEmptyTree(b))
    return NULL;
  return b->left;
}

BTree getRight(BTree b){
  if(isEmptyTree(b))
    return NULL;
  return b->right;
}

void preOrder(BTree b){
  if(!isEmptyTree(b)){
    //outputItem(b->item);
    preOrder(b->left);
    preOrder(b->right);
  }
}

void postOrder(BTree b){
  if(!isEmptyTree(b)){
    postOrder(b->left);
    postOrder(b->right);
    outputItem(b->item);
  }
}

void inOrder(BTree b){
  if(!isEmptyTree(b)){
    inOrder(b->left);
    outputItem(b->item);
    inOrder(b->right);
  }
}

int search(BTree b, Item item){
  if(isEmptyTree(b))
    return -1;

  BTree left,right;
  BTree node;
  Stack s = newStack();
  push(s,b);
  while(!isEmptyStack(s)){
    node = top(s);
    if(compareItem(node->item,item) == 0)
      return 1;
    pop(s);
    if((right = getRight(node))!=NULL)
      push(s,right);
    if((left = getLeft(node))!=NULL)
      push(s,left);
  }
}

Item max(BTree b){
  if(isEmptyTree(b))
    return NULL;

  BTree left,right;
  BTree node;
  Item maximo;
  Stack s = newStack();
  push(s,b);
  maximo = b->item;
  while(!isEmptyStack(s)){
    node = top(s);
    if(compareItem(node->item,maximo) > 0)
      maximo = node->item;
    pop(s);
    if((right = getRight(node))!=NULL)
      push(s,right);
    if((left = getLeft(node))!=NULL)
      push(s,left);
  }
  return maximo;
}

int equalTree(BTree b1,BTree b2){
  int flag = 1;

  int i=0;
  Item array1[20];
  Item array2[20];
  Stack s = newStack();
  BTree left,right;
  BTree node;
  push(s,b1);
  while(!isEmptyStack(s)){
    node = top(s);
    array1[i] = node->item;
    //outputItem(array1[i]);
    i++;
    pop(s);
    if((right = getRight(node))!=NULL)
      push(s,right);
    if((left = getLeft(node))!=NULL)
      push(s,left);
  }
  i=0;
  push(s,b2);
  while(!isEmptyStack(s)){
    node = top(s);
    array2[i] = node->item;
    //outputItem(array2[i]);
    i++;
    pop(s);
    if((right = getRight(node))!=NULL)
      push(s,right);
    if((left = getLeft(node))!=NULL)
      push(s,left);
  }

  for(int j=0;j < i;j++){
    if(array1[j] != array2[j])
      flag = 0;
  }
  return flag;
}

int isEqualRic(BTree b1,BTree b2){
  if(isEmptyTree(b1) && isEmptyTree(b2))
    return 1;

  int flag=0;
  if(compareItem(b1->item,b2->item)==0)
    flag=1;

  return (flag) && isEqualRic(b1->left,b2->left) && isEqualRic(b1->right,b2->right);
}
