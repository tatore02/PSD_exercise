#include <stdlib.h>
#include <stdio.h>
#include "btree.h"
#include "item.h"
#define COUNT 5

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
    outputItem(b->item);
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

int searchInt(BTree b,Item a){
  if(isEmptyTree(b))
    return 0;

  if(compareItem(b->item,a) == 0)
    return 1;

  if(getLeft(b))
    return searchInt(b->left,a);
  if(getRight(b))
    return searchInt(b->right,a);
}

int max(int a,int b){
  if(a>b)
    return a;
  else return b;
}

int maxBtree(BTree b){
  if(isEmptyTree(b))
    return 0;

  int left = maxBtree(b->left);
  int right = maxBtree(b->right);
  int item = ItemToInt(b->item);

  if(left > item)
    item = left;
  if(right > item)
    item = right;

  return item;
}

int isEqual(BTree b1,BTree b2){
  if(isEmptyTree(b1) && isEmptyTree(b2))
    return 1;
  if(!isEmptyTree(b1) && !isEmptyTree(b2)){
    return !compareItem(b1->item,b2->item) && isEqual(b1->left,b2->left) && isEqual(b1->right,b2->right);
  }

  return 0;
}
