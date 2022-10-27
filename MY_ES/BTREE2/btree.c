#include <stdlib.h>
#include "btree.h"
#include "item.h"
#include "queue.h"

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

int larghezza(BTree b){
  Queue q = newQueue();
  enqueue(q,b);
  BTree node;
  BTree left,right;
  int count = 1;

  while(!isEmptyQueue(q)){
    node = dequeue(q);
    outputItem(node->item);
    left = getLeft(node);
    right = getRight(node);
    if(left != NULL)
      enqueue(q,node->left);
    if(right != NULL)
      enqueue(q,node->right);

    if(grandezzaQ(q) > count)
      count = grandezzaQ(q);
  }
  return count;
}

void invertSon(BTree b){
  BTree node = b;
  BTree left,right;
  Queue q = newQueue();
  enqueue(q,node);

  while(!isEmptyTree(node)){
    node = dequeue(q);
    left = getLeft(node);
    right = getRight(node);
    if(left != NULL)
      enqueue(q,left);
    if(right != NULL)
      enqueue(q,right);
    if(left != NULL && right != NULL)
      swapItem(&(left->item),&(right->item));
  }
}

int isFull(BTree b){
  Queue q = newQueue();
  int index = 1;
  int index2 = index;
  enqueue(q,b);
  BTree node;
  while(!isEmptyQueue(q)){
    node = dequeue(q);
    if(getLeft(node)){
      enqueue(q,node->left);
      index2++;
    }
    if(getRight(node)){
      enqueue(q,node->right);
      index2++;
    }
    if(index2 != (index+2))
      return 0;
    else
      index = index2;
  }
  return 1;
}

List printLeaf(BTree b){
  List l = newList();

  if(isEmptyTree(b))
    return l;
  else{
    if(getLeft(b) == NULL && getRight(b) == NULL){
      outputItem(b->item);
      addListTail(l,b->item);
    }
    printLeaf(b->left);
    printLeaf(b->right);
  }
}

List minDiItem(BTree b,Item a){
  List l = newList();

  minDiItem2(b,a,l);

  return l;
}

void minDiItem2(BTree b,Item a,List l){
  if(compareItem(a,b->item) > 0)
    addListTail(l,b->item);

  if(getLeft(b))
    minDiItem2(b->left,a,l);

  if(getRight(b))
    minDiItem2(b->right,a,l);
}
