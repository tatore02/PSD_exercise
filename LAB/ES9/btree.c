#include <stdlib.h>
#include <stdio.h>
#include "btree.h"
#include "item.h"
#include "queue.h"
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
  return a>b ? a : b;
}

int height(BTree b){
  if(isEmptyTree(b))
    return 0;
  else if(getLeft(b)==NULL && getRight(b)==NULL)
    return 0;
  else
    return 1 + max(height(b->left),height(b->right));
}

int nNodi(BTree b){
  if(isEmptyTree(b))
    return 0;
  else
    return 1 + nNodi(b->left) + nNodi(b->right);
}

int nNodi2(BTree b){
  int count=1;
  if(isEmptyTree(b))
    return 0;
  else{
    if(!isEmptyTree(b->left))
      count+= nNodi2(b->left);
    if(!isEmptyTree(b->right))
      count+= nNodi2(b->right);
  }
  return count;
}

void printLiv(BTree b){
  Queue q = newQueue();
  enqueue(q,b);

  while(!isEmptyQueue(q)){
    BTree radice;
    radice = dequeue(q);
    outputItem(radice->item);
    if(!isEmptyTree(getLeft(radice)))
      enqueue(q,getLeft(radice));
    if(!isEmptyTree(getRight(radice)))
      enqueue(q,getRight(radice));
    }
}


void preOrderIter(BTree b){
  BTree node;
  Stack s = newStack();
  push(s,b);

  while(!isEmptyStack(s)){
    node = top(s);
    outputItem(node->item);
    pop(s);
    if(getRight(node))
      push(s,node->right);
    if(getLeft(node))
      push(s,node->left);
  }
}

void postOrderIter(BTree b){
  BTree last = NULL;
  BTree curr = b;
  Stack s = newStack();
  while(!isEmptyStack(s) || curr){
    if(curr){
      push(s,curr);
      curr = getLeft(curr);
    }
    else{
      curr = top(s);
      if(getRight(curr) && last!=getRight(curr)){
        curr = getRight(curr);
      }
      else{
        last = curr;
        outputItem(curr->item);
        pop(s);
        curr = NULL;
      }
    }
  }
}

void inOrderIter(BTree b){
  Stack s = newStack();
  BTree curr = b;

  while(!isEmptyStack(s) || curr){
    if(curr && curr->item != top(s)){
      push(s,curr);
      curr = getLeft(curr);
    }
    else{
      curr = top(s);
      outputItem(curr->item);
      pop(s);
      curr = getRight(curr);
    }
  }
}
