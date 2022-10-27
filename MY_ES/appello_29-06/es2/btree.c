#include <stdlib.h>
#include <stdio.h>
#include "btree.h"
#include "item.h"
#include "queue.h"
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


int max(int a,int b){
  if(a>b)
    return a;
  else return b;
}

int height(BTree b){
  if(isEmptyTree(b))
    return 0;

  if(getLeft(b)!=NULL || getRight(b)!=NULL)
    return 1 + max(height(b->left), height(b->right));
  else return 0;
}

int* sumByLevel(BTree b){
  Queue q = newQueue();
  int array[height(b)];
  BTree node;
  enqueue(q,b);
  while(!isEmptyTree(b)){
    while(!isEmptyTree(b)){
      node = ItemToInt(dequeue(q));
    

      if(getLeft(node))
        enqueue(q,node->left);
      if(getRight(b))
        enqueue(q,node->right);

  }
}


void printTree(BTree b){
  printTree2(b,0);
}

void printTree2(BTree b,int space){
  if(isEmptyTree(b))
    return;

  space += COUNT;
  printTree2(b->right,space);

  printf("\n");
  for(int i=COUNT;i < space;i++)
    printf(" ");
  outputItem(b->item);

  printTree2(b->left,space);
}
